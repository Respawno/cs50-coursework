Feel like I need more help in this area. I started the course and was understanding pointers quite well and got lost very quickly. So I am going to take more notes on pointers.

Pointer
	Variable-like reference that holds a memory address to another variable, array, etc.
	Makes some tasks easier like ex:
		Less time in program execution
		Working on the original variable
		With the help of pointers, we can create data structures (linked-list, stack, queue)
		Returning more than one values from functions
		Searching and sorting large data very easily
		Dynamically memory allocation.

```c
#include <stdio.h>

int main()
{
    int age = 21;

    printf("address of age: %p", &age);
    printf("value of age: %d\n", age);

    return 0;

}
```
First line returns the address of the value 21 where it is being stored in memory

Second line returns the actual value of 21

```c
#include <stdio.h>

int main()
{
    int age = 21;
    int *pAge = &age;

    printf("address of age: %p\n", &age);
    printf("value of pAge: %p\n", pAge);

    return 0;

}
```
First printf shows the address of age using &.

The second printf is essentially doing the same thing using pointers
	The `*p` is helping declaring it as a pointer and the `&` is telling the pointer what address to point at. Think as like pointing a finger. If I was to point my finger at a specific address, that address would then become my address.

```c
#include <stdio.h>

int main()
{
    int age = 21;
    int *pAge = &age;

    printf("address of age: %p\n", &age);
    printf("value of pAge: %p\n", pAge);

    printf("value at stored address: %d\n", *pAge);

    return 0;

}
```
You can see in this example I added an extra printf line. In this one it would print out 21 aka the value of age. We use the `*` / indirection operator to dereference the pointer.

```c
#include <stdio.h>

int main()
{
    int age = 21;
    int *pAge = &age;

    printf("address of age: %p\n", &age);
    printf("value of pAge: %p\n", pAge);

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge: %d bytes\n", sizeof(pAge));

    printf("value at stored address: %d\n", *pAge);

    return 0;

}
```
I added a couple more printf lines so you can see the amount of bytes that are being used.
The size of age: 4 bytes
The size of pAge: 8 bytes

Even though we stored our pointer as an int which takes 4 bytes. The actual size is going to be 8 bytes because that is enough to store a hexadecimal address.

Passing a pointer
```c
	#include <stdio.h>

void printAge(int age)
{
    printf("You are %d years old", age);
}

int main()
{
    int age = 21;
    int *pAge = &age;

    printAge(age);

    return 0;
}
```
Passing in a variable

Now lets try it with a pointer
```c
#include <stdio.h>

void printAge(int *pAge)
{
    printf("You are %d years old", *pAge);
}

int main()
{
    int age = 21;
    int *pAge = &age;

    printAge(pAge);

    return 0;

}
```

Good practices
```c
#include <stdio.h>

void printAge(int *pAge)
{
    printf("You are %d years old", *pAge);
}

int main()
{
    int age = 21;
    int *pAge = NULL;
    pAge = &age;

    printAge(pAge);

    return 0;

}
```
Notice the NULL. It is good practice to assign NULL if declaring a pointer.
