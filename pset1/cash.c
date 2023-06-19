#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get the change value from user
    float change;
    do
    {
        change = get_float("change:$ ");
    }
    while(change < 0);

    //Comverting to cents
    int cents = round( change * 100 );

    //How much coins do i need
    int counting = 0;

    while(cents >= 25)
    {
        cents = (cents - 25);
        counting ++;
    }
    while(cents >= 10)
    {
        cents = (cents - 10);
        counting ++;
    }
    while(cents >= 5)
    {
        cents = (cents - 5);
        counting ++;
    }
    while(cents >= 1)
    {
        cents = (cents - 1);
        counting ++;
    }
    printf("%i\n", counting);
}