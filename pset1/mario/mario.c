#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get int from user
    int i;
    do
    {
        i =  get_int("A number between 1 and 8: ");
    }
    while (i < 1 || i > 8);

    //Print the "#" and " ".
    for (int h = 0 ; h < i ; h++)
    {
        for (int x = i - h ; x > 1; x--)
        {
            printf(" "); // The spaces
        }
        for (int l = 0 ; l < h + 1 ; l++)
        {
            printf("#"); // The hashes
        }
        printf("\n");
    }
}

