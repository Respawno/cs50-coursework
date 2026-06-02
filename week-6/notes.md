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
