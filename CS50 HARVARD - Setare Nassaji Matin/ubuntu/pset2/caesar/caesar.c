#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{


// check there is only 1 arguments and it is a number else returns instructions
    if (argc != 2)
    {
        printf("Usage: ./ceasar k");
        return 1;
    }
     for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
        //convert into integar
        int k = atoi(argv[1]); 

        string s = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            // checking if it is lowercase
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a'); 
                // print lowercase with key
            }
            //  checking if it is uppercase
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); // print out uppercase with key
            }

            else
                printf("%c", s[i]);
        }

        printf("\n");
        return 0;

}
