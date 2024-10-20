# TODO
import cs50


def main():
    # Declare the digits variables
    d1 = 0
    d2 = 0
    d3 = 0
    d4 = 0
    d5 = 0
    d6 = 0
    d7 = 0
    d8 = 0
    d9 = 0
    d10 = 0
    d11 = 0
    d12 = 0
    d13 = 0
    d14 = 0
    d15 = 0
    d16 = 0

    # Ask for the credit card number in numbers only format
    number = cs50.get_int("Number: ")

    # Asign to each variable a value
    d16 = number % 10
    d15 = (number - d16) // 10 % 10
    d14 = (number - d15) // 100 % 10
    d13 = (number - d14) // 1000 % 10
    d12 = (number - d13) // 10000 % 10
    d11 = (number - d12) // 100000 % 10
    d10 = (number - d11) // 1000000 % 10
    d9 = (number - d10) // 10000000 % 10
    d8 = (number - d9) // 100000000 % 10
    d7 = (number - d8) // 1000000000 % 10
    d6 = (number - d7) // 10000000000 % 10
    d5 = (number - d6) // 100000000000 % 10
    d4 = (number - d5) // 1000000000000 % 10
    d3 = (number - d4) // 10000000000000 % 10
    d2 = (number - d3) // 100000000000000 % 10
    d1 = (number - d2) // 1000000000000000 % 10

    # Multiply the odds digits by 2
    d1b = d1 * 2
    d3b = d3 * 2
    d5b = d5 * 2
    d7b = d7 * 2
    d9b = d9 * 2
    d11b = d11 * 2
    d13b = d13 * 2
    d15b = d15 * 2

    # Verify if the result of the multiplication is more than 2 digit and in case it is sum the digits
    if (d1 > 4):
        d1b = d1b - 9

    if (d3 > 4):
        d3b = d3b - 9

    if (d5 > 4):
        d5b = d5b - 9

    if (d7 > 4):
        d7b = d7b - 9

    if (d9 > 4):
        d9b = d9b - 9

    if (d11 > 4):
        d11b = d11b - 9

    if (d13 > 4):
        d13b = d13b - 9

    if (d15 > 4):
        d15b = d15b - 9

    # Make 2 groups of digits
    odds = d1b + d3b + d5b + d7b + d9b + d11b + d13b + d15b
    pairs = d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16

    # Sums the 2 groups
    sum = odds + pairs

    # Verify if the number is valid and what type of credit cards is

    # Visa
    if (((d1 == 4) or (d4 == 4)) and ((number < 4999999999999999) or (number < 4999999999999)) and ((sum) % 10 == 0)):
        print("VISA")

    # Amex
    elif ((d2 == 3) and ((d3 == 4) or (d3 == 7)) and (number <= 379999999999999) and ((sum) % 10 == 0)):
        print("AMEX")

    # Mastercard
    elif ((number >= 5099999999999999) and (number <= 5600000000000000) and ((sum) % 10 == 0)):
        print("MASTERCARD")

    # Invalid number
    else:
        print("INVALID")
        

if __name__ == "__main__":
    main()