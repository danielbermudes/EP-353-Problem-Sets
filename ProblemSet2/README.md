### Project Name
Problem Set 2

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 2/10/2021

### Submission Date
5:01:00 PM on 2/9/2021

### Files Included
- README.md 
- Problem2.1.c
- Problem2.2.c
- Problem2.3.c

### Purpose
The purpose of this problem set was to better understand how to display integer and float type variable values using a single `printf()` function, `\n` for new lines, and `\t` for tab spaces.

### Description
Problem 2.1 explained how to print a phrase using one `printf()` function. Problem 2.2 focused on initializing integer type variables `note`, `velocity`, and `pitch` with different values, then printing them out. To format the printout exactly as the problem requested required using `\n` and `\t`. Problem 2.3 followed a similar layout as Problem 2.2, only this time initializing float type variables `frequency` and `decibel` with float values. To specify a miniumum number of digits to be written after the decimal point in this case required `.precision`.



### Build and Run Commands
To build Problem 2.1, use:

	clang Problem2.1.c -o Problem2.1

To run the compiled `Problem2.1` program, use:

	./Problem2.1
	
Note: This process also applies to building and running Problem 2.2 and Problem 2.3; simply switch the problem number itself for the desired number (2.1, 2.2, or 2.3).
	
### Acknowledgement
I used Hugo Rivera's answer on [this website](https://stackoverflow.com/questions/35121029/printf-a-float-value-with-precision-number-of-decimal-digits-passed-in-a-varia) to figure out how to exactly format `.precision` into Problem2.3.c. I initially figured out where to place `.*` inside the string. However, I couldn't find where the number indicating a minumum number of digits to be written went. 