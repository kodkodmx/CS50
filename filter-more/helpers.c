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

            //find out the average
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    //declare a temp struct
    RGBTRIPLE temp[height][width];

    //declare variables
    float GxRed = 0;
    float GxGreen = 0;
    float GxBlue = 0;
    float GyRed = 0;
    float GyGreen = 0;
    float GyBlue = 0;

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width; j++)
        {
            //copies values in temp struct
            temp [i][j] = image[i][j];
        }
    }

    //loop for Columns
    for (int i = 0; i < height; i++)
    {
        //loop for Lines
        for (int j = 0; j < width; j++)
        {
            //First row pixel
            if ((i == 0) && ((j != 0) || (j != width - 1)))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (0)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (0)) +
                         (temp[i][j - 1].rgbtRed * (-2)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (2)) +
                         (temp[i + 1][j - 1].rgbtRed * (-1)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (0)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (0)) +
                           (temp[i][j - 1].rgbtGreen * (-2)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (2))) +
                          (temp[i + 1][j - 1].rgbtGreen * (-1)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (1));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (0)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (0)) +
                          (temp[i][j - 1].rgbtBlue * (-2)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (2)) +
                          (temp[i + 1][j - 1].rgbtBlue * (-1)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (1)));

                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (0)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (0)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (1)) + (temp[i + 1][j].rgbtRed * (2)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (0)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (0)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (1)) + (temp[i + 1][j].rgbtGreen * (2)) + (temp[i + 1][j + 1].rgbtGreen * (1)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (0)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (0)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (1)) + (temp[i + 1][j].rgbtBlue * (2)) + (temp[i + 1][j + 1].rgbtBlue * (1)));
            }

            //Last row pixel
            if ((i == height - 1) && ((j != 0) || (j != width - 1)))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (1)) +
                         (temp[i][j - 1].rgbtRed * (-2)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (2)) +
                         (temp[i + 1][j - 1].rgbtRed * (0)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (0)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (1)) +
                           (temp[i][j - 1].rgbtGreen * (-2)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (2))) +
                          (temp[i + 1][j - 1].rgbtGreen * (0)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (0));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (1)) +
                          (temp[i][j - 1].rgbtBlue * (-2)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (2)) +
                          (temp[i + 1][j - 1].rgbtBlue * (0)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (0)));
                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (-2)) + (temp[i - 1][j + 1].rgbtRed * (-1)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (0)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (0)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (-2)) + (temp[i - 1][j + 1].rgbtGreen * (-1)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (0)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (0)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (-2)) + (temp[i - 1][j + 1].rgbtBlue * (-1)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (0)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (0)));
            }

            //Left row pixel
            if ((j == 0) && (i != 0) && (i != height - 1))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (0)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (1)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (2)) +
                         (temp[i + 1][j - 1].rgbtRed * (0)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (0)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (1)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (2)) +
                           (temp[i + 1][j - 1].rgbtGreen * (0)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (1)));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (0)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (1)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (2)) +
                          (temp[i + 1][j - 1].rgbtBlue * (0)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (1)));

                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (0)) + (temp[i - 1][j].rgbtRed * (-2)) + (temp[i - 1][j + 1].rgbtRed * (-1)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (0)) + (temp[i + 1][j].rgbtRed * (2)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (0)) + (temp[i - 1][j].rgbtGreen * (-2)) + (temp[i - 1][j + 1].rgbtGreen * (-1)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (0)) + (temp[i + 1][j].rgbtGreen * (2)) + (temp[i + 1][j + 1].rgbtGreen * (1)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (0)) + (temp[i - 1][j].rgbtBlue * (-2)) + (temp[i - 1][j + 1].rgbtBlue * (-1)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (0)) + (temp[i + 1][j].rgbtBlue * (2)) + (temp[i + 1][j + 1].rgbtBlue * (1)));
            }

            //Right row pixel
            if ((j == width - 1) && ((i != 0) || (i != height - 1)))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (0)) +
                         (temp[i][j - 1].rgbtRed * (-2)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (-1)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (0)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (0)) +
                           (temp[i][j - 1].rgbtGreen * (-2)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (-1)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (0)));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (0)) +
                          (temp[i][j - 1].rgbtBlue * (-2)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (-1)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (0)));

                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (-2)) + (temp[i - 1][j + 1].rgbtRed * (0)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (1)) + (temp[i + 1][j].rgbtRed * (2)) + (temp[i + 1][j + 1].rgbtRed * (0)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (-2)) + (temp[i - 1][j + 1].rgbtGreen * (0)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (1)) + (temp[i + 1][j].rgbtGreen * (2)) + (temp[i + 1][j + 1].rgbtGreen * (0)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (-2)) + (temp[i - 1][j + 1].rgbtBlue * (0)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (1)) + (temp[i + 1][j].rgbtBlue * (2)) + (temp[i + 1][j + 1].rgbtBlue * (0)));
            }

            //Middle pixel
            if (((j != 0) && (j != width - 1)) && ((i != 0) && (i != height - 1)))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (1)) +
                         (temp[i][j - 1].rgbtRed * (-2)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (2)) +
                         (temp[i + 1][j - 1].rgbtRed * (-1)) + (temp[i + 1][j].rgbtRed * (0)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (1)) +
                           (temp[i][j - 1].rgbtGreen * (-2)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (2))) +
                          (temp[i + 1][j - 1].rgbtGreen * (-1)) + (temp[i + 1][j].rgbtGreen * (0)) + (temp[i + 1][j + 1].rgbtGreen * (1));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (1)) +
                          (temp[i][j - 1].rgbtBlue * (-2)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (2)) +
                          (temp[i + 1][j - 1].rgbtBlue * (-1)) + (temp[i + 1][j].rgbtBlue * (0)) + (temp[i + 1][j + 1].rgbtBlue * (1)));

                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (-2)) + (temp[i - 1][j + 1].rgbtRed * (-1)) +
                         (temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) +
                         (temp[i + 1][j - 1].rgbtRed * (1)) + (temp[i + 1][j].rgbtRed * (2)) + (temp[i + 1][j + 1].rgbtRed * (1)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (-2)) + (temp[i - 1][j + 1].rgbtGreen * (-1)) +
                           (temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) +
                           (temp[i + 1][j - 1].rgbtGreen * (1)) + (temp[i + 1][j].rgbtGreen * (2)) + (temp[i + 1][j + 1].rgbtGreen * (1)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (-2)) + (temp[i - 1][j + 1].rgbtBlue * (-1)) +
                          (temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) +
                          (temp[i + 1][j - 1].rgbtBlue * (1)) + (temp[i + 1][j].rgbtBlue * (2)) + (temp[i + 1][j + 1].rgbtBlue * (1)));
            }

            // 0,0 pixel
            if ((i == 0) && (j == 0))
            {
                //X movement
                GxRed = ((temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (2)) + (temp[i + 1][j].rgbtRed * (0)) +
                         (temp[i + 1][j + 1].rgbtRed * (1)));
                GxGreen = ((temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (2)) + (temp[i + 1][j].rgbtGreen * (0)) +
                           (temp[i + 1][j + 1].rgbtGreen * (1)));
                GxBlue = ((temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (2)) + (temp[i + 1][j].rgbtBlue * (0)) +
                          (temp[i + 1][j + 1].rgbtBlue * (1)));

                //Y movement
                GyRed = ((temp[i][j].rgbtRed * (0)) + (temp[i][j + 1].rgbtRed * (0)) + (temp[i + 1][j].rgbtRed * (2)) +
                         (temp[i + 1][j + 1].rgbtRed * (1)));
                GyGreen = ((temp[i][j].rgbtGreen * (0)) + (temp[i][j + 1].rgbtGreen * (0)) + (temp[i + 1][j].rgbtGreen * (2)) +
                           (temp[i + 1][j + 1].rgbtGreen * (1)));
                GyBlue = ((temp[i][j].rgbtBlue * (0)) + (temp[i][j + 1].rgbtBlue * (0)) + (temp[i + 1][j].rgbtBlue * (2)) +
                          (temp[i + 1][j + 1].rgbtBlue * (1)));
            }

            // 0,w-1 pixel
            if ((i == 0) && (j == width - 1))
            {
                //X movement
                GxRed = ((temp[i][j - 1].rgbtRed * (-2)) + (temp[i][j].rgbtRed * (0)) + (temp[i + 1][j - 1].rgbtRed * (-1)) +
                         (temp[i + 1][j].rgbtRed * (0)));
                GxGreen = ((temp[i][j - 1].rgbtGreen * (-2)) + (temp[i][j].rgbtGreen * (0)) + (temp[i + 1][j - 1].rgbtGreen * (-1)) +
                           (temp[i + 1][j].rgbtGreen * (0)));
                GxBlue = ((temp[i][j - 1].rgbtBlue * (-2)) + (temp[i][j].rgbtBlue * (0)) + (temp[i + 1][j - 1].rgbtBlue * (-1)) +
                          (temp[i + 1][j].rgbtBlue * (0)));

                //Y movement
                GyRed = ((temp[i][j - 1].rgbtRed * (0)) + (temp[i][j].rgbtRed * (0)) + (temp[i + 1][j - 1].rgbtRed * (1)) +
                         (temp[i + 1][j].rgbtRed * (2)));
                GyGreen = ((temp[i][j - 1].rgbtGreen * (0)) + (temp[i][j].rgbtGreen * (0)) + (temp[i + 1][j - 1].rgbtGreen * (1)) +
                           (temp[i + 1][j].rgbtGreen * (2)));
                GyBlue = ((temp[i][j - 1].rgbtBlue * (0)) + (temp[i][j].rgbtBlue * (0)) + (temp[i + 1][j - 1].rgbtBlue * (1)) +
                          (temp[i + 1][j].rgbtBlue * (2)));
            }

            // h-1,0 pixel
            if ((i == height - 1) && (j == 0))
            {
                //X movement
                GxRed = ((temp[i - 1][j].rgbtRed * (0)) + (temp[i - 1][j + 1].rgbtRed * (1)) + (temp[i][j].rgbtRed * (0)) +
                         (temp[i][j + 1].rgbtRed * (2)));
                GxGreen = ((temp[i - 1][j].rgbtGreen * (0)) + (temp[i - 1][j + 1].rgbtGreen * (1)) + (temp[i][j].rgbtGreen * (0)) +
                           (temp[i][j + 1].rgbtGreen * (2)));
                GxBlue = ((temp[i - 1][j].rgbtBlue * (0)) + (temp[i - 1][j + 1].rgbtBlue * (1)) + (temp[i][j].rgbtBlue * (0)) +
                          (temp[i][j + 1].rgbtBlue * (2)));

                //Y movement
                GyRed = ((temp[i - 1][j].rgbtRed * (-2)) + (temp[i - 1][j + 1].rgbtRed * (-1)) + (temp[i][j].rgbtRed * (0)) +
                         (temp[i][j + 1].rgbtRed * (0)));
                GyGreen = ((temp[i - 1][j].rgbtGreen * (-2)) + (temp[i - 1][j + 1].rgbtGreen * (-1)) + (temp[i][j].rgbtGreen * (0)) +
                           (temp[i][j + 1].rgbtGreen * (0)));
                GyBlue = ((temp[i - 1][j].rgbtBlue * (-2)) + (temp[i - 1][j + 1].rgbtBlue * (-1)) + (temp[i][j].rgbtBlue * (0)) +
                          (temp[i][j + 1].rgbtBlue * (0)));
            }

            // h-1,w-1 pixel
            if ((i == height - 1) && (j == width - 1))
            {
                //X movement
                GxRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (0)) + (temp[i][j - 1].rgbtRed * (-2)) +
                         (temp[i][j].rgbtRed * (0)));
                GxGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (0)) + (temp[i][j - 1].rgbtGreen * (-2)) +
                           (temp[i][j].rgbtGreen * (0)));
                GxBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (0)) + (temp[i][j - 1].rgbtBlue * (-2)) +
                          (temp[i][j].rgbtBlue * (0)));

                //Y movement
                GyRed = ((temp[i - 1][j - 1].rgbtRed * (-1)) + (temp[i - 1][j].rgbtRed * (-2)) + (temp[i][j - 1].rgbtRed * (0)) +
                         (temp[i][j].rgbtRed * (0)));
                GyGreen = ((temp[i - 1][j - 1].rgbtGreen * (-1)) + (temp[i - 1][j].rgbtGreen * (-2)) + (temp[i][j - 1].rgbtGreen * (0)) +
                           (temp[i][j].rgbtGreen * (0)));
                GyBlue = ((temp[i - 1][j - 1].rgbtBlue * (-1)) + (temp[i - 1][j].rgbtBlue * (-2)) + (temp[i][j - 1].rgbtBlue * (0)) +
                          (temp[i][j].rgbtBlue * (0)));
            }

            //Sobel filter algorithm
            int resultRed = round(sqrt((pow(GxRed, 2)) + (pow(GyRed, 2))));
            if (resultRed > 255)
            {
                resultRed = 255;
            }
            image[i][j].rgbtRed = resultRed;

            // if the result is higher than 255
            int resultGreen = round(sqrt((pow(GxGreen, 2)) + (pow(GyGreen, 2))));
            if (resultGreen > 255)
            {
                resultGreen = 255;
            }
            image[i][j].rgbtGreen = resultGreen;

            int resultBlue = round(sqrt((pow(GxBlue, 2)) + (pow(GyBlue, 2))));
            if (resultBlue > 255)
            {
                resultBlue = 255;
            }
            image[i][j].rgbtBlue = resultBlue;


        }
    }

    return;
}
