#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./caesar");
        return 1;                  // stop the program if the user didn't give a command
    }
    else
    {
        int key = atoi(argv[1]);  // convert argv[1] to an integer
        string plaintext = get_string("plaintext: "); // ask the user for a text
        int len = strlen(plaintext); // determine the length of plaintext
        printf("ciphertext: ");
        for (int i = 0; i < len; i++)
        {
            if (islower(plaintext[i])) // if the character is lower case
            {
                int p = plaintext[i] - 97;
                int c = (p + key) % 26;
                int x = c + 97;
                printf("%c", x);
            }
            else if (isupper(plaintext[i])) // if the character is upper case
            {
                int p = plaintext[i] - 65; // convert a to 0, b to 1 ...
                int c = (p + key) % 26; //the formula to rotate each character by k positions
                int x = c + 65; //the ascii value of the character
                printf("%c", x);
            }
            else
            {
                printf("%c", plaintext[i]); // if the characte is not alphabetic it won't be changed
            }
        }
        printf("\n");
    }
    
}
