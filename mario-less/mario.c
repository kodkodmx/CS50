#include <cs50.h>
#include <stdio.h>

void buildPyramid(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:");
    }

    while (height < 1 || height > 8);

// Call the function with height as his parameter
    buildPyramid(height);

}

// Declare the function buildPyramid
void buildPyramid(int height)
{
    // for rows
    for (int i = 0; i < height; i++)
    {

        // for spaces
        for (int j = 0; j < height - i - 1 ; j++)
        {

            // Print a space
            printf(" ");

        }

        //for colums
        for (int j = 0; j < i + 1 ; j++)
        {
            // Print a brick
            printf("#");
        }
        // Move to next row
        printf("\n");
    }
}