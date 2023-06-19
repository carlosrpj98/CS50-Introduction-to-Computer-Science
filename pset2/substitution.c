#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //Checking if the key prompted is valid

    if (argc != 2) //It must contain just two arguments
    {
        printf("./Substitution KEY\n");
        return 1;
    }
    else if (strlen(key) != 26) //It must contain exactly 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(key); i < n; i++) //Looking for non alphabetic characters
        {
            if (isalpha(key[i]) == false)
            {
                printf("Key must contain only alphabetic characters.\n");
                return 1;
            }
        }
        for (int i = 0, n = strlen(key); i < n; i++) //Looking for repetitive characters
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (key[j] == key[i])
                {
                    count++;
                }
                if (count > 1)
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }

    //Alphabetic index
    string index_lower = "abcdefghijklmnopqrstuvwxyz";
    string index_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    //Getting the text to be enciphered
    string plain_text = get_string("plaintext: ");

    //Ciphering the string prompted
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        for (int j = 0, m = strlen(index_lower); j < m; j++)
        {
            if (plain_text[i] == index_lower[j])
            {
                int lower = index_lower[j] - 'a';
                printf("%c", tolower(key[lower]));
            }
            else if (plain_text[i] == index_upper[j])
            {
                int upper = index_upper[j] - 'A';
                printf("%c", toupper(key[upper]));
            }
        }
        if (isalpha(plain_text[i]) == false)
        {
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
    return 0;
} 





