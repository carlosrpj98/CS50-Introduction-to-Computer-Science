#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Promp the text from the user
    string text = get_string("Text: ");

    //Counting the number of letters in the text
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    //Counting the number of words in the text
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    words = words + 1;

    //Counting the number of sentences in the text
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    //Applying the Coleman-Liau Index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // Checking the difficult
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}