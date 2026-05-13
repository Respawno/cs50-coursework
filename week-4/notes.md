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
This would output the same thing as above. You are pointing to the variable/==address== of n!

A pointer is 8 bytes/64 bits large

Say you have a pointer and want to point to the ==VALUE== of the variable:
```c
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
}
```
The output of this would be 50. Yes we could have just printed the variable n but for this example it is easy to read this way in it's simplest form. 
This is also known as the ==dereference== operator.

Now that we are taking off the training wheels we can see under the hood.
For a string we have been using the `<cs50.h>` library.
Take a look at this code:
```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
}
```

Technically, the s variable is a pointer the string. Meaning s points to the address of the string.
Remember that a string is just an **ARRAY** of characters. The address is going to point to the location of the first character in the string.
So in this case it would be "H"
Also remember that in a string it always ends with \0 aka null.
So the code above would print the address of the "string" but really the character "H".

Lets print out all the characters addresses so we can see a better breakdown of what is going on:
```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
```
The output would look like this:
0x5f5e9a118004
0x5f5e9a118004
0x5f5e9a118005
0x5f5e9a118006
0x5f5e9a118007

You may ask why is there 4 character addresses and not 3 because "HI!" is only 3 characters.
Well we are printing the address of that null character we talked about.

Lets take off those training wheels even more and drop the string.
```c
#include <stdio.h>

int main(void)
{
    char *s = ("HI!");
    printf("%s\n", s);
}
```
As you can see we dropped the string function and the cs50 library.

Pointer arithmetic
	Ability to do math on locations of memory
```c
#include <stdio.h>

int main(void)
{
    char *s = ("HI!");
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
```
Output:
H
I
!

Lets do something a little different and see different results
```c
#include <stdio.h>

int main(void)
{
    char *s = ("HI!");
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);
}
```
Output:
HI!
I!
!

```c
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);
}
```
Output:
0x63390afd86b0
0x63390afd86f0

As you can see they output differently even though I typed in "HI!" for both of them.

Lets take a look at this code:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
Here is the output:
s: Hello
t: Hello

 I typed in "hello" so why did both string get changed to uppercase but I only asked for string "t" to be uppercase.
	 Well when we asked string "t" to be string "s". String "t" is point to the memory address of "s". Therefore when we asked "t" to be upper. We are really just changing the h character in string "s" memory location. Therefore that is why they are both capitalized now.

Malloc
	Allows you as the programmer, to allocate a block of a specific size of memory.

Free
	Allows you to tell the compiler to free up that block of memory you previously allocated.

Now lets try to do what we were doing above and try to only capitalize t
```c
// Capitalizes a copy of a string, defining n in loop too

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);

    // Copy string into memory, including '\0'
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Capitalize copy
    t[0] = toupper(t[0]);

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
Output:
s: hello
t: Hello

Ah there we go. So a couple things to note on these lines of code. We use `strlen` because we don't always know what the user will input and how long that string will be. We also add 1 at the end because of that null character. Also notice that we set `strlen`  to the variable n. That way we aren't wasting or calling unneeded functions in the middle condition of the for loop. Moving it the left hand side also will allow it to run only once.

Lets get rid of the loop and use a function instead:
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
```
This would be the same as above just in a function instead. Therefore we don't have to write a loop.

NULL
	A special value in memory, in the event that something goes wrong.
	Both `get_string` and `malloc` can return NULL

```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(s) > 0)
    {
    t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}
```
It is important to note that of the things added
	Both strings have NULL now meaning.
	Also notice that if the string length obtained is 0 it does not proceed with `toupper`
	Lastly we have `free(t)`
		Gives back the memory we took from `malloc` earlier in the program
		This is important because if we had a longer program for like a server. The computer will eventually run out of memory and run into a lot of problems.


Valgrind
```c
// Demonstrates memory erros via valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}
```
There are plenty of errors with this program and we can use valgrind to help spot those errors that are especially in the place of memory.
	In there terminal we would run `valgrind ./"yourprogram"` 
For this specific program we got the output of:
==19738== Memcheck, a memory error detector
==19738== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==19738== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==19738== Command: ./memory
==19738== 
==19738== Invalid write of size 4
==19738==    at 0x109170: main (memory.c:11)
==19738==  Address 0x4b9f04c is 0 bytes after a block of size 12 alloc'd
==19738==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==19738==    by 0x109151: main (memory.c:8)
==19738== 
==19738== 
==19738== HEAP SUMMARY:
==19738==     in use at exit: 12 bytes in 1 blocks
==19738==   total heap usage: 1 allocs, 0 frees, 12 bytes allocated
==19738== 
==19738== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
==19738==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==19738==    by 0x109151: main (memory.c:8)
==19738== 
==19738== LEAK SUMMARY:
==19738==    definitely lost: 12 bytes in 1 blocks
==19738==    indirectly lost: 0 bytes in 0 blocks
==19738==      possibly lost: 0 bytes in 0 blocks
==19738==    still reachable: 0 bytes in 0 blocks
==19738==         suppressed: 0 bytes in 0 blocks
==19738== 
==19738== For lists of detected and suppressed errors, rerun with: -s
==19738== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

Fixed code:
```c
// Demonstrates memory erros via valgrind

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}
```

Garbage Values
```c
#include <stdio.h>

int main(void)
{
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
```
Notice we are not asking the program or user for any score values. Therefore when you run this program it will compile but it will output tons of "garbage values". It may output values it has stored before and what not.

Swap example:
```c
// Fails to swap two integers

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x ,y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```
This fails because of the concept of scope.

Memory break down:
machine code ->
globals ->
heap ->
<- stack


Heap
	Chunk of memory that malloc uses to allocate memory for you.
Stack
	Area of memory that is used anytime you create local variables or call functions

Passing by reference: (Using pointers and addresses)
```c
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x ,y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

Heap overflow
	When you overflow the heap, touching areas of memory you are not supposed to.

Stack overflow
	When too many functions are called, overflowing the amount of memory available.

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("n: ");
    printf("n: %i\n", n);
}
```
Lets drop the training wheels on get_int for now:

```c
#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i", &n);
    printf("n: %i\n", n);
}
```

Lets try to get a string from a user now instead of an int:
```c
#include <stdio.h>

int main(void)
{
    char *s;
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```
This is the code we ran at first but we put in hello as the user input and got core memory dumped error. The program crashes because we declared a pointer with `char *s` but never allocated any memory for it to point to, it is just pointing to a random point of memory.

A couple ways to solve this problem:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
```

We can also drop the `scanf` because we don't know how many characters the human will type in.
More or less we will have to keep in mind how many characters or amounts of memory we will want to be using when asking for user input. Luckily, there are other programming languages like python that will help a lot with asking for user input rather than using C.

File I/O
	We can start,creating, or even saving files.
	Useful commands that we will explore:
		`fopen`
		`fclose`
		`fprintf`
		`fscanf`
		`fread`
		`fwrite`
		`fseek`

Example of using some of those codes to write someones name and number into a phonebook.csv file:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "w");

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}
```
You can use `"a"` instead if `"w"` to have the user input appended in the file that way new data or input won't get deleted or overwritten.

Copy a file as it reads program:
```c
#include <stdio.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dst = fopen(argv[2], "w");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1 ,dst);

    }

    fclose(dst);
    fclose(src);
}
```

Notice the new word `unsigned char`, this is basically us telling the program we are not using integers or negative numbers.

`uint8_t`
	Type that stores an 8 - bit unsigned integer.

`int16_t`
	Type that stores a 16 - bit signed integer.

Signed char
	Reserves one bit for the +/- sign
	Range: -128 to 127
	Example: Useful for storing small integers that could be negative

Unsigned char
	All 8 bits used for the value, no sign
	Range: 0 to 255
	Example: Useful for raw binary data, pixel values, bytes.
