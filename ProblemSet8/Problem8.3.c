/* This program does not create a proper reversed 'SN.wav' file. 
I wasn't able to execute it properly.

clang Problem8.3.c -lsndfile &&./a.out 
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sndfile.h>

const int BUFFER_SIZE = 4096; 

int main(){
    SNDFILE *inFile, *outFile; //Since we are reading AND writing, we need two 'sndFile'.
    SF_INFO sfInfo; //Holds the information about the above audio file. A struct that holds Sample Rate, # of Channels etc.

    float buffer[BUFFER_SIZE]; //THIS IS WHERE THE AUDIO DATA GETS STORED from what was initialized globally (BUFFER_SIZE).

    memset(&sfInfo, 0, sizeof(SF_INFO)); //Initialize SF_INFO

    //Open sound file 
    inFile = sf_open("SN.wav", SFM_READ, &sfInfo); //Using &sfInfo you pass the address of sfInfo, meaning the function will autopopulate the sfInfo content for us when it opens up the sine.wav.

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

    outFile = sf_open("ReverseSN.wav", SFM_WRITE, &sfInfo);

    if(outFile == NULL){
        printf("Could not open file...");
        printf("%s\n", sf_strerror(NULL));
        return 1;
    }

    int readCount = 0; //We gonna do actual reading and writing now. And keep track of how many number of frames we gonna be reading and writing from a soundfile at the same time. WE NEED TO SPECIFY AN EXACT #!
    while((readCount = sf_read_float(inFile, buffer, BUFFER_SIZE)) > 0){ //YOU MUST DEFINE A BUFFER TO READ CONTENT of this audio file. 
        printf("%d\n", readCount); //This printf() is for how many counts we are reading in each loop inside this while loop.
        sf_write_float(outFile, buffer, readCount); //Write it into the 'outFile', and the content is coming from 'buffer'...and then write 'this' much into it, which comes from readCount.
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