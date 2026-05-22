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

Node list example
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // Prepend node to list. Insert to start
        n->next = list;
        list = n;
    }
    return 0;
}
```

A way to print the numbers with a while loop
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // Prepend node to list. Insert to start
        n->next = list;
        list = n;
    }

    // Print numbers
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    return 0;
}
```

Now with a for loop:
```c
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // Prepend node to list. Insert to start
        n->next = list;
        list = n;
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    return 0;
}
```

Difference between array lists vs linked lists
Problem with array list
	We can't insert or delete data into an address. Everything would have to shift to right or left and it would be very hard to code if we had a lot of data.
This is where linked lists have the advantage.
	Linked lists do not have index's the same way arrays do.
	Linked lists use nodes and they are contiguous and can be anywhere in your computers memory. Each node knows where the next node resides.
	We know when we reached then end of our linked list when the address/pointer has a value of "NULL".
	If we delete a node. The node would just point to the next node in line.
	In a linked list we have to start with the head(start) and go through the nodes to find what we are looking for. That is called a ==Singly Linked List==
	A doubly linked list would store two address on a computers memory for one piece of data.
		Benefit would be that would could start for head or tail(end) of a the list to look for what we are looking for.
		Downside would be that a doubly linked list would take up more computer memory.

```c
// Frees memory in cases of error too

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

void unload(node *list);

int main(void)
{
    // Memory for numbers
    node *list = NULL;

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload(list);
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list
        else if (n->number < list->number)
        {
            n->next = list;
            list = n; 
        }

        // If number belongs later in list
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    unload(list);
    return 0;
}

void unload(node *list)
{
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
```

Notice that the `unload` function frees the entire list.

Trees
	How can we combine both arrays and linked lists?
		Binary search trees
			Downside is a lot more memory usage

```c
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}node;
```

```c
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}node;

bool search(node *tree, int number)
{
    if (tree = NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else if (number == tree->number)
    {
        return true;
    }
}
```

![[Pasted image 20260522143458.png]]
The code above is doing what this tree is showing.

Hashing
	Idea of taking a value and being able to output a value that becomes a shortcut to it later.
```c
#include <ctype.h>

int hash(char *name)
{
    return toupper(name[0]) - 'A';
}
```

Hash Tables
	Combination of both arrays and linked lists
		Array of pointers to nodes
	`node *table[26];`
![[Pasted image 20260522153318.png]]
Picture of an example of an array linked list.

Tries
	Another form of data structure.
	Trees of arrays.
	Always searchable in constant time.
	Downside is that they tend to take up a large amount of memory.
```c
typedef struct node
{
    struct node *childern[26];
    char *number;
} node;
```
