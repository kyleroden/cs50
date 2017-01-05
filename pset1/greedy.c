#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int num_of_coins = 0;
    float num;
    do {
        printf("Hello! How much change is owed?\n");
        num = get_float();
    } while(num < 0);

    int num_of_cents = num * 100;

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
    printf("%d\n", num_of_coins);
    }
