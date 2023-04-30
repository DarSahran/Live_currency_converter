
# Python as Backend Start#

# this is library section

import pandas as pd
import requests


# call api request
class CurrencyConverter:
    # API URL for real-time exchange rates
    url = 'https://api.exchangerate-api.com/v4/latest/'

    def __init__(self, from_currency, to_currency, amount):
        self.from_currency = from_currency
        self.to_currency = to_currency
        self.amount = amount

    def convert(self):
        # Construct API URL for the given currencies
        url = self.url + self.from_currency

        # Send HTTP GET request to API endpoint
        response = requests.get(url)

        # Extract JSON data from response
        data = response.json()

        # Get exchange rate for the given currency pair
        exchange_rate = data['rates'][self.to_currency]

        # Calculate converted amount
        converted_amount = exchange_rate * self.amount
        return converted_amount


# Read the currency file into a DataFrame
df_1 = pd.read_csv('currency_inp.csv', header=None,
                   names=['cur1', 'cur2', 'amt'])
df_str = df_1.to_string(index=False, header=False)  # converting into strings

# Print the DataFrame
elements = df_str.strip().split()
el1 = elements[0].upper()
el2 = elements[1].upper()
amn = elements[2]
amn_i = int(amn)

# /////test section//////
# print(el1,el2,amn_i)
# print(type(amn))
# print(type(amn_i))


# main conversion starts here

currencies = [

    (el1, el2, amn_i)
]

for from_currency, to_currency, amount in currencies:
    converter = CurrencyConverter(from_currency, to_currency, amount)
    result = converter.convert()
    print(f'{amount} {from_currency} is {result:.2f} {to_currency}')
    total_res = f'{amount} {from_currency} is {result:.2f} {to_currency}'

    # Creating output csv file for c to read as csv format
df_2 = pd.DataFrame({total_res})
df_2.to_csv('currency_out.csv', index=False, header=False)

# Python as Backend ENDED#
