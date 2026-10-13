/*
 * function: VCT_ADPCM_Encode4Bit
 * address:  0x021AF494
 * packet:   pkt_ov013_021AF494
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders VCT_ADPCM_Decode4Bit and VCT_ADPCM_Decode3Bit.
 *
 * pass 6 2026-10-06 P6L06: closed with the register colouring capture
 * (scratchpad tools6/regalloc_trace.py). The colouring is round 1 (round 0
 * spills the hoisted constants). Simplify sweeps vregs in ascending order,
 * so the image needs vreg(step1) < vreg(half) < vreg(pred1, idx1, code1).
 * With an inline helper the copy of its locals is one block below all outer
 * locals, so half can never fall inside it. The encoder is a macro over
 * per-sample function locals; outer locals are numbered in reverse
 * declaration order, so the sample-1 locals are declared before half and
 * step1/sample1 after it.
 *
 * symbols:
 *   gAdpcmIndexTable4     0x021B3A0C  data  ov013  a1
 *   gAdpcmStepTable     0x021B3A1C  data  ov013  a2
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

extern const s8 gAdpcmIndexTable4[16];
extern const s16 gAdpcmStepTable[89];

#define ADPCM_ENCODE(code, step, p, idx, diff, vp, np, sample) \
    idx = st->index;                                           \
    p = st->pred;                                              \
    step = gAdpcmStepTable[idx];                                    \
    diff = (sample) - p;                                       \
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
    vp = step >> 3;                                            \
    if (code & 4) {                                            \
        vp += step;                                            \
    }                                                          \
    if (code & 2) {                                            \
        vp += step >> 1;                                       \
    }                                                          \
    if (code & 1) {                                            \
        vp += step >> 2;                                       \
    }                                                          \
    if (code & 8) {                                            \
        vp = -vp;                                              \
    }                                                          \
    np = p + vp;                                               \
    if (np < -32768) {                                         \
        np = -32768;                                           \
    }                                                          \
    if (np > 32767) {                                          \
        np = 32767;                                            \
    }                                                          \
    idx += gAdpcmIndexTable4[code];                                   \
    if (idx < 0) {                                             \
        idx = 0;                                               \
    } else if (idx > 88) {                                     \
        idx = 88;                                              \
    }                                                          \
    st->pred = (s16)np;                                        \
    st->index = idx

void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 lo;
    u8 hi;
    int np1, vp1, code1, diff1, idx1, pred1;
    u32 half;
    int step1, sample1;
    int np2, vp2, code2, diff2, idx2, pred2;
    int step2, sample2;

    half = n / 2;
    for (i = 0; i < half; i++) {
        sample1 = *src++;
        ADPCM_ENCODE(code1, step1, pred1, idx1, diff1, vp1, np1, sample1);
        lo = code1;
        sample2 = *src++;
        ADPCM_ENCODE(code2, step2, pred2, idx2, diff2, vp2, np2, sample2);
        hi = code2;
        *dst++ = lo | (u8)(hi << 4);
    }
}
