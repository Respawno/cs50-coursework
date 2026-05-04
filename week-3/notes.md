Algorithm
	Step by step instructions to solve a problem

Arrays
	Arrays under the hood inside of computer hold memory. You could think of when the computer goes and looks for those memory chunks it is like all doors are closed.
		Can't just have a bird's eye view of everything
	In its simplest form it can only look at one value/one chunk of memory at a time.

Pseudocode examples:
```
For each door from left to right
	If 50 is behind door
		Return true
Return false
```
Computer scientist translation:
```
For i from 0 to n-1
	If 50 is behind door[i]
		Return true
Return false
```

Common running times:
- 𝑂⁡(𝑛2)
- 𝑂⁡(𝑛⁢log⁡𝑛)
- 𝑂⁡(𝑛)          -       Linear search
- 𝑂⁡(log⁡𝑛)     -       Binary search
- 𝑂⁡(1)  

Linear search example
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

What happens when we try to search a for a string in an array?
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strings[i] == s)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```
You will come to find that even entering a string in correctly you will be left with not found.
Why is that?
	Need to use `<string.h>` and will give us the function:
		`strcmp`
Example code:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

Phonebook example:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string names[] = {"Kelly", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    string name = get_string("Name: ");
    for (int i = 0; i <3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n")
    return 1; 
}
```
This example shows an error
	We are assuming that both arrays have correct data lined up. Meaning both numbers and names are both aligned correctly. But what if we were to have them mixed up.

Data Structures
```c
typedef struct
{
	string name;
	string number;
} person;
```

Example code:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main (void)
{
    person people[3];

    people[0].name = "Kelly";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

Sorting
```
For i from 0 n-1
	Find smallest number between numbers[i] and numbers[n-1]
	Swap smallest number with numbers[i]
```

Bubble sort
```c
Repeat n times
	For i from 0 to n-2
		If numbers[i] and numbers[i+1] out of order
			Swap them
		If no swaps
			Quit
```

Recursion
	A concept within programming where a function calls itself.
```c
If no doors left
	Return false
If number behind middle door
	Return true
Else if number < middle door
	Search left half
Else if number > middle door
	Search right half
```

 Example of iteration (Same Mario problem from week 1)
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    // For each row of pyramid
    for (int i = 0; i < n; i++)
    {
        // For each column of pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```

Recursion
	Algorithm that calls upon itself with the process of the tasl
		Base Case
			Logic "bottoms out" and no more recursions or work can be done and the recursion then "unfold" or cease.
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    // Base case
    if (n == 0)
    {
        return;
    }

    // Print a pyramid of heigh n - 1
    draw(n - 1);

    // Print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```
Prints same as above

Merge Sort
```c
Sort left half of numbers
Sort right half of numbers
Merge sorted halves
```
