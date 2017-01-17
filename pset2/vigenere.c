#include <stdio.h>
#include <cs50.h>
#include <string.h>

char vigenereCipher(string input_txt, char v_key);



int main(int argc, string argv[])
{
    printf("The program has begun!\n");
    string v_key = argv[1];

    if(argc != 2)
    {
        printf("Enter a set of characters to use as a key ('ABC', or 'YKL')\n");
    }

    printf("Key: %s\n", v_key);
}
