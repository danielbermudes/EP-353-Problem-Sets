#include <stdio.h>
#include <stdlib.h>

//To compile and run: gcc -o DBScore DBScore.c && ./DBScore

int main() {
	FILE *csd;
	csd = fopen("DBScore.csd", "w"); //Opens the .csd file, begins to write

	fprintf(csd, "<CsoundSynthesizer>\n"); //Writes these headers out to the .csd file
	fprintf(csd, "<CsInstruments>\n");

	FILE *orc;
	orc = fopen("DBScore.orc", "r"); //Opens the .orc containing just the orchestra portion of the .csd file.
	if (orc == NULL) {
		printf("can't open file\n"); //Checks if file is corrupt
		return 1;
	} else {
		int c;
		//the following works because an assignment expression has the value of the left operand after the assignment
		while((c = getc(orc)) != EOF) {
			putc(c, csd);
		}
		fclose(orc);
	}

	fprintf(csd, "\n</CsInstruments>\n"); //Starting from here, the fprintf() functions write ALL these out to the .csd file
	fprintf(csd, "<CsScore>\n");

	//All the function tables utilized
	fprintf(csd, "f1 0 8192 10 1\n");
	fprintf(csd, "f2 0 65536 10 1\n");
	fprintf(csd, "f3 0 65536 19 .5 1 270 1\n");
	fprintf(csd, "f 1 0 262144 10 1\n");
	fprintf(csd, "f 100 0 16385 -8	-1.0 2048 -1.0 4096 -0.7 1536 -0.05 1024 0.05 \
			1536 0.7 4096 1.0 2049 1.0\n");
	fprintf(csd, "f 11 0 512 9 1 1 0\n");
	fprintf(csd, "f 12 0 512 5 4096 512 1\n");
	fprintf(csd, "f 13 0 512 9 10 1 0 16 1.5 0 22 2 0 23 1.5 0\n");
	fprintf(csd, "f 14 0 512 9 1 1 0\n");
	fprintf(csd, "f 18 0 512 5 256 512 1\n");

	//Tempo = 128 BPM
	fprintf(csd, "t 0 128\n");

	//Distortion for Kick
	fprintf(csd, "i 90	0.0000	34.000\n");
	
	//Clean Kick
	fprintf(csd, "i 1	0.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	1.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	2.0150	1.0000	31	127\n");
	fprintf(csd, "i 1	3.0150	1.0000	31	120\n");
	fprintf(csd, "i 1	4.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	5.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	6.0150	1.0000	31	124\n");
	fprintf(csd, "i 1	7.0150	1.0000	31	120\n");
	fprintf(csd, "i 1	8.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	9.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	10.015	1.0000	31	127\n");
	fprintf(csd, "i 1	11.015	1.0000	31	120\n");
	fprintf(csd, "i 1	12.000	1.0000	31	124\n");
	fprintf(csd, "i 1	13.010	1.0000	31	120\n");
	fprintf(csd, "i 1	14.015	0.7500	31	124\n");
	fprintf(csd, "i 1	14.765	0.2000	31	122\n");
	fprintf(csd, "i 1	15.015	0.4000	31	124\n");
	fprintf(csd, "i 1	15.515	0.4000	31	126\n");
	fprintf(csd, "i 1	16.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	17.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	18.0150	1.0000	31	127\n");
	fprintf(csd, "i 1	19.0150	1.0000	31	120\n");
	fprintf(csd, "i 1	20.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	21.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	22.0150	1.0000	31	124\n");
	fprintf(csd, "i 1	23.0150	1.0000	31	120\n");
	fprintf(csd, "i 1	24.0000	1.0000	31	124\n");
	fprintf(csd, "i 1	25.0100	1.0000	31	120\n");
	fprintf(csd, "i 1	26.015	1.0000	31	127\n");
	fprintf(csd, "i 1	27.015	1.0000	31	120\n");
	fprintf(csd, "i 1	28.000	1.0000	31	124\n");
	fprintf(csd, "i 1	29.010	1.0000	31	120\n");
	fprintf(csd, "i 1	30.015	0.7500	31	124\n");

	//Global reverb instrument
	fprintf(csd, "i199	0	36	 2	.9\n");

	//That "deadmau5" pluck
	fprintf(csd, "i2  0       1     .09     48    .7\n");
	fprintf(csd, "i2  0.25    1     .3      36\n");
	fprintf(csd, "i2  0.5    .8     .5      55\n");
	fprintf(csd, "i2  0.75    1     .3      48\n");
	fprintf(csd, "i2  1       1     .5      36\n");
	fprintf(csd, "i2  1.25    1     .3      60\n");
	fprintf(csd, "i2  1.5    .8     .65     51\n");
	fprintf(csd, "i2  1.75  1.1     .5      36\n");
	fprintf(csd, "i2  2       1     .09     48\n");
	fprintf(csd, "i2  2.25    1     .3      36\n");
	fprintf(csd, "i2  2.5    .8     .3      55\n");
	fprintf(csd, "i2  2.75    1     .65     48\n");	
	fprintf(csd, "i2  3       1     .5      36\n");
	fprintf(csd, "i2  3.25    1     .3      60\n");
	fprintf(csd, "i2  3.5    .8     .65     51\n");
	fprintf(csd, "i2  3.75  1.1     .5      36\n");	
	fprintf(csd, "i2  4       1     .09     48\n");	
	fprintf(csd, "i2  4.25    1     .3      36\n");	
	fprintf(csd, "i2  4.5    .8     .3      55\n");
	fprintf(csd, "i2  4.75    1     .65     48\n");
	fprintf(csd, "i2  5       1     .5      36\n");
	fprintf(csd, "i2  5.25    1     .3      60\n");
	fprintf(csd, "i2  5.5    .8     .65     51\n");
	fprintf(csd, "i2  5.75  1.1     .5      36\n");	
	fprintf(csd, "i2  6       1     .09     48\n");	
	fprintf(csd, "i2  6.25    1     .3      36\n");
	fprintf(csd, "i2  6.5    .8     .3      55\n");	
	fprintf(csd, "i2  6.75    1     .65     48\n");				
	fprintf(csd, "i2  7       1     .5      36\n");
	fprintf(csd, "i2  7.25    1     .3      60\n");
	fprintf(csd, "i2  7.5    .8     .65     51\n");	
	fprintf(csd, "i2  7.75  1.1     .5      36\n");		
	fprintf(csd, "i2  8       1     .09     44\n");
	fprintf(csd, "i2  8.25    1     .3      32\n");
	fprintf(csd, "i2  8.50   .8     .5      51\n");
	fprintf(csd, "i2  8.75    1     .3      44\n");
	fprintf(csd, "i2  9       1     .5      32\n");
	fprintf(csd, "i2  9.25    1     .3      56\n");
	fprintf(csd, "i2  9.50   .8     .65     48\n");
	fprintf(csd, "i2  9.75  1.1     .5      32\n");
	fprintf(csd, "i2  10      1     .09     44\n");
	fprintf(csd, "i2  10.25    1     .3      32\n");
	fprintf(csd, "i2  10.50   .8     .5      51\n");
	fprintf(csd, "i2  10.75    1     .3      44\n");	
	fprintf(csd, "i2  11       1     .5      32\n");
	fprintf(csd, "i2  11.25    1     .3      56\n");
	fprintf(csd, "i2  11.50   .8     .65     48\n");
	fprintf(csd, "i2  11.75  1.1     .5      32\n");	
	fprintf(csd, "i2  12       1     .09     44\n");	
	fprintf(csd, "i2  12.25    1     .3      32\n");	
	fprintf(csd, "i2  12.50   .8     .5      51\n");
	fprintf(csd, "i2  12.75    1     .3      44\n");
	fprintf(csd, "i2  13       1     .5      32\n");
	fprintf(csd, "i2  13.25    1     .3      56\n");
	fprintf(csd, "i2  13.50   .8     .65     48\n");
	fprintf(csd, "i2  13.75  1.1     .5      32\n");	
	fprintf(csd, "i2  14       1     .09     44\n");	
	fprintf(csd, "i2  14.25    1     .3      32\n");
	fprintf(csd, "i2  14.50   .8     .5      51\n");	
	fprintf(csd, "i2  14.75    1     .7      44\n");				
	fprintf(csd, "i2  15       1     .9      32\n");
	fprintf(csd, "i2  15.25    1    1.1      56\n");
	fprintf(csd, "i2  15.50   .8    1.3      48\n");	
	fprintf(csd, "i2  15.75  1.1    1.5      32\n");
	fprintf(csd, "i2  16       1     .09     46\n");
	fprintf(csd, "i2  16.25    1     .3      34\n");
	fprintf(csd, "i2  16.50   .8     .5      53\n");
	fprintf(csd, "i2  16.75    1     .3      46\n");
	fprintf(csd, "i2  17       1     .5      34\n");
	fprintf(csd, "i2  17.25    1     .3      58\n");
	fprintf(csd, "i2  17.50   .8     .65     50\n");
	fprintf(csd, "i2  17.75  1.1     .5      34\n");
	fprintf(csd, "i2  18       1     .09     46\n");
	fprintf(csd, "i2  18.25    1     .3      34\n");
	fprintf(csd, "i2  18.50   .8     .5      53\n");
	fprintf(csd, "i2  18.75    1     .3      46\n");	
	fprintf(csd, "i2  19       1     .5      34\n");
	fprintf(csd, "i2  19.25    1     .3      58\n");
	fprintf(csd, "i2  19.50   .8     .65     50\n");
	fprintf(csd, "i2  19.75  1.1     .5      34\n");	
	fprintf(csd, "i2  20       1     .09     46\n");	
	fprintf(csd, "i2  20.25    1     .3      34\n");	
	fprintf(csd, "i2  20.50   .8     .5      53\n");
	fprintf(csd, "i2  20.75    1     .3      46\n");
	fprintf(csd, "i2  21       1     .5      34\n");
	fprintf(csd, "i2  21.25    1     .3      58\n");
	fprintf(csd, "i2  21.50   .8     .65     50\n");
	fprintf(csd, "i2  21.75  1.1     .5      34\n");	
	fprintf(csd, "i2  22       1     .09     46\n");	
	fprintf(csd, "i2  22.25    1     .3      34\n");
	fprintf(csd, "i2  22.50   .8     .5      53\n");	
	fprintf(csd, "i2  22.75    1     .3      46\n");				
	fprintf(csd, "i2  23       1     .5      34\n");
	fprintf(csd, "i2  23.25    1     .3      58\n");
	fprintf(csd, "i2  23.50   .8     .65     50\n");	
	fprintf(csd, "i2  23.75  1.1     .5      34\n");
	fprintf(csd, "i2  24       1     .09     41\n");
	fprintf(csd, "i2  24.25    1     .3      29\n");
	fprintf(csd, "i2  24.5    .8     .5      48\n");
	fprintf(csd, "i2  24.75    1     .3      41\n");
	fprintf(csd, "i2  25       1     .5      29\n");
	fprintf(csd, "i2  25.25    1     .3      53\n");
	fprintf(csd, "i2  25.5    .8     .65     44\n");
	fprintf(csd, "i2  25.75  1.1     .5      29\n");
	fprintf(csd, "i2  26       1     .09     41\n");
	fprintf(csd, "i2  26.25    1     .3      29\n");
	fprintf(csd, "i2  26.5    .8     .5      48\n");
	fprintf(csd, "i2  26.75    1     .3      41\n");	
	fprintf(csd, "i2  27       1     .5      29\n");
	fprintf(csd, "i2  27.25    1     .3      53\n");
	fprintf(csd, "i2  27.5    .8     .65     44 \n");
	fprintf(csd, "i2  27.75  1.1     .5      29\n");	
	fprintf(csd, "i2  28       1     .09     41\n");	
	fprintf(csd, "i2  28.25    1     .1      29\n");	
	fprintf(csd, "i2  28.5    .8     .2      48\n");
	fprintf(csd, "i2  28.75    1     .3      41\n");
	fprintf(csd, "i2  29       1     .4      29\n");
	fprintf(csd, "i2  29.25    1     .5      53\n");
	fprintf(csd, "i2  29.5    .8     .6      44\n");
	fprintf(csd, "i2  29.75  1.1     .7      29\n");	
	fprintf(csd, "i2  30       1     .8      41\n");	
	fprintf(csd, "i2  30.25    1     .9      29\n");
	fprintf(csd, "i2  30.5    .8     1       48\n");	
	fprintf(csd, "i2  30.75    1    1.1      41\n");				
	fprintf(csd, "i2  31       1    1.2      29\n");
	fprintf(csd, "i2  31.25    1    1.3      53\n");
	fprintf(csd, "i2  31.5    .8    1.4      44\n");	
	fprintf(csd, "i2  31.75  1.1    1.5      29\n");

	//Snare
	fprintf(csd, "i4 1.000 1.000 200 6000\n");
	fprintf(csd, "i4 3.000 1.000 200 6000\n");
	fprintf(csd, "i4 5.000 1.000 200 6000\n");
	fprintf(csd, "i4 7.000 1.000 200 6000\n");
	fprintf(csd, "i4 9.000 1.000 200 6000\n");
	fprintf(csd, "i4 11.000 1.000 200 6000\n");
	fprintf(csd, "i4 13.000 1.000 200 6000\n");
	fprintf(csd, "i4 15.000 1.000 200 6000\n");
	fprintf(csd, "i4 17.000 1.000 200 6000\n");
	fprintf(csd, "i4 19.000 1.000 200 6000\n");
	fprintf(csd, "i4 21.000 1.000 200 6000\n");
	fprintf(csd, "i4 23.000 1.000 200 6000\n");
	fprintf(csd, "i4 25.000 1.000 200 6000\n");
	fprintf(csd, "i4 27.000 1.000 200 6000\n");
	fprintf(csd, "i4 29.000 1.000 200 6000\n");
	fprintf(csd, "i4 31.000 1.000 200 6000\n");

	//Splash Synth
	fprintf(csd, "i3   0   16   90   6.00    8   5   .4\n");
	fprintf(csd, "i3  16   30   90   7.00    8   5   .4\n");
	
	fprintf(csd, "</CsScore>\n");
	fprintf(csd, "</CsoundSynthesizer>\n");
	fprintf(csd, "\n");

	fclose(csd);

	system("csound DBScore.csd -odac"); //Outputs sound

	return 0;	
}