#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            if (average > 255)
            {
                average = 255;
            }
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width / 2; k++)
        {
            RGBTRIPLE tmpPixel = image[i][k];
            image[i][k] = image[i][(width - 1) - k];
            image[i][(width - 1) - k] = tmpPixel;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            tmp_image[i][k] = image[i][k];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int sum_red = tmp_image[i][k].rgbtRed;
            int sum_blue = tmp_image[i][k].rgbtBlue;
            int sum_green = tmp_image[i][k].rgbtGreen;
            float counter = 1.00;

            if (k - 1 >= 0)
            {
                sum_red += tmp_image[i][k - 1].rgbtRed;
                sum_blue += tmp_image[i][k - 1].rgbtBlue;
                sum_green += tmp_image[i][k - 1].rgbtGreen;
                counter++;

                if (i + 1 < height)
                {
                    sum_red += tmp_image[i + 1][k - 1].rgbtRed;
                    sum_blue += tmp_image[i + 1][k - 1].rgbtBlue;
                    sum_green += tmp_image[i + 1][k - 1].rgbtGreen;
                    counter++;
                }

                if (i - 1 >= 0)
                {
                    sum_red += tmp_image[i - 1][k - 1].rgbtRed;
                    sum_blue += tmp_image[i - 1][k - 1].rgbtBlue;
                    sum_green += tmp_image[i - 1][k - 1].rgbtGreen;
                    counter++;
                }
            }

            if (k + 1 < width)
            {
                sum_red += tmp_image[i][k + 1].rgbtRed;
                sum_blue += tmp_image[i][k + 1].rgbtBlue;
                sum_green += tmp_image[i][k + 1].rgbtGreen;
                counter++;

                if (i + 1 < height)
                {
                    sum_red += tmp_image[i + 1][k + 1].rgbtRed;
                    sum_blue += tmp_image[i + 1][k + 1].rgbtBlue;
                    sum_green += tmp_image[i + 1][k + 1].rgbtGreen;
                    counter++;
                }

                if (i - 1 >= 0)
                {
                    sum_red += tmp_image[i - 1][k + 1].rgbtRed;
                    sum_blue += tmp_image[i - 1][k + 1].rgbtBlue;
                    sum_green += tmp_image[i - 1][k + 1].rgbtGreen;
                    counter++;
                }
            }

            if (i + 1 < height)
            {
                sum_red += tmp_image[i + 1][k].rgbtRed;
                sum_blue += tmp_image[i + 1][k].rgbtBlue;
                sum_green += tmp_image[i + 1][k].rgbtGreen;
                counter++;
            }

            if (i - 1 >= 0)
            {
                sum_red += tmp_image[i - 1][k].rgbtRed;
                sum_blue += tmp_image[i - 1][k].rgbtBlue;
                sum_green += tmp_image[i - 1][k].rgbtGreen;
                counter++;
            }

            if (round(sum_red/counter) > 255)
            {
                image[i][k].rgbtRed = 255;
            }
            else
            {
                image[i][k].rgbtRed = round(sum_red / counter);
            }

            if (round(sum_blue/counter) > 255)
            {
                image[i][k].rgbtBlue = 255;
            }
            else
            {
                image[i][k].rgbtBlue = round(sum_blue / counter);
            }

            if (round(sum_green/counter) > 255)
            {
                image[i][k].rgbtGreen = 255;
            }
            else
            {
                image[i][k].rgbtGreen = round(sum_green / counter);
            }

        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
