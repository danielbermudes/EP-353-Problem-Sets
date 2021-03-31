### Project Name
Problem Set 9

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 3/31/2021

### Submission Date
8:50:00 AM on 3/31/2021

### Files Included
- README.md 
- Problem9.1.c
- Problem9.2.c
- sine.wav
- triangle.wav
- enveloped.wav

### Purpose
The purpose of this problem set was to learn more about how to generate different waveforms, as well as process waveforms with a simple envelope.

### Description
Problem 9.1 asked to create a program that would generate a triangle wave, and write the result out as `triangle.wav`.

Problem 9.2 focused on applying a linear Attack/Decay envelope to `sine.wav` utilizing linear interpolation, and its equation being: `y0 + (x - x0) * ((y1 - y0) / (x1 - x0))` It then asked to write the result out as `enveloped.wav`. But, I didn't successfully create this program.


### Build and Run Commands
To build Problem 9.1, use:

	clang Problem9.1.c -lsndfile

To run the compiled `Problem9.1` program, use:

	./a.out
	
To build Problem 9.2, use:

	clang Problem9.2.c -lsndfile

To run the compiled `Problem9.2` program, use:

	./a.out
	
### Acknowledgements
I referenced *The Audio Programming in C* book by Richard Boulanger and Victor Lazzarini in creating a triangle equation for Problem9.1, as well as [Wikipedia](https://en.wikipedia.org/wiki/Triangle_wave).