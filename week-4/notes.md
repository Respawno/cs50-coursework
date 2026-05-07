Hexadecimal
	Aka base -16
		System of counting that has 16 counting values.
			0 1 2 3 4 5 6 7 8 9 A B C D E F
		Hexadecimal is usually prefix to avoid confusion like such:
			0x0 0x1 0x2 ....... 0xf and so on.

We can pull address from an integer. We know integers take up 4 bytes on a memory stick. Well using this code of `%p` and a `&`, we can print the address of that variable

```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}
```

Output:
0x7ffd9685731c

Pointer
	A variable that stores the address of something.
	The `*` key makes a pointer

Example of a pointer being used:
```C
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
}
```
This would output the same thing as above. You are pointing to the variable/address of n!

A pointer is 8 bytes/64 bits large
