#include "helpers.h"
#include <stdio.h>
#include <math.h>

#define RED_COLOUR 0
#define GREEN_COLOUR 1
#define BLUE_COLOUR 2

int Gx_value[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
int Gy_value[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

int grid(int xy);
int get_edges(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colour);
int cap(int c);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Average of colours
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Applying the parameters
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp; // Temporary variable
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Function that return a blur value
int get_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colour)
{
    float count = 0;
    int sum = 0;
    for (int row = i - 1; row <= (i + 1); row++)
    {
        for (int column = j - 1; column <= (j + 1); column++)
        {
            if (row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }
            else if (colour == RED_COLOUR)
            {
                sum += image[row][column].rgbtRed;
            }
            else if (colour == GREEN_COLOUR)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Making a copy of the image
    RGBTRIPLE tempimage[height][width];

    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            tempimage[k][l] = image[k][l];
        }
    }

    // Blur image to each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = get_blur(i, j, height, width, tempimage, RED_COLOUR);
            image[i][j].rgbtGreen = get_blur(i, j, height, width, tempimage, GREEN_COLOUR);
            image[i][j].rgbtBlue = get_blur(i, j, height, width, tempimage, BLUE_COLOUR);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Making a copy of the image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Calling function to get the edges to each colour
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = get_edges(k, l, height, width, copy, RED_COLOUR);
            image[k][l].rgbtGreen = get_edges(k, l, height, width, copy, GREEN_COLOUR);
            image[k][l].rgbtBlue = get_edges(k, l, height, width, copy, BLUE_COLOUR);
        }
    }
    return;
}

// Getting the edges
int get_edges(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colour)
{
    // Variables set to zero
    float sumGx = 0;
    float sumGy = 0;
    int count = 0;

    for (int row = i - 1; row <= (i + 1); row++)
    {
        for (int column = j - 1; column <= (j + 1); column++)
        {
            // Check if the colour is red, green or blue
            // Each color is represented by a global variable
            if (row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }
            else if (colour == RED_COLOUR)
            {
                sumGx += (image[row][column].rgbtRed * Gx_value[row - i + 1][column - j + 1]);
                sumGy += (image[row][column].rgbtRed * Gy_value[row - i + 1][column - j + 1]);
            }
            else if (colour == GREEN_COLOUR)
            {
                sumGx += (image[row][column].rgbtGreen * Gx_value[row - i + 1][column - j + 1]);
                sumGy += (image[row][column].rgbtGreen * Gy_value[row - i + 1][column - j + 1]);
            }
            else if (colour == BLUE_COLOUR)
            {
                sumGx += (image[row][column].rgbtBlue * Gx_value[row - i + 1][column - j + 1]);
                sumGy += (image[row][column].rgbtBlue * Gy_value[row - i + 1][column - j + 1]);
            }
        }

    }
    return cap(round(sqrt((sumGx * sumGx) + (sumGy * sumGy))));
}
// Ensure a return <= 255
int cap(int c)
{
    return c <= 255 ? c : 255;
}