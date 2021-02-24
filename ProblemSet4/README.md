### Project Name
Problem Set 4

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 2/24/2021

### Submission Date
8:55:00 AM on 2/24/2021

### Files Included
- README.md 
- Problem4.1.c
- Problem4.2.c
- Problem4.3.c

### Purpose
The purpose of this problem set was to understand how to open and read a text file by understanding I/O. Also, the problem set goes into detail in explaining how to create and use one's own function within a C program, and the difference betweeng global and local variables in the context of variable scope.
### Description
Problem 4.1 showed how to read the content of the included `LoremIpsum.txt` file character by character. In addition, this program also prints out the number of newlines in the file.

Problem 4.2 demonstrates how to create a new function and call it in the `main` function. This problem I was not able to execute completely; I think where I got stuck was in figuring out how to print out `Potato Cats!` for every 4 bars using some sort of looping statement.

Problem 4.3 shows the difference between global and local variables by having them print out their assigned values inside a created function called `decrement`. The global variable is assigned outside the `decrement` function, while the local varibale is assigned inside of it. I also wasn't able to execute this program accurately, but the overall layout appears correct. I wasn't sure how to have the global variable's values decrement (I thought what I had in my code would work).

### Build and Run Commands
To build Problem 4.1, use:

	clang Problem4.1.c -o Problem4.1

To run the compiled `Problem4.1` program, use:

	./Problem4.1
	
To build Problem 4.2, use:

	clang Problem4.2.c -o Problem4.2

To run the compiled `Problem4.2` program, use:

	./Problem4.2

To build Problem 4.3, use:

	clang Problem4.3.c -o Problem4.3

To run the compiled `Problem4.3` program, use:

	./Problem4.3
	
### Acknowledgement
While I referenced quite a few online resources, most of them I think confused me more because I didn't realize almost all of them were referring to other programming langauges and not C. However, [this](https://github.com/Roseburrow/Frequency-To-Closest-Midi-Note/blob/master/frequency2closestmidi.c) website simply gave me a quick refresher on looping statements, and Dan Gookin's explaination on incrementing/decrementing variables [here] (https://www.dummies.com/programming/c/incrementing-or-decrementing-a-variable-in-c-before-or-after-you-use-it/) was also referenced.