Data Structures
	Forms of organization in memory

Queues
	FIFO
		First in first out

```c
const int CAPACITY = 50;

typedef struct
{
	person people[CAPACITY]
	int size;
}queue;
```

We have an array person people and the capacity = 50 people.
The int size is keeping track of the actual size of people we have in a given moment.
This line of code/problem has a limitation and that being if we wanted 51 people we are limited in that capacity.
 Problem is we only have so much memory in a computer.. If we were to set this to lets say 1,000 people to over compensate and only 2 people showed up. That is a lot of wasted memory.

Stacks
	LIFO
		Last in first out 
```c
const int CAPACITY = 50;

typedef struct
{
	person people[CAPACITY]
	int size;
}
stack;
```
Lets go line by line in this one
`const int CAPACITY = 50`
	This is setting the integer of capacity to 50. Since its a const it can't be changed afterwards.
`typedef struct.....stack;`
	This creates a new custom type called stack. Means later I can use `stack myStack;` instead of `struct stack myStack`.
Inside the struct:
	`person people[CAPACITY]`
		An array of person with a fixed size of 50. Actual storage for the stack's data.
	`int size;`
		Tracks how many items/elements are in the stack. Increases or decreases as items are pushed or popped.
Notice they are practically the same but... stack and queues essentially determine how I will use them later in functions just by the way we name them.

If you name it queue
	`enqueue()` and `dequeue()`
		functions that to the back and remove from the front.
If you name it stack
	`push()` and `pop()`
		functions that add or removed from the top.

Dictionaries
	Two column table
		word | definition

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes

    int *tmp = malloc(4 * sizeof(int));
    if (list == NULL)
    {
        free(list);
        return 1;
    }

    // Copy old list into new list
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    // Free original list
    free(list);

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);

    return 0;
}
```
Program that allocates memory for 3 integers than changes it mind and allocates for 4 integers. Then frees the memory of the previous 3 integers after copying the old integers into the new set of 4 and adds the last 4 value.

One way we can copy the array without a for loop is by using `realloc`

It will look something like this:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes

    int *tmp = realloc(list, 4 * sizeof(int));
    if (list == NULL)
    {
        free(list);
        return 1;
    }

    // Free original list
    free(list);

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);

    return 0;

}
```

Linked lists
	Operator = `->`
	One of the most powerful data structures within C.
	Allows you to include values that are located in varying areas of memory.
		Allow you to dynamically grow and shrink the list as you desire.

Data
	Values you care about.

Metadata
	Data that helps you maintain the data you care about.

