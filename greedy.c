#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int num_of_coins = 0;
    float num;
    do {
        printf("Hello! Enter an amount of change (0.43, .87, etc) and I'll tell you the minimum number of coins required to create that amount.\n");
        num = get_float();
        //
    } while(num < 0);
    printf("current number: %.2f\n", num);
    //num = round(num);
    int num_of_cents = num * 100;
    printf("After multiplying by 100, number is: %i\n", num_of_cents);
    while (num_of_cents > 100)
    {
        num_of_cents -= 100;
    }
    printf("After subracting the dollars, the number of cents remaining is: %i\n", num_of_cents);
    
    while(num_of_cents >= 25)
    {
        num_of_coins += 1;
        num_of_cents -= 25;
    }
    while(num_of_cents >= 10)
    {
        num_of_coins += 1;
        num_of_cents -= 10;
    }
    while(num_of_cents >= 5)
    {
        num_of_coins += 1;
        num_of_cents -= 5;
    }
    while(num_of_cents >= 1)
    {
        num_of_coins += 1;
        num_of_cents -= 1;
    }
    printf("Miniumum coins required to make %.2f : %d\n", num, num_of_coins);
    }
