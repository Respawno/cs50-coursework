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
int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }
    // Need to get key to know how much letter rotation there will be.
    // Prompt user plaintext
    // For each character in plaintext
        // Rotate the character if it's a letter.
    string plaintext = get_string("Plaintext: ");

    // Need that output to be the ciphertext.
    // Program must preserve case sens for boht lower and upper case.
    // Ciphertext should also print a newline
        // Program should then exit by returning 0 from main

}
