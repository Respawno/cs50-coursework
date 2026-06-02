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

Left off on 47:04
