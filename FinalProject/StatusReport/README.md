# Status Report

#### Your name

Daniel Bermudes

#### Project title

*Daniel's Csound Notelist Piece*

***

Short answers for the below questions suffice. If you want to alter your plan for your project (and obtain approval for the same), be sure to email your instructor!

#### What have you done for your project so far?

Up until now, I've been learning how to reconfigure Ben Houge's `.c` files (specifically his  `GrainGeneratorRead.c` file) to run a `.csd` file that plays a notelist piece. I have an almost 'in-time' synth arpeggiator sound generated from the `buzz` opcode in Csound that'll serve as the basis for the piece. The original `.csd` file was created to demonstate an analog-style LPF by Josep M Comajuncosas, but I also included an `lfo` opcode controlling its frequency for a more 'fatter' sound with vibrato.

#### What have you not done for your project yet?

I have not added audio effects yet, nor have I included other instruments such as bass and drums. 

#### What problems, if any, have you encountered?

No real major problems have risen thankfully! However, using the `GrainGeneratorRead.c` file still requires the user to input function tables and instrument lines individually (and with more instruments still to be put in, it will be cumbersome!) So, I've been trying to learn how to utilize his `GrainGeneratorDensity.c` that creates and defines variables as parameters to be used by the `.csd` file. It then executes the score with just one `fprintf()` function, making the entire `.c` file much more cleaner.
