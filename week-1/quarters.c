#include <cs50.h>
#include <stdio.h>

// Prototype
int calc_quarters(int cents);

int main(void)
{
    // Make an integer for cents and asking the user how much change is owed. Also not allowing the user to input 0 or lower
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calc_quarters(cents);

    cents = cents - (quarters * 25);

    printf("%i\n", quarters);
}

int calc_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

