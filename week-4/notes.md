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
