/* This C program creates a new .wav file that contains an inverted sine wave from 'sine.wav'

To compile and run this program type:
clang Problem8.2.c -lsndfile && ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sndfile.h>

int main(){
    SNDFILE *inFile = NULL, *outFile = NULL; //Since we are reading AND writing now, we need two 'sndFile'.
    SF_INFO sfInfo; //Holds the information about the above audio file.

    memset(&sfInfo, 0, sizeof(SF_INFO)); //INITIALIZE SF_INFO

    //Open sound file 
    inFile = sf_open("sine.wav", SFM_READ, &sfInfo); //Using &sfInfo you pass the address of sfInfo, meaning the function will autopopulate the sfInfo content for us when it opens up the sine.wav. It'll figure out the sample rate, channel #, duration etc.
    if(inFile == NULL){
        printf("Failed to open sound file");
        return 1;
    }

    int bufferSize = sfInfo.frames; //Initialize BUFFER_SIZE with number of frames (samples) in sound file
    float buffer[bufferSize]; //THIS IS WHERE THE AUDIO DATA SAMPLES GETS STORED.

    //Check if file format is in good shape
    if(!sf_format_check(&sfInfo)){
        sf_close(inFile);
        printf("Invalid encoding\n");
        return 1;
    }

    outFile = sf_open("sineInverted.wav", SFM_WRITE, &sfInfo);
    if(outFile == NULL){
        printf("Could not open file...");
        printf("%s\n", sf_strerror(NULL));
        return 1;
    }

    while(sf_read_float(inFile, buffer, bufferSize) > 0){ //YOU MUST DEFINE A BUFFER TO READ CONTENT of this audio file. This line says "read this much frames from 'inFile' and store it into 'buffer'". Comparing 'readCount' to '0' is for seeing if it is bigger than '0'. We are always gonna get how many frames did 'sf_read_float' read and it'll return to this 'readCount', and constantly check as the 'while' loop runs over and over. At some point we'll reach '0' (END OF FILE!), when it's not zero, KEEP GOING! When frame count is zero, you've reached the EOF!
        for(int i = 0; i < bufferSize; i++){ //Invert audio signal
            buffer[i] = buffer[i] * -1;
        }
        sf_write_float(outFile, buffer, bufferSize); //Write it into the 'outFile', and the content is coming from 'buffer'.
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