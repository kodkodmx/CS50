#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define block_size 512

//create a variable call BYTE of unsigned 8 bites
typedef uint8_t BYTE;

//File pointer for destination file
FILE *destination_file = NULL;

//File pointer for original file
FILE *original_file = NULL;

int main(int argc, char *argv[])
{
    //check if the user provide the right arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //check if is valid
    if(original_file == NULL)
    {
        printf("The provided file '%s' is invalid\n" , argv[1]);
        return 2;
    }

    //allocate memory
    char *filename = malloc(sizeof(uint8_t));

    //open the file on argv[1] for "r"ead
    original_file = fopen(argv[1], "r");

    //create an array of BYTE
    BYTE buffer[block_size];

    //declares a variable call counter to track the numbers of jpeg found
    int counter = 0;


    while (fread(buffer, 1, block_size, original_file))
    {
        //check if is a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //fills char *filename with the names
            sprintf(filename, "%03i.jpg", counter);

            //Open a new destination file to "w"rite on it
            destination_file = fopen(filename, "w");

            //increse by 1 the number of images found
            counter++;
        }

        if (destination_file != NULL)
        {
            fwrite(buffer, 1, block_size, destination_file);
        }

       }
        free(filename);
        fclose(destination_file);
        fclose(original_file);

        return 0;


}