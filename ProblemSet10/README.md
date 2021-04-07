### Project Name
Problem Set 10

### Submitted by
Daniel Bermudes

### For Course
EP-353

### Due Date
09:00:00 AM on 4/7/2021

### Submission Date
8:58:00 AM on 4/7/2021

### Files Included
- README.md 
- Problem10.1.c
- Problem10.2.c
- Problem10.3.c
- sine.wav
- reduct.aiff
- noisy.wav
- noisegate.wav

### Purpose
The purpose of this problem set was to create different audio processing effects within their own C program, utilizing `0.DAFxTemplate.c` as a starting point.

### Description
Problem 10.1 asked to create a tremolo effect that would modulate a sine wave, utilzing the `sin` function from the `math.h` library to generate the LFO signal.

Problem 10.2 focused on creating a noise gate effect from `noisy.wav` that would attenuate signals below a threshold of positive and negative 0.02. It was then to be saved as `noisegate.wav`.

Problem 10.3 was about implementing the bit quantization/reduction effect source code that was given to us, and processing `sine.wav` with it. This time, it was supposed to be saved as `reduct.aiff`.


### Build and Run Commands
To build Problem 10.1, use:

	clang Problem10.1.c -lsndfile

To run the compiled `Problem10.1` program, use:

	./Problem10.1
	
To build Problem 10.2, use:

	clang Problem10.2.c -lsndfile

To run the compiled `Problem10.2` program, use:

	./Problem10.2
	
To build Problem 10.3, use:

	clang Problem10.3.c -lsndfile

To run the compiled `Problem10.3` program, use:

	./Problem10.3
	
### Acknowledgements

No references utilized for this week.