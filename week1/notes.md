// Week 1 notes
Source code --> complier --> machine code

GUI (Graphical User Interface)

Manual Pages
	manual.cs50.io
	Man pages to find a lot of libraries for C

Prototype
	A way to call a function or variable that might not be at the beginning of your code
```c
#include <cs50.h>
#include <stdio.h>

// Prototype
void meow(void);

int main(void)
{
	for(int i - 0; i < 3; i++)
	{
		meow();
	}
}

void meow(void)
{
	printf("meow\n");
}
```

Constant Value
	Will not let you change a value of a variable if you try to later on. Keeps it the same throughout the entire program.

Long
	You can use a long instead of an integer because a long is 64 bits allowing you to reach a higher number/value.
