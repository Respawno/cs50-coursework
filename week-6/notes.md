Python is a lot faster coding wise but can be slower in the compiler. It can also be beginner friendly for beginners. Lets do last weeks problem set speller in python and lets see how simple it is compared to C.

```python
words = set()

def check(word):
    return word.lower() in words

def load(dictionary):
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True

def size():
    return len(words)

def unload():
    return True:
```

Remember that annoying blur problem from week 4. Well look how easy we can do the same concept in python
```python
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")
```

We can do the same with finding the edges problem
```python
from PIL import Image, ImageFilter

before = Image.open("stadium.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out2.bmp")
```

Functions
	modules, packages

Named parameters

docs.python.org

End parameters
```python
print("hello, world", end="")
```
This would be like forgetting to put \n in c at the end of your print statement:
hello, world$

```python
print(*objects, sep=' ', end='\n', file=None, flush=False)
```
 Objects
	 0 or more objects
		 Could be a number or a string
sep(Separator)
	Separators between arguments to print

Variables
	Types
		bool
		float
		int
		str

Data types
	range - sequence of numbers
	list - sequence of mutable values
	tuple - sequence of immutable values
	dict - collection of key - value pairs
	set - collection of unique values

Change counter by 1
	`counter += 1`

```python
# Addition with int

x = input("x: ")

y = input("y: ")

print(x + y)
```
The output would be the numbers combined not added
So I put 5 for x and 2 for y the output would be 52.
So how do we do addition?
```python
# Addition with int

x = input("x: ")

y = input("y: ")

print(int(x) + int(y))
```

You could also do it like such
```python
# Addition with int

x = int(input("x: "))

y = int(input("y: "))

print(x + y)
```
Both would give you addition to your output and give you the results you wanted.

Conditionals
```python
if x < y:
    print("x is less than y")
```
Example of a conditional in python and notice the differences from when we were using them in C.

Compare.py
```python
x = int(input("What's x: "))
y = int(input("What's y: "))

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

Also remember in C when we would use strcmp to compare two strings together to see if the are equal. Look how easy we can do that in python:
```python
s = input("s: ")
t = input("t: ")

if s == t:
    print("same")
else:
    print("different")
```

Using or for our conditionals
```python
s = input("Do you agree? ")

if s == "Y" or s == "y":
    print("Agreed")
else:
    print("Disagre")
```

Lists
	Linked list in python
```python
s = input("Do you agree? ")

if s in ["y", "yes"]:
    print("Agreed")
else:
    print("Disagre")
```
We can use the in operator to have a conditional for the list of strings we provided.
But now we have ran into a bug. What happens if a user enters the input "YES". It would be declined and follow the else statement because it is case sensitive. Lets fix that:
```python
s = input("Do you agree? ")

s = s.lower()

if s in ["y", "yes"]:
    print("Agreed")
else:
    print("Disagre")
```

You can also chain the first line together with .lower()
```python
s = input("Do you agree? ").lower()

if s in ["y", "yes"]:
    print("Agreed")
else:
    print("Disagre")
```
This is also known as object-oriented programming

```python
s = input("s: ")

t = s.capitalize()

print(f"s: {s}")
print(f"t: {t}")
```
s would print it's original output and t would print a copy of that input and output it as capitalized. 

```python
i = 0
while i < 3:
    print("meow")
    i += 1
```
This will print meow three times
Another and easier way to write this:
```python
for i in [0, 1, 2]:
    print("meow")
```
