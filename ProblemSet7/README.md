### Project Name
Problem Set 7

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 3/17/2021

### Submission Date
9:00:00 AM on 3/17/2021

### Files Included
- README.md 
- Problem7.1.c
- Problem7.2.c

### Purpose
The purpose of this problem set was to understand the importance of memory management for alocating memory space (using `malloc`), in order to complete certain tasks in a program.

### Description
Problem 7.1 asked to create a sequencer-style program by allocating memory space for a char pointer-type variable named `sequence` that holds integer variable `numBeats` multiplied by integer variable `numPercs`.

Problem 7.2 focused on creating a struct with three `unsigned char` varibles: `pitch`, `velocity`, and `channel`. These three members would then contain values based on what the user inputted, and be printed out through a function called `printNote`.

### Build and Run Commands
To build Problem 7.1, use:

	clang Problem7.1.c -o Problem7.1

To run the compiled `Problem7.1` program, use:

	./Problem7.1
	
To build Problem 7.2, use:

	clang Problem7.2.c -o Problem7.2

To run the compiled `Problem7.2` program, use:

	./Problem7.2
	
### Acknowledgements
I referenced this [ASCII Table](https://www.techonthenet.com/ascii/chart.php) to understand how to print out non-printable characters, pressing `Cntrl` and `V` simultaneously to unlock decimal values (e.g. decimal `1` requires using char `^A`). Also, I used [this source code](https://cboard.cprogramming.com/c-programming/154145-random-number-interval-[0-1].html) to implement `rand()` and `srand()` to generate only `0` or `1`.