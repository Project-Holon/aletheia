#ifndef GAME_OV172_CTVT_ADPCM_H
#define GAME_OV172_CTVT_ADPCM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_adpcm.c, prototypes copied from their definitions. */

struct CtvtAdpcmAdpcmState;
typedef struct CtvtAdpcmAdpcmState CtvtAdpcmAdpcmState;

#include "../types.h"

void CTVT_ADPCM_ResetEncoder(void);
void CTVT_ADPCM_ResetDecoder(void);
int CTVT_ADPCM_Encode(void *pcm, unsigned pcmBytes, void *out);
int CTVT_ADPCM_Decode(int in, int inBytes, int out);
void CTVT_ADPCM_EncodeSamples(short *pcm, unsigned char *out, int sampleCount, CtvtAdpcmAdpcmState *state);
void CTVT_ADPCM_DecodeSamples(char *in, s16 *out, int sampleCount, CtvtAdpcmAdpcmState *state);
s8 CTVT_ADPCM_EncodeSample(int sample, CtvtAdpcmAdpcmState *state);
s16 CTVT_ADPCM_DecodeSample(unsigned char code, CtvtAdpcmAdpcmState *state);
/* END mkheaders: generated region */

#endif
