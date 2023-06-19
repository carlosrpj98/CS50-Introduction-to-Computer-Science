// Implements a dictionary's functionality

#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 100000

// Hash table
node *table[N];

//Dictionary size variable
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *p = table[index];

    while (p != 0)
    {
        //Comparing the two strings
        if (strcasecmp(word, p->word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //This function sum all the ASCII values of the word together
    unsigned long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char dic_word[LENGTH + 1];
    while (fscanf(file, "%s", dic_word) != EOF)
    {
        node *next_word = malloc(sizeof(node));
        if (next_word == NULL)
        {
            unload();
            return false;
        }
        strcpy(next_word->word, dic_word);

        int index = hash(dic_word);
        next_word->next = table[index];
        table[index] = next_word;
        dict_size++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (dict_size > 0)
    {
        return dict_size;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
