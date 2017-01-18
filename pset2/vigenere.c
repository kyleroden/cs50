#include <stdio.h>
#include <cs50.h>
#include <string.h>

char* vigenereCipher(string input_txt, char* v_key);


int main(int argc, string argv[])
{
    printf("The program has begun!\n");
    string v_key = argv[1];
    //this isn't really working too well yet
    if(argc != 2)
    {
        printf("Enter a set of characters to use as a key ('ABC', or 'YKL')\n");
        return 1;
    }
    //print instructions to user to enter text which will be encrypted
    printf("plaintext: ");
    //store the input in variable
    string plain_text = get_string();
    //run the encryption function
    string crypt_text = vigenereCipher(plain_text, v_key);
    //print out the encrypted text
    printf("crypt_text: %s\n", crypt_text);
    free(crypt_text);
    //indicate that all went well
    return 0;
}

char* vigenereCipher(string input_txt, char* v_key)
{
    //get memory for string variables
    char* plain_txt = malloc(sizeof(input_txt));
    char* enc_txt = malloc(sizeof(input_txt));
    //store the text given to the function into variable
    plain_txt = input_txt;
    //loop over each char in the text and encrypt it
    for(int i = 0, n = strlen(plain_txt); i < n; i++)
    {
        int y = (int) plain_txt[i];
        //just temporary garbage, delete this later
        int r = y + 1;
        //fix this later
        enc_txt[i] = (char) r;
    }
    //fix this. currently us to use the v_key
    printf("Key: %s\n", v_key);
    return enc_txt;
}
