// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// 2 Bytes
typedef int16_t TWO_BYTES;
typedef uint8_t BYTES;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTES header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    TWO_BYTES samples;
    while (fread(&samples, sizeof(samples), 1, input) != 0)
    {
        samples *= factor;
        fwrite(&samples, sizeof(samples), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
