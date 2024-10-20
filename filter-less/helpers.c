#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Int of the average
    int average = 0;

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width; j++)
        {
            //average of rgb values
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }

    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //ints for sepia
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width; j++)
        {
            //sepia Formula
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            //if values are out of boundaries
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;

            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtGreen = sepiaGreen;

            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;

        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width / 2; j++)
        {
            // creates a copy image
            temp = image[i][j];
            image[i][j] = image[i][width - (1 + j)];
            image[i][width - (1 + j)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //declare a temp struct
    RGBTRIPLE temp[height][width];

    //declare variables
    float averageRed = 0;
    float averageGreen = 0;
    float averageBlue = 0;
    float valid = 0;

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width ; j++)
        {
            //copies values in temp struct
            temp [i][j] = image[i][j];
        }
    }

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width ; j++)
        {
            // calculate valid sourranding pixels

            if ((i == 0) && ((j != 0) || (j != width - 1)))
            {
                averageRed = ((temp[i][j - 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed) +
                              (temp[i + 1][j - 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed));
                averageGreen = ((temp[i][j - 1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen) +
                                (temp[i + 1][j - 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen));
                averageBlue = ((temp[i][j - 1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue) +
                               (temp[i + 1][j - 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue));
                valid = 6;
            }

            if ((i == height - 1) && ((j != 0) || (j != width - 1)))
            {
                averageRed = ((temp[i][j - 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed) +
                              (temp[i - 1][j - 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed));
                averageGreen = ((temp[i][j - 1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen) +
                                (temp[i - 1][j - 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen));
                averageBlue = ((temp[i][j - 1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue) +
                               (temp[i - 1][j - 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue));
                valid = 6;
            }

            if ((j == 0) && ((i != 0) || (i != height - 1)))
            {
                averageRed = ((temp[i - 1][j].rgbtRed + temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed) +
                              (temp[i - 1][j + 1].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j + 1].rgbtRed));
                averageGreen = ((temp[i - 1][j].rgbtGreen + temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen) +
                                (temp[i - 1 ][j + 1].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen));
                averageBlue = ((temp[i - 1][j].rgbtBlue + temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue) +
                               (temp[i - 1][j + 1].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue));
                valid = 6;
            }

            if ((j == width - 1) && ((i != 0) || (i != height - 1)))
            {
                averageRed = ((temp[i - 1][j].rgbtRed + temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed) +
                              (temp[i - 1][j - 1].rgbtRed + temp[i][j - 1].rgbtRed + temp[i + 1][j - 1].rgbtRed));
                averageGreen = ((temp[i - 1][j].rgbtGreen + temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen) +
                                (temp[i - 1][j - 1].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen));
                averageBlue = ((temp[i - 1][j].rgbtBlue + temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue) +
                               (temp[i - 1][j - 1].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue));
                valid = 6;
            }


            if ((i == 0) && (j == 0))
            {
                averageRed = (temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed);
                averageGreen = (temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen);
                averageBlue = (temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue);
                valid = 4;
            }

            if ((i == height - 1) && (j == 0))
            {
                averageRed = (temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed);
                averageGreen = (temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen);
                averageBlue = (temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue);
                valid = 4;
            }

            if ((i == 0) && (j == width - 1))
            {
                averageRed = (temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j - 1].rgbtRed);
                averageGreen = (temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j - 1].rgbtGreen);
                averageBlue = (temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j - 1].rgbtBlue);
                valid = 4;
            }

            if ((i == height - 1) && (j == width - 1))
            {
                averageRed = (temp[i][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j - 1].rgbtRed);
                averageGreen = (temp[i][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j - 1].rgbtGreen);
                averageBlue = (temp[i][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j - 1].rgbtBlue);
                valid = 4;
            }

            if (((j != 0) && (j != width - 1)) && ((i != 0) && (i != height - 1)))
            {
                averageRed = ((temp[i - 1][j - 1].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed) +
                              (temp[i][j - 1].rgbtRed + temp[i][j].rgbtRed + temp[i][j + 1].rgbtRed) +
                              (temp[i + 1][j - 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i + 1][j + 1].rgbtRed));
                averageGreen = ((temp[i - 1][j - 1].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen) +
                                (temp[i][j - 1].rgbtGreen + temp[i][j].rgbtGreen + temp[i][j + 1].rgbtGreen) +
                                (temp[i + 1][j - 1].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i + 1][j + 1].rgbtGreen));
                averageBlue = ((temp[i - 1][j - 1].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue) +
                               (temp[i][j - 1].rgbtBlue + temp[i][j].rgbtBlue + temp[i][j + 1].rgbtBlue) +
                               (temp[i + 1][j - 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i + 1][j + 1].rgbtBlue));
                valid = 9;
            }

            //find aout the average
            averageRed = round(averageRed / valid);
            averageGreen = round(averageGreen / valid);
            averageBlue = round(averageBlue / valid);


            //copies back pixels amounts to image
            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;
        }
    }

    return;
}
