<CsoundSynthesizer>
<CsInstruments>
sr        =         44100
kr        =         44100
ksmps     =         1
nchnls    =         2 ;STEREO!

ga0x	init  0		;Global Distortion (for the Kick)
garvb	init  0      ;Global Reverb (for the "deadmau5" Pluck)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;THE "deadmau5" PLUCK
		instr 2

ibound    =         10000
imaxamp   =         10000
irvbsnd   =           p6
kfreq     = 			cpsmidinn(p5)			

		kcps  = 30
		itype = 0	;sine wave for LFO
		klfo line 0, p3, 20
alfo   lfo klfo, kcps, itype
kamp      linen     1,.01,p3,.1
apulse1   buzz      kamp, kfreq+alfo, ibound/kfreq, 1
asaw      filter2   apulse1, 1, 1, 1, -.99

; THE FILTER ITSELF
i2pidsr   =         2*3.14159265359 / sr

; FREQ. CUTOFF
kfco      expseg    20, .01, 5000, p3-.2, 20   
;Changed 2nd argument which initailly had '.2' to '.01' for sharper transient

kfcon     =         kfco*i2pidsr
kfc       =         2*sin(kfcon/2)

; Q (RESONANCE) : STABILITY GUARANTEED FOR KQC IN [0,1]
; THOUGH YOU CAN TRY TO GO FURTHER (>1) AT YOUR OWN RISK
kqc       =         p4

ay4       init      0
ay5       init      0
ay7       init      0
ay8       init      0

ax        =         asaw/2
ay1       =         ax - ay5 - ay7
ay2       =         kfc*ay1
ay3       =         ay2+ay4
ay4       delay1    ay3
ay5       =         ay4*kqc
ay6       =         ay5*kfc
ay7       =         ay6+ay8
ay8       delay1    ay7


ay14      init      0
ay15      init      0
ay17      init      0
ay18      init      0

ax2       =         ay8
ay11      =         ax2 - ay15 - ay17
ay12      =         kfc*ay11
ay13      =         ay2+ay14
ay14      delay1    ay13
ay15      =         ay14*kqc
ay16      =         ay15*kfc
ay17      =         ay16+ay18
ay18      delay1    ay17
ay19      =         ay18*2

         outs       tanh(ay19)*imaxamp, tanh(ay19)*imaxamp
         garvb	 =		garvb+((tanh(ay19)*imaxamp)*irvbsnd)
          endin
          
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;          
;SPLASH SYNTH		
		instr 3
iamp		=		ampdb(p4)/2				
inote	=		cpspch(p5)
ibal		=		p8 
if2		=		0
if3		=		0	
ind1		=		35
ind2		=		30
k1		linseg	0,p3/2,iamp,p3/2, 0
a3		pluck	k1,inote*.997,ind1,if2,1		
a2		pluck	k1,inote*1.003,ind1,if2,1				
aplk1	=		a2+a3

k2 		linseg	0,p3*.66,iamp*1.2,p3/3,0
a6		pluck	k2,inote*.995,ind2,if3,1		
a5		pluck	k2,inote*1.005,ind2,if3,1						
aplk2	=		a5+a6
apluck	=		aplk1+aplk2
		outs		apluck*ibal,apluck*(1-ibal)
		
		endin
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;KICK
	instr 1

/* ------------------------------------------------------------------------- */

ibpm	=	140.000			/* tempo			*/
ivol	=	0.3			/* volume			*/
irel	=	0.05			/* release time			*/
ifmax	=	5.3333			/* max. frequency / note frq.	*/
ifdec	=	12			/* frequency decay speed	*/
ifmax2	=	4			/* max. frequency 2 / note frq.	*/
ifdec2	=	1024			/* frequency 2 decay speed	*/
iamax	=	0.5			/* start amplitude		*/
iadec	=	16			/* amplitude -> 1.0 speed	*/
iamax2	=	-4			/* start amp. 2			*/
iadec2	=	1024			/* amp2 -> 1.0 speed		*/
iLP1f	=	2			/* LP flt. 1 start f. / osc. f.	*/
iLP1fd	=	6			/* LP filter 1 frq. decay speed	*/
iHPxf	=	1.5			/* output HP flt. f. / note f.	*/
iHPxq	=	1.5			/* output resonant HP filter Q	*/

/* ------------------------------------------------------------------------- */

icps	=  440.0*exp(log(2.0)*(p4-69.0)/12.0)
iamp	=  0.0039+p5*p5/16192
p3	=  p3+irel+0.05

ibtime	=  60/ibpm				/* convert parameters */
iHPxf	=  iHPxf*icps

iSCALE0	=  sr/(10*3.141593)		/* scale for BUZZ oscillators */

/* -------- ENVELOPES -------- */

kfrq	port 1,ibtime/ifdec,ifmax		/* base freq. envelope */
kfrq_	port 1,ibtime/ifdec2,ifmax2
kfrq	=  kfrq*kfrq_*icps
kamp1	linseg 1,p3-(irel+0.05),1,irel,0,1,0	/* amp. envelope 1 */
kamp	expon 1,ibtime/iadec,0.5		/* amp. envelopes */
kamp2	expon 1,ibtime/iadec2,0.5
kamp	=  iamp*kamp1*(kamp*(iamax-1)+1)*(kamp2*(iamax2-1)+1)

kffrq1	port 0,ibtime/iLP1fd,iLP1f		/* lowpass 1 freq. envelope */
kffrq1	=  kffrq1*kfrq

/* -------- OSCILLATOR -------- */

k_nh_	=  int(sr/(2*kfrq))
a_1_	buzz iSCALE0,kfrq,k_nh_,1,0
a_2_	buzz iSCALE0,kfrq,k_nh_,1,0.5
aosc0	tone a_1_-a_2_,10

/* -------- FILTERS -------- */

a1	butterlp aosc0,kffrq1		/* lowpass 1 */

a1	pareq a1,iHPxf,iHPxq*2,iHPxq,0	/* resonant HP */
a_	tone a1,iHPxf
a1	=  a1-a_
a_	tone a1,iHPxf
a1	=  a1-a_

/* -------- OUTPUT -------- */

ga0x	=  ga0x+(kamp*ivol*(1.0*a1))

	endin

	instr 90

a0x	table3 ga0x/2.80,100,1,0.5,0	/* distortion table */
ga0x	=  0

	outs a0x*30000, a0x*30000

	endin		
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;SNARE
          instr 4
i1        =         p5*.3
i2        =         p4*.1
i3        =         1/p3
i4        =         p5*.8
i5        =         4

a1        randi     p5,4000
a1        oscil     a1,i3,12
a1        oscil     a1,3000,11

a2        oscil     i1,i3,12
a2        oscil     a2,i2,13

a3        oscil     i4,i3,18
a3        oscil     a3,i5,14

          outs       (a1+a2+a3)*2.3, (a1+a2+a3)*2.3

          endin	
          
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;REVERB
		instr 	199
idur	=		p3					
irvbtim=		p4
ihiatn	=		p5
arvb, arvb	freeverb	garvb, garvb, 0.7, 0.3
		outs		arvb, arvb
garvb	=		0
		endin
</CsInstruments>
<CsScore>
f1 0 8192 10 1
f2 0 65536 10 1
f3 0 65536 19 .5 1 270 1
f 1 0 262144 10 1
f 100 0 16385 -8	-1.0 2048 -1.0 4096 -0.7 1536 -0.05 1024 0.05 			1536 0.7 4096 1.0 2049 1.0
f 11 0 512 9 1 1 0
f 12 0 512 5 4096 512 1
f 13 0 512 9 10 1 0 16 1.5 0 22 2 0 23 1.5 0
f 14 0 512 9 1 1 0
f 18 0 512 5 256 512 1
t 0 128
i 90	0.0000	34.000
i 1	0.0000	1.0000	31	124
i 1	1.0100	1.0000	31	120
i 1	2.0150	1.0000	31	127
i 1	3.0150	1.0000	31	120
i 1	4.0000	1.0000	31	124
i 1	5.0100	1.0000	31	120
i 1	6.0150	1.0000	31	124
i 1	7.0150	1.0000	31	120
i 1	8.0000	1.0000	31	124
i 1	9.0100	1.0000	31	120
i 1	10.015	1.0000	31	127
i 1	11.015	1.0000	31	120
i 1	12.000	1.0000	31	124
i 1	13.010	1.0000	31	120
i 1	14.015	0.7500	31	124
i 1	14.765	0.2000	31	122
i 1	15.015	0.4000	31	124
i 1	15.515	0.4000	31	126
i 1	16.0000	1.0000	31	124
i 1	17.0100	1.0000	31	120
i 1	18.0150	1.0000	31	127
i 1	19.0150	1.0000	31	120
i 1	20.0000	1.0000	31	124
i 1	21.0100	1.0000	31	120
i 1	22.0150	1.0000	31	124
i 1	23.0150	1.0000	31	120
i 1	24.0000	1.0000	31	124
i 1	25.0100	1.0000	31	120
i 1	26.015	1.0000	31	127
i 1	27.015	1.0000	31	120
i 1	28.000	1.0000	31	124
i 1	29.010	1.0000	31	120
i 1	30.015	0.7500	31	124
i199	0	36	 2	.9
i2  0       1     .09     48    .7
i2  0.25    1     .3      36
i2  0.5    .8     .5      55
i2  0.75    1     .3      48
i2  1       1     .5      36
i2  1.25    1     .3      60
i2  1.5    .8     .65     51
i2  1.75  1.1     .5      36
i2  2       1     .09     48
i2  2.25    1     .3      36
i2  2.5    .8     .3      55
i2  2.75    1     .65     48
i2  3       1     .5      36
i2  3.25    1     .3      60
i2  3.5    .8     .65     51
i2  3.75  1.1     .5      36
i2  4       1     .09     48
i2  4.25    1     .3      36
i2  4.5    .8     .3      55
i2  4.75    1     .65     48
i2  5       1     .5      36
i2  5.25    1     .3      60
i2  5.5    .8     .65     51
i2  5.75  1.1     .5      36
i2  6       1     .09     48
i2  6.25    1     .3      36
i2  6.5    .8     .3      55
i2  6.75    1     .65     48
i2  7       1     .5      36
i2  7.25    1     .3      60
i2  7.5    .8     .65     51
i2  7.75  1.1     .5      36
i2  8       1     .09     44
i2  8.25    1     .3      32
i2  8.50   .8     .5      51
i2  8.75    1     .3      44
i2  9       1     .5      32
i2  9.25    1     .3      56
i2  9.50   .8     .65     48
i2  9.75  1.1     .5      32
i2  10      1     .09     44
i2  10.25    1     .3      32
i2  10.50   .8     .5      51
i2  10.75    1     .3      44
i2  11       1     .5      32
i2  11.25    1     .3      56
i2  11.50   .8     .65     48
i2  11.75  1.1     .5      32
i2  12       1     .09     44
i2  12.25    1     .3      32
i2  12.50   .8     .5      51
i2  12.75    1     .3      44
i2  13       1     .5      32
i2  13.25    1     .3      56
i2  13.50   .8     .65     48
i2  13.75  1.1     .5      32
i2  14       1     .09     44
i2  14.25    1     .3      32
i2  14.50   .8     .5      51
i2  14.75    1     .7      44
i2  15       1     .9      32
i2  15.25    1    1.1      56
i2  15.50   .8    1.3      48
i2  15.75  1.1    1.5      32
i2  16       1     .09     46
i2  16.25    1     .3      34
i2  16.50   .8     .5      53
i2  16.75    1     .3      46
i2  17       1     .5      34
i2  17.25    1     .3      58
i2  17.50   .8     .65     50
i2  17.75  1.1     .5      34
i2  18       1     .09     46
i2  18.25    1     .3      34
i2  18.50   .8     .5      53
i2  18.75    1     .3      46
i2  19       1     .5      34
i2  19.25    1     .3      58
i2  19.50   .8     .65     50
i2  19.75  1.1     .5      34
i2  20       1     .09     46
i2  20.25    1     .3      34
i2  20.50   .8     .5      53
i2  20.75    1     .3      46
i2  21       1     .5      34
i2  21.25    1     .3      58
i2  21.50   .8     .65     50
i2  21.75  1.1     .5      34
i2  22       1     .09     46
i2  22.25    1     .3      34
i2  22.50   .8     .5      53
i2  22.75    1     .3      46
i2  23       1     .5      34
i2  23.25    1     .3      58
i2  23.50   .8     .65     50
i2  23.75  1.1     .5      34
i2  24       1     .09     41
i2  24.25    1     .3      29
i2  24.5    .8     .5      48
i2  24.75    1     .3      41
i2  25       1     .5      29
i2  25.25    1     .3      53
i2  25.5    .8     .65     44
i2  25.75  1.1     .5      29
i2  26       1     .09     41
i2  26.25    1     .3      29
i2  26.5    .8     .5      48
i2  26.75    1     .3      41
i2  27       1     .5      29
i2  27.25    1     .3      53
i2  27.5    .8     .65     44 
i2  27.75  1.1     .5      29
i2  28       1     .09     41
i2  28.25    1     .1      29
i2  28.5    .8     .2      48
i2  28.75    1     .3      41
i2  29       1     .4      29
i2  29.25    1     .5      53
i2  29.5    .8     .6      44
i2  29.75  1.1     .7      29
i2  30       1     .8      41
i2  30.25    1     .9      29
i2  30.5    .8     1       48
i2  30.75    1    1.1      41
i2  31       1    1.2      29
i2  31.25    1    1.3      53
i2  31.5    .8    1.4      44
i2  31.75  1.1    1.5      29
i4 1.000 1.000 200 6000
i4 3.000 1.000 200 6000
i4 5.000 1.000 200 6000
i4 7.000 1.000 200 6000
i4 9.000 1.000 200 6000
i4 11.000 1.000 200 6000
i4 13.000 1.000 200 6000
i4 15.000 1.000 200 6000
i4 17.000 1.000 200 6000
i4 19.000 1.000 200 6000
i4 21.000 1.000 200 6000
i4 23.000 1.000 200 6000
i4 25.000 1.000 200 6000
i4 27.000 1.000 200 6000
i4 29.000 1.000 200 6000
i4 31.000 1.000 200 6000
i3   0   16   90   6.00    8   5   .4
i3  16   30   90   7.00    8   5   .4
</CsScore>
</CsoundSynthesizer>

