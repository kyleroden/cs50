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
    //establish the lower and upper limits of the array of values
    int upper = n - 1;
    int lower = 0;
    while(lower <= upper)
    {
        //establish the midpoint value
        int midpoint = floor((upper + lower) / 2);
        //check that value to see if it is the value which we're looking for
        if(values[midpoint] == value)
        {
            return true;
        }
        //the value can be found in the right half of the array
        //so we 'forget' the left half by setting the lower to one value right of the midpoint
        else if (value > midpoint)
        {
            lower = midpoint + 1;
        }
        //value can be found in left half, so we forget right half
        else if (value < midpoint)
        {
            upper = midpoint - 1;
        }
    }
    //value can't be found
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    //selection sort
    //for loop to look at each item in the array till size - 2
    for(int i = 0; i < (n - 2); i++)
    {
        int min = i;
        //for loop to compare that item to the rest of the items, seeing which is smaller
        for(int j = (i + 1); j < n; j++)
        {
            //change the value of the smallest to that value if it is smaller
            if(values[j] < values[min])
            {
                min = j;
            }
        }
        //swap the item at min in the correct position
        //first make a temporary variable, and store the value of the min
        int tmp = values[min];
        //then swap the other, higher value, from i to the location where min was
        values[min] = values[i];
        //finally, store the lower value at the i
        values[i] = tmp;
    }

    return;
}
