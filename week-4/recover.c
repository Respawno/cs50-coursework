#include <stdio.h>
#include <stdlib.h>

// Accept one command line argument, remind user of correct usage,return main and 1.
// Forensic image cannot be opened for reading, program should inform user and return main and 1.
// Files generated should be each named ###.jpg
    // Three digit decimal number starting with 000 for first image.
// If program uses malloc, don't leak memory

// We use an unsigned char because its values goes up to 255
    // A signed char goes from -128 to 127
    // Therefore the JPEG signature byte is a 255 decimal value and would overflow wrap around if we used a signed char.
// The typedef is just giving the word BYTE the defition or use of an unsigned char into the word BYTE. So when we use BYTE in our program we are really just using unsigned char.
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argv != 2)
    {
        printf("Missing command line argument\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File cannot be opened for reading");
        return 1;
    }

    BYTE buffer[512];
    while (fread(buffer, sizeof(buffer), 1, file))
    {
        if (int i = 0; i < buffer; i++)
        {
            if (i == 0xff && 0xd8 && 0xff)
            {
                
            }
        }
    }


}
