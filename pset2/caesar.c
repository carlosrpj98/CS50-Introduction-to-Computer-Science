#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    //Checking if the key value prompted is valid
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./ceasar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    //Converting the key value to an integer
    int key = atoi(argv[1]);
    printf("%i\n", key);

    //Prompting a text from he user
    string plain_text = get_string("plaintext: ");
    int cipher_text;
    string cipher;

    //Ciphering the text
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        //Checking if its a lower character
        if (islower(plain_text[i]))
        {
            cipher_text = (((plain_text[i] - 'a') + key) % 26) + 'a';
        }
        //Checking if its an upper character
        else if (isupper(plain_text[i]))
        {
            cipher_text = (((plain_text[i] - 'A') + key) % 26) + 'A';
        }
        //Do not change if its not a character
        else
        {
            cipher_text = plain_text[i];
        }
        printf("%c", cipher_text);
    }
    printf("\n");
    return 0;
}




