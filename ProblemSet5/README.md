### Project Name
Problem Set 5

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 3/3/2021

### Submission Date
4:40:00 PM on 3/2/2021

### Files Included
- README.md 
- Problem5.1.c
- Problem5.2.c
- Problem5.3.c

### Purpose
The purpose of this problem set was to understand how arrays and strings can be reversed, sorted, and iterated over to print out different outcomes using `for` loops.

### Description
Problem 5.1 showed how to print out the values of an array in reverse, while keeping each index number the same. In short, `numbers[0]` would become 3, which was originally the last value in the array.

Problem 5.2 focused on printing out the values of another array, `char pitches[]`, only this time in ascending order. I used an algorithm called bubble sort to swap elements that weren't in the right order (it was cool to learn about!)

Problem 5.3 shows how to iterate over a string entered by a user, changing lowercase letters to uppercase and vice versa in the final printout. Ended up using `fgets()` for receiving input from the user, since `scanf()` didn't take in whitespaces.

### Build and Run Commands
To build Problem 5.1, use:

	clang Problem5.1.c -o Problem5.1

To run the compiled `Problem5.1` program, use:

	./Problem5.1
	
To build Problem 5.2, use:

	clang Problem5.2.c -o Problem5.2

To run the compiled `Problem5.2` program, use:

	./Problem5.2

To build Problem 5.3, use:

	clang Problem5.3.c -o Problem5.3

To run the compiled `Problem5.3` program, use:

	./Problem5.3
	
### Acknowledgements
I used the source code here on [this website](https://www.sanfoundry.com/c-program-sort-array-ascending-order/) as a template for Problem 5.2. I only needed to exclude `scanf()` since there was already an array with assigned values. To understand a little more about the process the above link took to sort the array, I checked out [this tutorial](https://www.programiz.com/dsa/bubble-sort) that explains the algorithm called Bubble Sort. Also, I referenced the source code [here](https://www.codezclub.com/c-convert-string-lowercase-to-uppercase-or-vice-versa/) for Problem 5.3, which I also just had to format it correctly. 