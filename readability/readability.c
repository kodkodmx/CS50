#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Functions Declarations
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//Global Variables Declarations
float letters = 0;
float words = 1;
float sentences = 0;

//Main Function make the math and print the result
int main(void)
{
    //Ask for the original Text
    string text = get_string("Text: ");

    //Prints back the text
    //printf("%s\n ", text);

    //Call the functions
    count_letters(text);
    count_words(text);
    count_sentences(text);

    //Make the Math for the Coleman-Liau index with the formula index = 0.0588 * L - 0.296 * S - 15.8
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    //printf("%f L\n %f S\n", L, S);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //Number of letters, words and sentences
    //printf("%1ld letters\n %1ld words\n %1ld sentences\n", lroundf(letters), lroundf(words), lroundf(sentences));

    //Prints the results
    if (index > 16)
    {
        printf("Grade 16+\n");
    }

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    if ((index > 1) && (index < 16))
    {
        printf("Grade %ld\n", lroundf(index));
    }


}

//Function that count the letters
int count_letters(string text)
{
    for (int j = 0; j <= 25; j++)
    {
        for (int i = 0; i < strlen(text); i++)
        {
            if (text[i] == 65 + j || text[i] == 97 + j)
            {
                letters++;
            }

        }
    }

    return letters;

}

//Function that count the words
int count_words(string text)
{

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words++;
        }

    }

    return words;
}

//Function that count the sentenses
int count_sentences(string text)
{

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == 33) || (text[i] == 46) || (text[i] == 63))
        {
            sentences++;
        }

    }

    return sentences;
}