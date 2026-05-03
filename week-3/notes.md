Algorithm
	Step by step instructions to solve a problem

Arrays
	Arrays under the hood inside of computer hold memory. You could think of when the computer goes and looks for those memory chunks it is like all doors are closed.
		Can't just have a bird's eye view of everything
	In its simplest form it can only look at one value/one chunk of memory at a time.

Pseudocode examples:
```
For each door from left to right
	If 50 is behind door
		Return true
Return false
```
Computer scientist translation:
```
For i from 0 to n-1
	If 50 is behind door[i]
		Return true
Return false
```

Common running times:
- 𝑂⁡(𝑛2)
- 𝑂⁡(𝑛⁢log⁡𝑛)
- 𝑂⁡(𝑛)
- 𝑂⁡(log⁡𝑛)
- 𝑂⁡(1)
