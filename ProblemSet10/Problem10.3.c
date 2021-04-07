#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//Compile & Run with:
//clang Problem10.3.c -o Problem10.3 -lsndfile && ./Problem10.3

#define kInputFileName "sine.wav"
#define kOutputFileName "reduct.aiff"

//Hold SNDFILE and SF_INFO together
typedef struct SoundFile {
  SNDFILE *file;
  SF_INFO info;
} SoundFile;

//Function prototypes
int openInputSndFile(SoundFile *inFile);
int createOutputSndFile(SoundFile *inFile, SoundFile *outFile);
void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize);

// Bit Quantization/Reduction Effect
//short keep_bits_from_16(short input, int keepBits);
short keep_bits_from_16(short input, int keepBits) {
  return (input & (-1 << (16-keepBits)));
}

//Global Variables
int keepBits = 8;

int main(void){
  SoundFile inFile, outFile;
  
  // Open input file and create output file
  int error = openInputSndFile(&inFile);
  if(error) return 1;

  // Get buffer size
  sf_count_t bufferSize = inFile.info.frames;

  // Allocate buffers for sound processing
  short *inBuffer = (short *) malloc(bufferSize*sizeof(short));
  short *outBuffer = (short *) calloc(bufferSize,sizeof(short));

  // Copy content the file content to the buffer
  sf_read_short(inFile.file, inBuffer, bufferSize);

  
  // Process inBuffer and copy the result to outBuffer
  process(inBuffer, outBuffer, bufferSize);
  
  // Create output file and write the result
  error = createOutputSndFile(&inFile, &outFile);
  if(error) return 1;
  sf_write_short(outFile.file, outBuffer, bufferSize);
  
  // Clean up
  sf_close(inFile.file);
  sf_close(outFile.file);
  free(inBuffer);
  free(outBuffer);
  
  return 0;
}

//TODO: Implement your DSP here
void process(short *inBuffer, short *outBuffer, sf_count_t bufferSize){
  for(sf_count_t n = 0; n < bufferSize; n++){
    outBuffer[n] = inBuffer[n]; //Copy input to output

    keep_bits_from_16(inBuffer[n], keepBits);

    return;

    //keep_bits_from_16(inBuffer[n], (-1 << (16-keepBits)));
    
  }
}
int openInputSndFile(SoundFile *sndFile){
  //Initialize SF_INFO with 0s (Required for reading)
  memset(&sndFile->info, 0, sizeof(SF_INFO));

  //Open the original sound file as read mode
  sndFile->file = sf_open(kInputFileName, SFM_READ, &sndFile->info);
  if(!sndFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kInputFileName);
		puts(sf_strerror(NULL));
		return 1;
  }

  //Check if the file format is in good shape
  if(!sf_format_check(&sndFile->info)){	
    sf_close(sndFile->file);
		printf("Invalid encoding\n");
		return 1;
	}

  //Check if the file is mono
  if(sndFile->info.channels > 1){
    printf("Input file is not mono\n");
    return 1;
  }

  //print out information about opened sound file
  printf("Sample rate for this file is %d\n", sndFile->info.samplerate);
	printf("A number of channels in this file is %d\n", sndFile->info.channels);
  printf("A number of frames in this file is %lld\n", sndFile->info.frames);
  printf("time is %f\n", (double)sndFile->info.frames / sndFile->info.samplerate);

  return 0;
}

int createOutputSndFile(SoundFile *inFile, SoundFile *outFile){
  //Open another sound file in write mode
  outFile->file = sf_open(kOutputFileName, SFM_WRITE, &inFile->info);
  if(!outFile->file){//Check if the file was succefully opened
    printf("Error : could not open file : %s\n", kOutputFileName);
		puts(sf_strerror(NULL));
		return 1;
	}
  return 0;
}