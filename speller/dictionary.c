// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include <strings.h>
#include "dictionary.h"

//universal variables
unsigned int words = 0;
unsigned int hash_index = 0;
unsigned int hash_index2 = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//maximum buckets possible 515399146 before segmentation fault
//3049  minimum buckets possible on word LENGTH in ASCII
//4880 maximum buckets possible on word LENGTH in ASCII
//515 maximum buckets possible ASCII - 'A' but is problematic

const unsigned int N = 4880;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char word[LENGTH + 1])
{
    // TODO call hash function again
    hash_index2 = hash(word);

    //create a temp variable call cursor to iterate thru the linked list
    node *cursor = table[hash_index2];

    //iterate thru the linked list
    while (cursor != 0)
    {
        //if found a match
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        //move to next node if is not a match
        cursor = cursor->next;
    }
    return false;

}
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int result = 0;
    // Summaries first 3 letteres
    for (int i = 0; i < 3; i++)
    {
        result += toupper(word[i]);
    }
    return result;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open file in read mode
    FILE *dict = fopen(dictionary, "r");
    //check is succed to opened
    if (dictionary != NULL)
    {
        //rescue the words using a char array and fscanf function
        char word[LENGTH + 1];
        while ((fscanf(dict, "%s", word)) != EOF)
        {
            //make and check a new node for each new word
            node *n = malloc(sizeof(node));
            if (n != 0)
            {
                //copy the word to the new node
                strcpy(n -> word, word);
            }
            //asigned a hash value to this particular word
            hash_index = hash(word);
            //points the new node to the first node on the linked list
            n -> next = table[hash_index];
            //points the hash table to new first node
            table[hash_index] = n;
            words++;
        }
        //close file
        fclose(dict);
        //inform succed
        return true;
    }
    //inform fail
    return false;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (words != 0)
    {
        return words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // create a cursor pointing the the firts node on the list then iterates thru the list with another node call liberator who frees the node and follows cursor to the next node
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *liberator = cursor;
            cursor = cursor -> next;
            free(liberator);
            // if cursor reach the last node returns true;
            if (cursor == NULL)
            {
                return true;
            }
        }

    }
    //in case fail
    return false;
}