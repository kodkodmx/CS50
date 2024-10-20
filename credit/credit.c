#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare the digits variables
    long d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;

    //Ask for the credit card number in numbers only format
    long number = get_long("Number: ");

    //Asign to each variable a value
    d16 = number % 10;
    d15 = (number - d16) / 10 % 10;
    d14 = (number - d15) / 100 % 10;
    d13 = (number - d14) / 1000 % 10;
    d12 = (number - d13) / 10000 % 10;
    d11 = (number - d12) / 100000 % 10;
    d10 = (number - d11) / 1000000 % 10;
    d9 = (number - d10) / 10000000 % 10;
    d8 = (number - d9) / 100000000 % 10;
    d7 = (number - d8) / 1000000000 % 10;
    d6 = (number - d7) / 10000000000 % 10;
    d5 = (number - d6) / 100000000000 % 10;
    d4 = (number - d5) / 1000000000000 % 10;
    d3 = (number - d4) / 10000000000000 % 10;
    d2 = (number - d3) / 100000000000000 % 10;
    d1 = (number - d2) / 1000000000000000 % 10;

    // Multiply the odds digits by 2
    int d1b = d1 * 2;
    int d3b = d3 * 2;
    int d5b = d5 * 2;
    int d7b = d7 * 2;
    int d9b = d9 * 2;
    int d11b = d11 * 2;
    int d13b = d13 * 2;
    int d15b = d15 * 2;


    //Verify if the result of the multiplication is more than 2 digit and in case it is sum the digits
    if (d1 > 4)
    {
        d1b = d1b - 9;
    }

    if (d3 > 4)
    {
        d3b = d3b - 9;
    }

    if (d5 > 4)
    {
        d5b = d5b - 9;
    }

    if (d7 > 4)
    {
        d7b = d7b - 9;
    }

    if (d9 > 4)
    {
        d9b = d9b - 9;
    }

    if (d11 > 4)
    {
        d11b = d11b - 9;
    }

    if (d13 > 4)
    {
        d13b = d13b - 9;
    }

    if (d15 > 4)
    {
        d15b = d15b - 9;
    }

    // Make 2 groups of digits
    int odds = (d1b + d3b + d5b + d7b + d9b + d11b + d13b + d15b);
    int pairs = (d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16);

    //Sums the 2 groups
    int sum = odds + pairs;

    //verify if the number is valid and what type of credit cards is

    //visa
    if (((d1 == 4) || (d4 == 4)) && ((number < 4999999999999999) || (number < 4999999999999)) && ((sum) % 10 == 0))
    {
        printf("VISA\n");
    }

    //Amex
    else if ((d2 == 3) && ((d3 == 4) || (d3 == 7)) && (number <= 379999999999999) && ((sum) % 10 == 0))
    {
        printf("AMEX\n");
    }

    //Mastercard
    else if ((number >= 5099999999999999) && (number <= 5600000000000000) && ((sum) % 10 == 0))
    {
        printf("MASTERCARD\n");
    }

    //Invalid number
    else
    {
        printf("INVALID\n");
    }
}