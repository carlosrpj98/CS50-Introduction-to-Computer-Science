#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Opening the file
    FILE *input_file = fopen(argv[1], "r");

    //Checking if the file exists
    if (input_file == NULL)
    {
        printf("Could not open the file!\n");
        return 1;
    }
    //Checking the number of arguments
    else if (argc != 2)
    {
        printf("usage: ./recover FILENAME\n");
        return 2;
    }

    BYTE buffer[512]; //Array with a size of 512 chunks

    FILE *output_file = NULL; // File that the data will be pasted

    int count = 0; //Counting the number of images found

    char *filename = malloc(8 * (sizeof(char))); //Alocating the memory to create strings

    while (fread(buffer, sizeof(BYTE) * 512, 1, input_file) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count > 0)
            {
                fclose(output_file);
            }

            sprintf(filename, "%03i.jpg", count); //Printing the name into a string

            output_file = fopen(filename, "w");

            count++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, output_file);
        }

    }
    fclose(input_file);
    free(filename);
    fclose(output_file);
    return 0;
}
