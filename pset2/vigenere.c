#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char* vigenereCipher(string input_txt, char* v_key);


int main(int argc, string argv[])
{
    //this isn't really working too well yet
    if(argc != 2)
    {
        printf("Enter a set of characters to use as a key ('ABC', or 'YKL')\n");
        return 1;
    }
    //key for encrypting
    string v_key = argv[1];
    //get the length of the key
    int key_len = strlen(v_key);
    //loop over each char in the key, to ensure that each is alphabetic
    for(int i = 0; i < key_len; i++)
    {
        if(!isalpha(v_key[i]))
        {
            printf("Keyword must only contain alphabetic characters ('a-z, A-Z')\n");
            return 1;
        }
    }

    //print instructions to user to enter text which will be encrypted
    printf("plaintext: ");
    //store the input in variable
    string plain_text = get_string();
    //run the encryption function
    string crypt_text = vigenereCipher(plain_text, v_key);
    //print out the encrypted text
    printf("ciphertext: %s\n", crypt_text);
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
    //store the length of the key so we can ensure that the chars in the key are looped through properly
    int key_len = strlen(v_key);
    //loop over each char in the text and encrypt it
    //int i is created in iterate over string
    //int k is created to iterate over the key chars
    for(int i = 0, k = 0, n = strlen(plain_txt); i < n; i++)
    {
        if(isalpha(plain_txt[i])) //the char is alphabetic, so we encrypt
        {
            if(isupper(plain_txt[i]))
            {
                //get the ascii value of the char in plain_txt
                //if plain_txt = HELLO, y is 72
                int y = (int) plain_txt[i] - 65;
                //get the ascii value of the char to encrypt to
                // with a key of CBA, r is 2
                int r = (int) (v_key[(k) % key_len]) - 65;
                //
                enc_txt[i] = (char) ((y + r) % 26) + 65;
                k++;
            }
            else if(islower(plain_txt[i]))
            {
                //get the ascii value of the char in plain_txt
                //if plain_txt = hello, y is 104
                int y = (int) plain_txt[i] - 97;
                //get the ascii value of the char to encrypt to
                // with a key of cba, r is 2
                int r = (int) (v_key[(k) % key_len]) - 97;
                //
                enc_txt[i] = (char) ((y + r) % 26) + 97;
                k++;

            }
        }
        else //the char is not alphabetic
        {
            enc_txt[i] = plain_txt[i];
        }
    }
    return enc_txt;
}
