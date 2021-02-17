### Project Name
Problem Set 3

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 2/17/2021

### Submission Date
7:20:00 PM on 2/16/2021

### Files Included
- README.md 
- Problem3.1.c
- Problem3.2.c
- Problem3.3.c

### Purpose
The purpose of this problem set was to better understand how operators can drive values or variables in conditional statements and looping statements. The relationship between conditional and looping statements is also explored, and how conditional statements can make decisions, and looping statements repeatedly execute a block of statements while a condition is true.

### Description
Problem 3.1 showed how to print out a MIDI note number and its corresponding frequency value. Using the `pow()` function from `math.h`, the program implemented an equation used to convert any given MIDI note to its corresponding frequency.

Problem 3.2 focused on translating any musical note between `'C'` and `'B'` into pitch classes (0 ~ 11) using the `switch` statement, with `'C'` being 0 and `'B'` being 11. Musical notes with `♯` and `♭` were disregarded in this problem.

Problem 3.3 explains how to print out all musical notes in an octave in descending steps using `for` loop, starting from 11 (`'Bb'`) and finishing at 0 (`'C'`). However, in order to print musical notes and not pitch classes, the `switch` statement is used to convert pitch class into notes.

### Build and Run Commands
To build Problem 3.1, first type in a single character to assign to `midiNote` (e.g.`'E'`). Then, use:

	clang Problem3.1.c -o Problem3.1

To run the compiled `Problem3.1` program, use:

	./Problem3.1
	
To build Problem 3.2, first type in a single character to assign to `note` between musical notes `C` and `B`. Then, use:

	clang Problem3.2.c -o Problem3.2

To run the compiled `Problem3.2` program, use:

	./Problem3.2

To build Problem 3.3, use:

	clang Problem3.3.c -o Problem3.3

To run the compiled `Problem3.3` program, use:

	./Problem3.3
	
### Acknowledgement
I referenced Roseburrow's code here on [GitHub](https://github.com/Roseburrow/Frequency-To-Closest-Midi-Note/blob/master/frequency2closestmidi.c). To be sincere, I can't recall the purpose of referencing it, but it did help clarify something in one problem.