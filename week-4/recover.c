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
typedef unsigned char BYTES;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("File cannot be opened for reading");
        return 1;
    }

    // This searchs the file for a jpeg image.
    // A jpeg image uses/has specific "signatures" patterns of bytes
    // We use 512 bytes in the array because the digital camera memory file system is a "FAT" and their block sizes are 512 bytes.
    BYTES buffer[512];
    int found_jpeg = 0;
    int count_jpeg = 0;
    FILE *current_file;
    char filename[8];
    while (fread(buffer, sizeof(buffer), 1, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef) // Looking for the specific type of "signatures"
        {
            found_jpeg = 1; // If jpeg is found the boolean turns into true using 1.
            if (count_jpeg > 0) // If the count_jpeg is higher than 0 it will close the output. Output is before because it has to copy its data over. When it loops back over than it will close
            {
                fclose(output);
            }
            sprintf(filename, "%03d.jpg", count_jpeg); // Copying data to jpg files using sprintf.
            current_file = fopen(filename, "wb"); // Open new file get it ready for binary data. Point current_file to it.
            count_jpeg++; // Updates the count_jpeg for the loop above.
        }
        if (found_jpeg == 1) // Checking to see if jpeg was found.
        {
            fwrite(buffer, sizeof(buffer), 1 ,current_file); // Write the data into the opened file above.
        }
    }
    if (found_jpeg == 1)
    {
        fclose(current_file); // Making sure that the current file open will always be closed
    }
    fclose(file); // Close first file.
}
