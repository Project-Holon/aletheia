/*
 * file:     ctvt_adpcm.c
 * unit:     yes
 * function: CTVT_ADPCM_ResetEncoder, CTVT_ADPCM_ResetDecoder, CTVT_ADPCM_Encode, CTVT_ADPCM_Decode, CTVT_ADPCM_EncodeSamples, CTVT_ADPCM_DecodeSamples, CTVT_ADPCM_EncodeSample, CTVT_ADPCM_DecodeSample
 * address:  0x021B69E0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from camera_system.c, draw_system.c by tools/splitfile.py.
 *
 * symbols:
 *   gCtvtAdpcmState 0x021C88E4 data a4 ov172
 *   gCtvtAdpcmEncoderState     0x021C88E8  data
 *   gImaStepTable 0x021C4D20 data a4
 *   gImaIndexTable 0x021C4D10 data a1
 *   CTVT_ADPCM_Encode  0x021B6A00  thumb  ov172
 *   CTVT_ADPCM_Decode  0x021B6A18  thumb  ov172
 */
#include "../types.h"

/* IMA ADPCM coder state: last predicted sample and the step table index. */
typedef struct AdpcmState {
    s16 predictor;
    s8 stepIndex;
} AdpcmState;

extern AdpcmState gCtvtAdpcmState[2];    /* decoder state, then encoder state */
extern AdpcmState gCtvtAdpcmEncoderState;       /* encoder state, 4 bytes after the decoder state */
extern const int gImaStepTable[];      /* IMA step size table, 89 entries */
extern const s8 gImaIndexTable[];       /* IMA index adjustment table, 16 entries */

void CTVT_ADPCM_ResetEncoder(void);
void CTVT_ADPCM_ResetDecoder(void);
int CTVT_ADPCM_Encode(void *pcm, unsigned pcmBytes, void *out);
int CTVT_ADPCM_Decode(int in, int inBytes, int out);
void CTVT_ADPCM_EncodeSamples(short *pcm, unsigned char *out, int sampleCount, AdpcmState *state);
void CTVT_ADPCM_DecodeSamples(char *in, s16 *out, int sampleCount, AdpcmState *state);
s8 CTVT_ADPCM_EncodeSample(int sample, AdpcmState *state);
s16 CTVT_ADPCM_DecodeSample(unsigned char code, AdpcmState *state);

/* Resets the encoder state. */
void CTVT_ADPCM_ResetEncoder(void)
{
    gCtvtAdpcmState[1].predictor = 0;
    gCtvtAdpcmState[1].stepIndex = 0;
}

/* Resets the decoder state. */
void CTVT_ADPCM_ResetDecoder(void)
{
    gCtvtAdpcmState[0].predictor = 0;
    gCtvtAdpcmState[0].stepIndex = 0;
}

/* Encodes pcmBytes bytes of 16 bit samples to 4 bit codes with the encoder
 * state. Returns the number of code bytes. */
int CTVT_ADPCM_Encode(void *pcm, unsigned pcmBytes, void *out)
{
    CTVT_ADPCM_EncodeSamples((short *)pcm, (unsigned char *)out, (int)(pcmBytes >> 1), &gCtvtAdpcmEncoderState);
    return (int)((pcmBytes + 3) >> 2);
}

/* Decodes inBytes bytes of codes (two per byte) with the decoder state.
 * Returns the number of output bytes. */
int CTVT_ADPCM_Decode(int in, int inBytes, int out)
{
    CTVT_ADPCM_DecodeSamples((char *)in, (s16 *)out, inBytes * 2, gCtvtAdpcmState);
    return inBytes * 4;
}

/* Packs the codes of sampleCount samples two per byte, first sample in the low
 * nibble. An odd last code is stored alone in the low nibble. */
void CTVT_ADPCM_EncodeSamples(short *pcm, unsigned char *out, int sampleCount, AdpcmState *state)
{
    int i;
    int outIdx = 0;
    int pending = 0;
    int havePending = 0;

    for (i = 0; i < sampleCount; i++) {
        unsigned char code = (unsigned char)CTVT_ADPCM_EncodeSample(pcm[i], state);

        if (havePending == 0) {
            pending = code;
            havePending = 1;
        } else {
            havePending = 0;
            out[outIdx] = (unsigned char)(pending + ((code & 0xf) << 4));
            pending = 0;
            outIdx++;
        }
    }

    if (havePending == 1)
        out[outIdx] = (unsigned char)pending;
}

/* Decodes sampleCount / 2 code bytes into sampleCount samples, low nibble first. */
void CTVT_ADPCM_DecodeSamples(char *in, s16 *out, int sampleCount, AdpcmState *state)
{
    int i, byteCount;
    char code;
    byteCount = sampleCount / 2;
    for (i = 0; i < byteCount; i++) {
        code = in[i];
        out[i * 2] = CTVT_ADPCM_DecodeSample(code & 15, state);
        out[i * 2 + 1] = CTVT_ADPCM_DecodeSample((code & 240) >> 4, state);
    }
}

/* Encodes one sample as a 4 bit code (sign in bit 3) and updates the state. */
s8 CTVT_ADPCM_EncodeSample(int sample, AdpcmState *state)
{
    int code, delta, step, value, index;
    code = 0;
    index = state->stepIndex;
    value = state->predictor;
    step = gImaStepTable[index];
    sample -= value;
    if (sample < 0) { code = 8; sample = -sample; }
    delta = step >> 3;
    if (sample >= step) { code |= 4; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 2; sample -= step; delta += step; }
    step >>= 1;
    if (sample >= step) { code |= 1; delta += step; }
    if (code & 8) value -= delta;
    else value += delta;
    if (value > 32767) value = 32767;
    else if (value < -32767) value = -32767;
    index += gImaIndexTable[code];
    if (index < 0) index = 0;
    if (index > 88) index = 88;
    state->predictor = value;
    state->stepIndex = index;
    return code & 15;
}

/* Decodes one 4 bit code to a sample and updates the state. */
s16 CTVT_ADPCM_DecodeSample(unsigned char code, AdpcmState *state)
{
  int step;
  int value;
  int index;
  int delta;
  value = state->predictor;
  index = state->stepIndex;
  step = gImaStepTable[index];
  delta = step >> 3;
  if (code & 4)
    delta += step;
  if (code & 2)
    delta += step >> 1;
  if (code & 1)
    delta += step >> 2;
  if (code & 8)
  {
    value -= delta;
    if (value < (-32767))
      value = -32767;
  }
  else
  {
    value += delta;
    if (value > 32767)
      value = 32767;
  }
  index += gImaIndexTable[code];
  if (index < 0)
    index = 0;
  else
    if (index > 88)
    index = 88;
  state->predictor = (s16) value;
  state->stepIndex = index;
  return (s16) value;
}
