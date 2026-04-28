// Problem set 1 from week 1
#include <cs50.h>
#include <stdio.h>

int main(void)
// Asking the user for their name and returning it with printf
{
    string name = get_string("What's your name?: ");
    printf("hello, %s\n", name);
}
