#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get the card number from user
    long number;
    do
    {
        number = get_long("Card number: ");
    }
    while (number < 0);

    //Luhn Algorithm

    long a; //Penultimate number (start)
    long b; //Last number
    long multi = 0; //Result from multiplication
    long separate; //To separate the results in two integer
    long sum = 0; //Sum of the other numbers
    long total; //Total of the Luhn Algorithm

    for (long d = number ; d > 0 ; d = d / 100)
    {
        a = (((d / 10) % 10) * 2);
        if (a > 9)
        {
            separate = a % 10;
            a  = separate + 1;
        }
        multi += a;
        b = (d % 10);
        sum += b;
        total = sum + multi;

    }

    total = total % 10;

    //Length of the number
    int length = 0;
    long k = number;
    while (k > 0)
    {
        k = (k / 10);
        length++;
    }

    //initial numbers
    long d = (length - 2);
    long e = pow(10, d);
    int initial = (number / e);

    //Check which card it is

    // American Express. length = 15 | initial = 34 or 37
    // MasterCard. length = 16 | initial = 51, 52, 53, 54 or 55
    //Visa. length = 13 or 16 | initial = 4

    if (total == 0)
    {
        if (length == 15 && (initial == 34 || initial == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (initial == 51 || initial == 52 || initial == 53 || initial == 54 || initial == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && ((initial / 10) == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
