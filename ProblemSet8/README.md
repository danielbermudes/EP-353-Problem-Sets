### Project Name
Problem Set 8

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 3/24/2021

### Submission Date
3:07:00 AM on 3/24/2021

### Files Included
- README.md 
- Problem8.1.c
- Problem8.2.c
- Problem8.3.c

### Purpose
The purpose of this problem set was to begin utilizing and processing audio within the C Language, using `libsndfile` in each problem.

### Description
Problem 8.1 asked to write a program that, using `sine.wav`, extended the duration of the audio file to 5 seconds.

Problem 8.2 focused on creating a program that inverted `sine.wav`, reversing its polarity.

Problem 8.3 was about creating a program that reversed the file `SN.wav`.

### Build and Run Commands
To build Problem 8.1, use:

	clang Problem8.1.c -lsndfile

To run the compiled `Problem8.1` program, use:

	./a.out
	
To build Problem 8.2, use:

	clang Problem8.2.c -lsndfile

To run the compiled `Problem8.2` program, use:

	./a.out

To build Problem 8.3, use:

	clang Problem8.3.c -lsndfile

To run the compiled `Problem8.3` program, use:

	./a.out
	
### Acknowledgements
I recieved help from a peer for Problem8.2. I also got help from another peer for Problem8.3, but I didn't manage to execute their examples properly. Thus, I also tried referencing this [website](https://stackoverflow.com/questions/6593118/how-to-reverse-an-audio-file), following user Tom Nys' example, but with no prevail.