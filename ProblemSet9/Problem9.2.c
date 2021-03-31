/* This C program is supposed to create a new .wav file called 'enveloped.wav'.

To compile and run this program type:
clang Problem9.2.c -lsndfile && ./a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <sndfile.h>

const int BUFFER_SIZE = 4096; //THINK OF THIS LIKE THE HEADER IN CSOUND! This number can be anything, but just keep it to the power of 2

int main(){
    SNDFILE *inFile, *outFile; //Since we are reading AND writing now, we need two 'sndFile'. NULL is optional, since it is arleady default.
    SF_INFO sfInfo; //Holds the information about the above audio file. We are gonna use same information from input file to write for the output file!

    float *buffer; //THIS IS WHERE THE AUDIO DATA GETS STORED from what was initialized globally (BUFFER_SIZE)...temporarily. This is an array/buffer....
    long bufferSize = 0;

    //INITIALIZE SF_INFO
    memset(&sfInfo, 0, sizeof(SF_INFO));

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
// ___________________________________________________________________________________________
    buffer = (float *) malloc(sfInfo.frames * sizeof(float));
    bufferSize = sfInfo.frames;

    outFile = sf_open("enveloped.wav", SFM_WRITE, &sfInfo);

    if(outFile == NULL){
        printf("Could not open file...");
        printf("%s\n", sf_strerror(NULL));
        return 1;
    }

    float y0 = 0;
    float y1 = 0.1;
    float x = bufferSize;
    float x0 = 1;
    float x1 = 4096;

    float linearInt = y0 + (x - x0) * ((y1 - y0)) / (x1 - x0);

    sf_read_float(inFile, buffer, bufferSize); //This repaces 'while' loop that was used to read chunks. This 'buffer' is as long as the actual audio frames in the actual sound file. Then say it has a 'bufferSize'.
    sf_write_float(outFile, buffer, bufferSize * linearInt);
// __________________________________________________________________________________________
    if(inFile != NULL){
        sf_close(inFile);
        inFile = NULL;
    }

    if(outFile != NULL){
        sf_close(outFile);
        outFile = NULL;
    }

    free(buffer);
    
    return 0;
}

// clang Problem9.2.c -lsndfile && ./a.out