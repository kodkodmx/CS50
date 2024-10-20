#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Global Variables Declarations
int n = 0;

//Functions Declarations
bool only_digits(string k);
char rotate(string text, int key);

//Main Function
int main(int argc, string argv[])
{


    //Checks if command line have the right format
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Call the function to check if the key is only digits
    if (only_digits(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Convert the Key from the command line to an integer
    int k = atoi(argv[1]);
    //printf("key: %i\n", k);

    //Ask the user for the original text
    string plaintext = get_string("plaintext:  ");
    //printf("plaintext:  %s\n", plaintext);


    //prints the ciphertext and Call the function that rotates the original text in to the ciphertext
    printf("ciphertext: ");
    for (int j = 0; j < strlen(plaintext); j++)
    {
        printf("%c", rotate(plaintext, k));
        n++;
    }
    printf("\n");
    return 0;
}

// Function that verify if the key is only digits
bool only_digits(string k)
{
    for (int i = 0; i < strlen(k); i++)
    {
        if (isdigit(k[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}



// Function that change the character in key positions
char rotate(string text, int key)
{
    char c = '\0';
    for (int i = 0 + n; i < strlen(text); i++)
    {
        if (isalpha(text[i]) == 0)
        {
            return text[i];
        }
        if (isupper(text[i]))
        {
            //if the characters are Upper
            return (text[i] - 'A' + key) % 26 + 'A';
        }
        else
        {
            //if the characters are Lower
            c = (text[i] - 'a' + key) % 26 + 'a';
            return c;
        }

    }

    return 0;
}





