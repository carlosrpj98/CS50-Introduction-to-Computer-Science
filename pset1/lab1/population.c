#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Propmpting the start size from the user
    long Start;
    do
    {
        Start = get_long("Start Size: ");
    }
    while (Start < 9);

    //Prompting the end size from the user
    long End;
    do
    {
        End = get_long("End Size: ");
    }
    while (End < Start);

    //Growth of the population per year
    double growth = Start;
    int years = 0;

    while (growth < End)
    {
        growth = (growth + (((long)growth / 3) - ((long)growth / 4)));
        years++;
    }
    printf("Years: %i", years);
}