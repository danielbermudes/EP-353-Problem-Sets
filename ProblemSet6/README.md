### Project Name
Problem Set 6

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 3/10/2021

### Submission Date
8:59:00 AM on 3/10/2021

### Files Included
- README.md 
- Problem6.1.c
- Problem6.2.c
- Problem6.3.c

### Purpose
The purpose of this problem set was to better understand how to utilize pointers in relationship with functions and strings, and how to use pointer arithmetic to be able to rotate an array.

### Description
Problem 6.1 asked to write a program that counted the number of characters in an array named `string` with a function named `countCharacter`, while not using `sizeof` or `strlen()`.

Problem 6.2 focused on initializing all the elements of an array named `numbers` with a size of 8 based on what the user inputed, with a function named `setArray()`.

Problem 6.3 shows how to rotate the values of an array named `numbers` based on the number of steps the user inputs into a variable named `steps`, while using a function named `rotate()`.

### Build and Run Commands
To build Problem 6.1, use:

	clang Problem6.1.c -o Problem6.1

To run the compiled `Problem6.1` program, use:

	./Problem6.1
	
To build Problem 6.2, use:

	clang Problem6.2.c -o Problem6.2

To run the compiled `Problem6.2` program, use:

	./Problem6.2

To build Problem 6.3, use:

	clang Problem6.3.c -o Problem6.3

To run the compiled `Problem6.3` program, use:

	./Problem6.3
	
### Acknowledgements
I recieved help from a peer for Problem6.2 and Problem6.3. I also used the source code here on [this forum](https://cboard.cprogramming.com/c-programming/136836-multiple-inputs-one-line.html#:~:text=So%20as%20long%20as%20you,what%20you%20wrote%20should%20work.&text=You%20can%20get%20more%20than%20one%20value%20with%20a%20single%20scanf%20statement.&text=int%20x%5B3%5D%3B%20printf,%25d%2C%20and%20%25d ) to be able to collect 5 integer values from the user to be stored into the array named `numbers` in Problem6.3. 