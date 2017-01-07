#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Enter name: \n");
    string s = get_string();
    printf("name: %s\n", s);
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]))
        {
            printf("Second initial: %c\n", s[i+1]);
        }
    }
}
