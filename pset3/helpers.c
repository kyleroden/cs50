/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n < 0)
    {
        return false;
    }
    else
    {
        //establish the lower and upper limits of the array of values
        int upper = size - 1;
        int lower = 0;

        int midpoint = floor(n / 2);
        if(midpoint == value)
        {
            return true;
        }
        else
        {
            values[0] = midpoint + 1;
            search()
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
