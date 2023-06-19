#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompting the user for its name
    string name = get_string("Whats your name?\n");
    // Greeting the user
    printf("hello,%s\n", name);
}