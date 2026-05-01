#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// Our program can only be run with just one command-line argument. Need something to check that.
    // If user does not provide one or provides more than one than we should remind them with a usage key
        // Usage: ./caesar key
// Need to also make sure every character in argv[1] is a digit.
// Convert argv[1] from a 'string' to an 'int'
int main (int argc, string argv[]) // int argc is the "argument count" string argv is the "array of strings"
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converting string to integer
    int key = atoi(argv[1]);
    // Prompt user plaintext
    string plaintext = get_string("Plaintext: ");
    // For each character in plaintext
        // Rotate the character if it's a letter.
    // 𝑐𝑖=(𝑝𝑖+𝑘)⁢ % ⁢26
    printf("Cipher: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            // rotate
            // Convert the letter to its alphabet position (0-25), Example = X - A = 88-65 = 23 (X is the 24th letter postion, but 23 when zero-indexed)
            // Add the key and wrap it back around with "% 26". This way it doesn't trip up on the ascii table and wraps back around the char we want.
            // Convert back to an ASCII letter by adding 'A'. Will replicate same for lowercase.
            // Printing every character as it loops through
            printf("%c", (plaintext[i] - 'A' + key) % 26 + 'A');

        }
        else if (islower(plaintext[i]))
        {
            //rotate
            printf("%c", (plaintext[i] - 'a' + key) % 26 + 'a');
        }
        else
        {
            // print as is
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
    // Need that output to be the ciphertext.
    // Program must preserve case sens for boht lower and upper case.
    // Ciphertext should also print a newline
        // Program should then exit by returning 0 from main
}
