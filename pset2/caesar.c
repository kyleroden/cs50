#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

char* caesarCipher(string input_text, int cipher_key);

int main(int argc, string argv[])
{
    //store the key in variable, converted from string to int
    int cipher_key = atoi(argv[1]);
    //take user input
    if(argc != 2)
    {
        printf("Error. Run 'caesar x', where x is a number used as a cipher key.\n");
        //indicates that the program didn't run correctly due to lacking the key argument
        return 1;
    }
    else
    {
        //gather user input
        printf("plaintext: ");
        string plain_text = get_string();
        if(plain_text != NULL || "")
        {
            //encrypt the text
            string encrypted_text = caesarCipher(plain_text, cipher_key);
            printf("ciphertext: %s\n", encrypted_text);
            free(encrypted_text);
        }
    }
    //indicates that all went well
    return 0;
}


char* caesarCipher(string plain_text, int cipher_key)
{
    char* plain = plain_text;
    char* encrypted_text = malloc(sizeof(plain));
    //iterate over each character in plain and push the ascii value of that char to a new array
    for(int i = 0, n = strlen(plain); i < n; i++)
    {
        //check to see if the char is alphabetic
        if(isalpha(plain[i]))
        {
            //check to see if the char is uppercase, if so, then we need to make the range 65-90, 65 = A, 90 = Z
            if(isupper(plain[i]))
            {
                //get the ascii value of the i'th character in plain
                int k = (int) plain[i];
                //add the value of cipher key to k
                int l = k + (cipher_key % 26);

                //change the ascii value by the key, but subtract 26 if that value goes past Z / z
                if(l > 90)
                {
                    //this works, kinda, but not if the value of the key is high (like 65, with one of the test cases)
                    l -= 26;
                    //l = (l % 26) + 65;
                }
                encrypted_text[i] = (char) l;
                //printf("%c", (char) l);
            }
            else if(islower(plain[i]))
            {
                //get the ascii value of the i'th character in plain
                int k = (int) plain[i];
                //add the value of cipher key to k
                int l = k + (cipher_key % 26);

                //change the ascii value by the key, but subtract 26 if that value goes past Z / z
                if(l > 121)
                {
                    l -= 26;
                }
                encrypted_text[i] = (char) l;
            }
            else
            {

            }
        }
        else
        {
            encrypted_text[i] = plain[i];
        }
    }
    return encrypted_text;
}
