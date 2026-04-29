// This is the correct version with the correct allignment on the bricks

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char brick = '#';
    int height = get_int("Height: ");
    // I got confused on int i = 0. Remember i is the variable you are creating and its an integer the starts at the value 0.
    // The variable is also called a counter. Keeps track of how many times the loop has ran
    for (int i = 0; i < height; i++)
    {
        {
            // This part tripped me on the formula. Didn't realize you could add height - 1 to your i variable.
            for (int k = 0; k < height - 1 - i; k++)
            {
                printf(" ");
            }
        }
            for (int j = 0; j <= i; j++)
            {
            printf("%c", brick);
            }
        printf("\n");
    }
}
