// C as Frontend Start//

// this is library section
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // all the variables required //
    char cur1[50];
    char cur2[50];
    char ans;
    int amt;
    int ret;
    char cmd[100];
    int Count = 1;

    // some of the currencies mentioned
    char *currencies[] = {"USD ", "EUR ", "JPY ", "GBP ", "CHF ",
                          "CAD ", "AUD ", "CNY ", "HKD ", "NZD ", "SEK ", "KRW ",
                          "SGD ", "NOK ", "MXN ", "INR ", "RUB ", "ZAR ", "TRY ", "BRL "};
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%s", currencies[i]);
    }
    printf("\n");

    // Main input and conversion starts here
    while (Count <= 5)
    {
        printf("Enter Currency_1: ");
        scanf("%s", cur1);
        printf("Enter Currency_2: ");
        scanf("%s", cur2);
        printf("Enter Amount: ");
        scanf("%d", &amt);
        printf("\n");
        printf("Currency_1= %s, Currency_2= %s, Amount= %d ", cur1, cur2, amt);

        ///////////////////////////////////////////////////////

        // Creating the CSV_file for writing
        FILE *fp = fopen("currency_inp.csv", "w");

        // Write the input to the file
        fprintf(fp, "%s,%s,%d\n", cur1, cur2, amt);
        printf("\n");
        // Close the file
        fclose(fp);

        //////////////////////////////////////

        printf("\n");

        ///////////////////////////////////////////////////////

        // connect c with python i.e trigger C to run Python file

        sprintf(cmd, "python CAL_python.py");
        ret = system(cmd);
        if (ret != 0)
        {
            printf("Error running Python script\n");
            return 1;
        }

        ///////////////////////////////////////////////////////

        // Read the CSV_file to get output back
        printf("\n");
        FILE *fp2;
        char filename[] = "currency_out.csv";
        float result;

        fp2 = fopen(filename, "r");
        if (fp2 == NULL)
        {
            printf("Could not open file %s", filename);
            return 1;
        }

        fscanf(fp2, "%f", &result);

        fclose(fp2);
        ////////////////////////////////////

        // asking user whether he wants to continue or not
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &ans);

        if (ans == 'Y' || ans == 'y')
        {
            Count++;
        }
        else if (ans == 'N' || ans == 'n')
        {
            Count = 10;
        }
    }

    printf("THANK you:)");
    return 0;
}
// C as Frontend ENDED//
