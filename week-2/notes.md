Command Line Arguments
	In addition to giving a command to run a program, inputs can/are also provided to alter various actions of the run.

Compiling
	Source code is entered into a complier that converts the source code to machine code, allowing the program to run on a computer
	Source code --> Compiler --> Machine code
	When you run the command make in your terminal. That is not the complier, you are commanding the machine to compile the code.
		A very popular compiler is called Clang
			Free and open source
	Compiler saves a lot of time. Ties in libraries and finds them on the servers hard drive.

Steps of Compiling
	Preprocessing
		'#' is a preprocessor directive
		header files are read and "copied" into your program for use.
	Compiling
		Translation of source code to assembly code
		Computer CPU can interpret assembly code
	Assembling:
		Translation of assembly code in step 2 to machine code = 0's and 1's
	 Linking
		 Taking the machine code from the original ".c" file, the machine code from the header files, etc. and linking them together

Reverse Engineering
	Hardware (CPU) manufacturer has a a manual for their machine code "codes" and what they represent.

Arrays
	A chunk of contiguous memory and sequence of values that all have the same data type.
	Example code:
```c
#include <stdio.h>

int main(void)

{
    int score[3];

    score[0] = 72;

    score[1] = 73;

    score[2] = 33;

    printf("Average: %f\n", (score[0] + score[1] + score[2]) / 3.0);
}
```
Lets clean it up with a loop and add more with input:
```c
#include <stdio.h>
 
 float average(int length,int numbers[])
 {
	 int sum = 0;
	 for (int i = 0; i < length; i++)
	 {
		 sum += numbers[i];
	 }
	 return sum / (float) length;
 }
 
int main(void)
{
	const int N = 3;
    int score[n];
    for (int i = 0, i < n, i++)
    {
        scores[i] = get_int("Score: "):
    }
    
    printf("Average: %f\n", average(N, scores));
}
```
Note:
The constant variable N is capitalized because it is a constant

A string is just an array of characters

NUL Character
	A bite of zero bits
	Represents the end of a string

You can use `#include <string.h>` and use `strlen()` to find the length of a string.

Another library you can use for a bunch of character specific thing is `#include <ctype.h>`

`int main(void)`
	main
		The function called automatically after you compiled and run your code
	void
		Means main and all the programs written do not take command line arguments.

`int main(int argc, string argv[ ])`
	Means it can take command line arguments
	First argument would be an integer and the second would be an array of strings.
	`argc`
		Count of arguments typed after programs name
	`argv`
		Argument vector aka array of actual words
Example:
```c
#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[])
{
	if (argc == 2)
	{
	    printf("hello, %s\n", argv[1]);
	}
    else
    {
	    printf("hello, world\n");
    }
}
```

Exit status
	Numeric status that indicates success or failure
Example code with exit status:
```C
#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n")
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
```
You can run in your terminal echo $? to see the return value that the program returned

