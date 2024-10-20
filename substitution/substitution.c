#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Main Function that cypher a provided text with a provided key
int main(int argc, string argv[])
{
    //Variable Declarations
    string key = argv[1];
    string Ukey = key;

    // Verifies that one and only one key is provided in the command line
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Verifies that the key is 26 characters long
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Changue all Characters to UpperCase
    for (int i = 0; i < strlen(key); i++)
    {
        Ukey[i] = toupper(key[i]);
    }

    //Just to check the key ERASE IT
    //printf("Ukey  %s\n", Ukey);

    //Vefifies all characters in the key are letters
    for (int i = 0; i < strlen(Ukey); i++)
    {
        if (!isalpha(Ukey[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        //Vefifies all characters in the key are unique
        for (int j = 1 + i; j < strlen(Ukey); j++)
        {
            if (Ukey[i] == Ukey[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    //Ask for the text to use
    string plaintext = get_string("plaintext:  ");

    //Just to check the plaintext ERASE IT
    //printf("plaintext:  %s\n", plaintext);

    //Prints the frase "ciphertext: "
    printf("ciphertext: ");

    //Determine if is a letter and if is low or up character and print the substituted character
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 65;
            printf("%c", Ukey[index]);
        }
        if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 97;
            printf("%c", (Ukey[index]) + 32);
        }
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
    }
    //If everything was ok print a new line and exits the program
    printf("\n");
    return 0;
}