#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Get a number between 1 and 8

    int height;
    do
    {
       height = get_int("a number beween 1 and 8: ");
    }
    while(height < 1 || height > 8);

//Print both piramids

    int count = 1;
    for (int i = 0; i < height; i++)
    {
        for (int k = 0 ; k < height - count; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < count; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < count; l++)
        {
            printf("#");
        }
        printf("\n");
        count++;
    }
}
