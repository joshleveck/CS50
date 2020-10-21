#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float grey;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            grey = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);
            image[j][i].rgbtBlue = grey;
            image[j][i].rgbtGreen = grey;
            image[j][i].rgbtRed = grey;
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int buff[3];

    for (int i = 0; i < width/2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            buff[0] = image[j][i].rgbtBlue;
            buff[1] = image[j][i].rgbtGreen;
            buff[2] = image[j][i].rgbtRed;

            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = buff[0];
            image[j][width - i - 1].rgbtGreen = buff[1];
            image[j][width - i - 1].rgbtRed = buff[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float blur;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i != 0 && i != width - 1 && j != 0 && j != height) {
            blur = round((image[j + 1][i + 1].rgbtBlue + image[j + 1][i].rgbtBlue + image[j + 1][i - 1].rgbtBlue + image[j][i + 1].rgbtBlue + image[j][i].rgbtBlue + image[j][i - 1].rgbtBlue + image[j - 1][i + 1].rgbtBlue + image[j - 1][i].rgbtBlue + image[j - 1][i - 1].rgbtBlue) / 9.000);
            image[j][i].rgbtBlue = blur;

            blur = round((image[j + 1][i + 1].rgbtGreen + image[j + 1][i].rgbtGreen + image[j + 1][i + 1].rgbtGreen + image[j][i + 1].rgbtGreen + image[j][i].rgbtGreen + image[j][i - 1].rgbtGreen + image[j - 1][i + 1].rgbtGreen + image[j - 1][i].rgbtGreen + image[j - 1][i - 1].rgbtGreen) / 9.000);
            image[j][i].rgbtGreen = blur;

            blur = round((image[j + 1][i + 1].rgbtRed + image[j + 1][i].rgbtRed + image[j + 1][i + 1].rgbtRed + image[j][i + 1].rgbtRed + image[j][i].rgbtRed + image[j][i - 1].rgbtRed + image[j - 1][i + 1].rgbtRed + image[j - 1][i].rgbtRed + image[j - 1][i - 1].rgbtRed) / 9.000);
            image[j][i].rgbtRed = blur;
            }
        }
    }
    return;
}

// Detect edges

//i didn't really figure this one out
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create line var that holds the value of the final pixel
    float line;

    // create the gx and gy array that will multiply the numbers
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int i = 0; i < width; i++) {

        for (int j = 0; j < height; j++) {

            //initialize the var that will hold the addition data

            float lineXb = 0;
            float lineXg = 0;
            float lineXr = 0;

            float lineYb = 0;
            float lineYg = 0;
            float lineYr = 0;

            for (int k = -1; k < 2; k++) {

                for (int l = -1; l < 2; l++) {

                    if (i + l > 0 && i + l < width && j + k > 0 && j + k < height) {

                        //for a 3x3 square around the pixel that is not out of the image, multiply the values by the array

                        lineXb += (image[j + k][i + l].rgbtBlue * gx[k + 1][l + 1]);
                        lineXg += (image[j + k][i + l].rgbtGreen * gx[k + 1][l + 1]);
                        lineXr += (image[j + k][i + l].rgbtRed * gx[k + 1][l + 1]);

                        lineYb += (image[j + k][i + l].rgbtBlue * gy[k + 1][l + 1]);
                        lineYg += (image[j + k][i + l].rgbtGreen * gy[k + 1][l + 1]);
                        lineYr += (image[j + k][i + l].rgbtRed * gy[k + 1][l + 1]);

                    }
                }
            }

            //all of the math that makes the final pixel value

            line  = round(sqrt(pow(lineXb, 2) + pow(lineYb, 2)));
            if (line > 255) {
                line = 255;
            }
            image[j][i].rgbtBlue = line;

            line  = round(sqrt(pow(lineXg, 2) + pow(lineYg, 2)));
            if (line > 255) {
                line = 255;
            }
            image[j][i].rgbtGreen = line;

            line  = round(sqrt(pow(lineXr, 2) + pow(lineYr, 2)));
            if (line > 255) {
                line = 255;
            }
            image[j][i].rgbtRed = line;
        }
    }
    return;
}
