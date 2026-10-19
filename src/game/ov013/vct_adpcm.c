/*
 * file:     vct_adpcm.c
 * unit:     yes
 * function: VCT_ADPCM_Decode4Bit, VCT_ADPCM_Encode4Bit, VCT_ADPCM_Decode3Bit, VCT_ADPCM_Encode3Bit, VCT_ADPCM_Decode2Bit, VCT_ADPCM_Encode2Bit, VCT_ADPCM_DecodePacket, VCT_ADPCM_EncodePacket
 * address:  0x021AF340
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from vct_main.c, vct_audio.c, vct_session.c, vct_dsp.c by tools/splitfile.py.
 *
 * symbols:
 *   gAdpcmIndexTable4     0x021B3A0C  data ov013 a1
 *   gAdpcmStepTable     0x021B3A1C  data ov013 a2
 *   gAdpcmIndexTable3     0x021B3A04  data ov013 a1
 *   gAdpcmIndexTable2     0x021B3A00  data ov013 a1
 *   VCT_ADPCM_EncodePacket  0x021B04A8  arm  ov013
 *   VCT_ADPCM_DecodePacket  0x021B043C  arm  ov013
 */
#include "vct_types.h"

void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);

void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);

void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);

void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);

void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st);

void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st);

void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int packetBytes, int bits);

void VCT_ADPCM_EncodePacket(AdpcmHeader *out, void *samples, int sampleCount, AdpcmState *st, int bits);

/* ADPCM index tables (4, 3 and 2 bit codes) and the step table. */
extern const s8 gAdpcmIndexTable4[16];

extern const s16 gAdpcmStepTable[89];

extern const s8 gAdpcmIndexTable3[8];

extern const s8 gAdpcmIndexTable2[4];

#pragma thumb off

#define ADPCM_ENCODE(code, step, predicted, indexVar, diff, delta, newPred, sample) \
    indexVar = st->stepIndex;                                           \
    predicted = st->predictor;                                              \
    step = gAdpcmStepTable[indexVar];                                    \
    diff = (sample) - predicted;                                       \
    if (diff < 0) {                                            \
        code = 8;                                              \
        diff = -diff;                                          \
    } else {                                                   \
        code = 0;                                              \
    }                                                          \
    if (diff >= step) {                                        \
        code |= 4;                                             \
        diff -= step;                                          \
    }                                                          \
    if (diff >= (step >> 1)) {                                 \
        code |= 2;                                             \
        diff -= step >> 1;                                     \
    }                                                          \
    if (diff >= (step >> 2)) {                                 \
        code |= 1;                                             \
    }                                                          \
    delta = step >> 3;                                            \
    if (code & 4) {                                            \
        delta += step;                                            \
    }                                                          \
    if (code & 2) {                                            \
        delta += step >> 1;                                       \
    }                                                          \
    if (code & 1) {                                            \
        delta += step >> 2;                                       \
    }                                                          \
    if (code & 8) {                                            \
        delta = -delta;                                              \
    }                                                          \
    newPred = predicted + delta;                                               \
    if (newPred < -32768) {                                         \
        newPred = -32768;                                           \
    }                                                          \
    if (newPred > 32767) {                                          \
        newPred = 32767;                                            \
    }                                                          \
    indexVar += gAdpcmIndexTable4[code];                                   \
    if (indexVar < 0) {                                             \
        indexVar = 0;                                               \
    } else if (indexVar > 88) {                                     \
        indexVar = 88;                                              \
    }                                                          \
    st->predictor = (s16)newPred;                                        \
    st->stepIndex = indexVar

static inline s16 Adpcm4DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int step;
    int diff;

    stepIndex = st->stepIndex;
    predicted = st->predictor;
    step = gAdpcmStepTable[stepIndex];
    diff = step >> 3;
    if (code & 4) {
        diff += step;
    }
    if (code & 2) {
        diff += step >> 1;
    }
    if (code & 1) {
        diff += step >> 2;
    }
    if (code & 8) {
        predicted -= diff;
        if (predicted < -32768) {
            predicted = -32768;
        }
    } else {
        predicted += diff;
        if (predicted > 32767) {
            predicted = 32767;
        }
    }
    stepIndex += gAdpcmIndexTable4[code];
    if (stepIndex < 0) {
        stepIndex = 0;
    } else if (stepIndex > 88) {
        stepIndex = 88;
    }
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}

/*
 * IMA ADPCM decoder: n source bytes, low nibble first, to 2n s16 samples,
 * with the predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C.
 */
void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < byteCount; i++) {
        *dst++ = Adpcm4DecodeCode(st, *src & 0xF);
        *dst++ = Adpcm4DecodeCode(st, (*src >> 4) & 0xF);
        src++;
    }
}

/*
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders VCT_ADPCM_Decode4Bit and VCT_ADPCM_Decode3Bit.
 *
 * pass 6 2026-10-06 P6L06: closed with the register colouring capture
 * (scratchpad tools6/regalloc_trace.py). The colouring is round 1 (round 0
 * spills the hoisted constants). Simplify sweeps vregs in ascending order,
 * so the image needs vreg(step1) < vreg(pairCount) < vreg(predicted1, stepIndex1, code1).
 * With an inline helper the copy of its locals is one block below all outer
 * locals, so pairCount can never fall inside it. The encoder is a macro over
 * per-sample function locals; outer locals are numbered in reverse
 * declaration order, so the sample-1 locals are declared before pairCount and
 * step1/sample1 after it.
 */
void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 lo;
    u8 hi;
    int newPred1, delta1, code1, diff1, stepIndex1, predicted1;
    u32 pairCount;
    int step1, sample1;
    int newPred2, delta2, code2, diff2, stepIndex2, predicted2;
    int step2, sample2;

    pairCount = sampleCount / 2;
    for (i = 0; i < pairCount; i++) {
        sample1 = *src++;
        ADPCM_ENCODE(code1, step1, predicted1, stepIndex1, diff1, delta1, newPred1, sample1);
        lo = code1;
        sample2 = *src++;
        ADPCM_ENCODE(code2, step2, predicted2, stepIndex2, diff2, delta2, newPred2, sample2);
        hi = code2;
        *dst++ = lo | (u8)(hi << 4);
    }
}

static inline s16 Adpcm3DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int step;
    int diff;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    step = gAdpcmStepTable[stepIndex];
    diff = step >> 2;
    if (code & 2) diff += step;
    if (code & 1) diff += step >> 1;
    if (code & 4) {
        predicted -= diff;
        if (predicted < -32768) predicted = -32768;
    } else {
        predicted += diff;
        if (predicted > 32767) predicted = 32767;
    }
    stepIndex += gAdpcmIndexTable3[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}

/*
 * Byte locals for all three packed input bytes reproduce the spilled step
 * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail.
 * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first.
 */
void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;
    u8 byte0;
    u8 byte1;
    u8 byte2;
    for (i = 0; i < byteCount / 3; i++) {
    byte0 = src[0];
    byte1 = src[1];
    byte2 = src[2];
    dst[0] = Adpcm3DecodeCode(st, byte0 >> 5);
    dst[1] = Adpcm3DecodeCode(st, (byte0 >> 2) & 7);
    dst[2] = Adpcm3DecodeCode(st, ((byte0 << 1) & 7) | (byte1 >> 7));
    dst[3] = Adpcm3DecodeCode(st, (byte1 >> 4) & 7);
    dst[4] = Adpcm3DecodeCode(st, (byte1 >> 1) & 7);
    dst[5] = Adpcm3DecodeCode(st, ((byte1 << 2) & 7) | (byte2 >> 6));
    dst[6] = Adpcm3DecodeCode(st, (byte2 >> 3) & 7);
    dst[7] = Adpcm3DecodeCode(st, byte2 & 7);
        src += 3;
        dst += 8;
    }
}

static inline u8 Adpcm3EncodeSample(AdpcmState *st, int sample)
{
    int delta;
    int predicted;
    int step;
    int stepIndex;
    int diff;
    int code;
    int newPred;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = sample - predicted;
    if (diff < 0) {
        code = 4;
        diff = -diff;
    } else {
        code = 0;
    }
    step = gAdpcmStepTable[stepIndex];
    if (diff >= step) {
        code |= 2;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 1;
    }
    delta = step >> 2;
    if (code & 2) delta += step;
    if (code & 1) delta += step >> 1;
    if (code & 4) delta = -delta;
    newPred = predicted + delta;
    if (newPred < -32768) newPred = -32768;
    if (newPred > 32767) newPred = 32767;
    stepIndex += gAdpcmIndexTable3[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->predictor = (s16)newPred;
    st->stepIndex = stepIndex;
    return code;
}

/*
 * 3-bit ADPCM encoder (twin of the decoder VCT_ADPCM_Decode3Bit): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * pass 6 2026-10-06 P6L07: EXACT (was 352 B off; EXACT in --lang c99 and --lang c). Found with a
 * capture of the mwccarm register allocator (SelectColors at 0x5269d0) and an exact replay model of
 * its simplify/select passes. Levers: (1) the step table read once after the sign if/else (join form);
 * (2) helper locals declared delta, predicted, step, stepIndex, diff, code, newPred (each inline copy numbers its
 * locals in declaration order, and steady and reloaded samples are simplified in different passes);
 * (3) one u8 accumulator reused for all three output bytes (the second and third live ranges become
 * new, late-numbered webs, so they take r6 as in the original).
 */
void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 packed;
    u8 code2, code5;
    for (i = 0; i < sampleCount / 8; i++) {
        packed = Adpcm3EncodeSample(st, *src++) << 5;
        packed |= Adpcm3EncodeSample(st, *src++) << 2;
        code2 = Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code2 >> 1);
        packed = Adpcm3EncodeSample(st, *src++) << 4;
        packed |= Adpcm3EncodeSample(st, *src++) << 1;
        code5 = Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code2 << 7) | (code5 >> 2);
        packed = Adpcm3EncodeSample(st, *src++) << 3;
        packed |= Adpcm3EncodeSample(st, *src++);
        *dst++ = packed | (code5 << 6);
    }
}

static inline s16 Adpcm2DecodeCode(AdpcmState *st, int code)
{
    int predicted;
    int stepIndex;
    int diff;

    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = gAdpcmStepTable[stepIndex];
    if (!(code & 1)) {
        diff = 0;
    }
    if (code & 2) {
        predicted -= diff;
        if (predicted < -32768) {
            predicted = -32768;
        }
    } else {
        predicted += diff;
        if (predicted > 32767) {
            predicted = 32767;
        }
    }
    stepIndex += gAdpcmIndexTable2[code];
    if (stepIndex < 0) {
        stepIndex = 0;
    } else if (stepIndex > 88) {
        stepIndex = 88;
    }
    st->stepIndex = stepIndex;
    st->predictor = (s16)predicted;
    return (s16)predicted;
}

/*
 * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples,
 * with the predictor and step index carried in *st (the 4-bit IMA twin is
 * VCT_ADPCM_Decode4Bit). Index table (s8[4]) at 0x021B3A00, step table (s16[89])
 * at 0x021B3A1C.
 */
void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 byteCount, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < byteCount; i++) {
        *dst++ = Adpcm2DecodeCode(st, *src & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 2) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 4) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 6) & 3);
        src++;
    }
}

static inline u8 Adpcm2EncodeSample(AdpcmState *st, int sample)
{
    int predicted;
    int stepIndex;
    int diff;
    int code;
    int delta;
    int newPred;
    stepIndex = st->stepIndex;
    predicted = st->predictor;
    diff = sample - predicted;
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= gAdpcmStepTable[stepIndex]) {
        code |= 1;
    }
    delta = gAdpcmStepTable[stepIndex];
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    newPred = predicted + delta;
    if (newPred < -32768) newPred = -32768;
    if (newPred > 32767) newPred = 32767;
    stepIndex += gAdpcmIndexTable2[code];
    if (stepIndex < 0) stepIndex = 0;
    else if (stepIndex > 88) stepIndex = 88;
    st->predictor = (s16)newPred;
    st->stepIndex = stepIndex;
    return code;
}

/*
 * 2-bit ADPCM encoder (twin of the decoder VCT_ADPCM_Decode2Bit): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed.
 * (1) No named step local: the table is read twice, in the compare and again for
 * the delta (`delta = gAdpcmStepTable[stepIndex]`); with a `step` local the preheader loaded
 * the index table first. (2) The new predictor is its own local `newPred`, so the add
 * does not write back into `predicted`. (3) `src` is not const: with const the stepIndex store
 * sinks below the orr. (4) The samples are read as `*src++`: that moves the src
 * increment into the last sample's slot (add r1,r1,#8 early).
 */
void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 sampleCount, AdpcmState *st)
{
    u32 i;
    u8 packed;
    for (i = 0; i < sampleCount / 4; i++) {
        packed = Adpcm2EncodeSample(st, *src++);
        packed |= Adpcm2EncodeSample(st, *src++) << 2;
        packed |= Adpcm2EncodeSample(st, *src++) << 4;
        packed |= Adpcm2EncodeSample(st, *src++) << 6;
        *dst++ = packed;
    }
}

void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int packetBytes, int bits)
{
    AdpcmState st;

    st.predictor = hdr->predictor;
    st.stepIndex = hdr->stepIndex;
    switch (bits) {
    case 2:
        VCT_ADPCM_Decode2Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    case 3:
        VCT_ADPCM_Decode3Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    case 4:
        VCT_ADPCM_Decode4Bit((u8 *)hdr + 4, dst, packetBytes - 4, &st);
        break;
    }
}

void VCT_ADPCM_EncodePacket(AdpcmHeader *out, void *samples, int sampleCount, AdpcmState *st, int bits)
{
    out->predictor = st->predictor;
    out->stepIndex = st->stepIndex;
    out->zero = 0;
    switch (bits) {
    case 2:
        VCT_ADPCM_Encode2Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    case 3:
        VCT_ADPCM_Encode3Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    case 4:
        VCT_ADPCM_Encode4Bit((u8 *)out + 4, samples, sampleCount, st);
        break;
    }
}
