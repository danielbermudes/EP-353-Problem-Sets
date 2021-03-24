/* This C program displays:
4096
4096
4096
4096
4096
4096
4096
4096
4096
4096
3140

The program also creates a new .wav file called 'sine5.wav'.
To compile and run this program type:
clang Problem8.1.c -lsndfile && ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <sndfile.h>

const int BUFFER_SIZE = 4096;

int main(){
    SNDFILE *inFile, *outFile; //Since we are reading AND writing now, we need two 'sndFile'.
    SF_INFO sfInfo; //Holds the information about the above audio file. We are gonna use same information from input file to write for the output file!

    float buffer[BUFFER_SIZE]; //THIS IS WHERE THE AUDIO DATA GETS STORED from what was initialized globally (BUFFER_SIZE).

    memset(&sfInfo, 0, sizeof(SF_INFO)); //INITIALIZE SF_INFO

    //Open sound file 
    inFile = sf_open("sine.wav", SFM_READ, &sfInfo); //Using &sfInfo you pass the address of sfInfo, meaning the function will autopopulate the sfInfo content for us when it opens up the sine.wav. itll figure out the sample rate, channel #, duration etc. It'll all populate into &sfInfo . That's why you pass it by refernece, and not by normal variables. 

    //check to make sure soundfile opens
    if(inFile == NULL){
        printf("Failed to open sound file");
        return 1;
    }

    //Check if file format is in good shape
    if(!sf_format_check(&sfInfo)){
        sf_close(inFile);
        printf("Invalid encoding\n");
        return 1;
    }

    outFile = sf_open("sine5.wav", SFM_WRITE, &sfInfo);

    if(outFile == NULL){
        printf("Could not open file...");
        printf("%s\n", sf_strerror(NULL));
        return 1;
    }

    int readCount = 0; //Reading and writing now. And keep track of how many number of frames we're gonna be reading and writing from a soundfile at the same time. WE NEED TO SPECIFY AN EXACT #!

    sf_seek(outFile, 190000, SEEK_END); //extending audio file duration

    while((readCount = sf_read_float(inFile, buffer, BUFFER_SIZE)) > 0){ //YOU MUST DEFINE A BUFFER TO READ CONTENT of this audio file. This line says "read this much frames from 'inFile' and store it into 'buffer'".
        printf("%d\n", readCount); //This printf() is for how many counts we are reading in each loop inside this while loop.
        sf_write_float(outFile, buffer, readCount); //Write it into the 'outFile', and the content is coming from 'buffer'...and then write "this" much into it, which comes from readCount.
    }

    if(inFile != NULL){
        sf_close(inFile);
        inFile = NULL;
    }

    if(outFile != NULL){
        sf_close(outFile);
        outFile = NULL;
    }

    return 0;
}