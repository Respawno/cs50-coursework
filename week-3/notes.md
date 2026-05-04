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
