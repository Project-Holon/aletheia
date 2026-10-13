/*
 * function: VCT_ADPCM_Encode3Bit
 * address: 0x021AFABC
 * packet: pkt_ov013_021AFABC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * 3-bit ADPCM encoder (twin of the decoder VCT_ADPCM_Decode3Bit): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * pass 6 2026-10-06 P6L07: EXACT (was 352 B off; EXACT in --lang c99 and --lang c). Found with a
 * capture of the mwccarm register allocator (SelectColors at 0x5269d0) and an exact replay model of
 * its simplify/select passes. Levers: (1) the step table read once after the sign if/else (join form);
 * (2) helper locals declared delta, pred, step, idx, diff, code, np (each inline copy numbers its
 * locals in declaration order, and steady and reloaded samples are simplified in different passes);
 * (3) one u8 accumulator reused for all three output bytes (the second and third live ranges become
 * new, late-numbered webs, so they take r6 as in the original).
 * symbols:
 *   gAdpcmIndexTable3 0x021B3A04 data ov013 a1
 *   gAdpcmStepTable 0x021B3A1C data ov013 a2
 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;
extern const s8 gAdpcmIndexTable3[8];
extern const s16 gAdpcmStepTable[89];
static inline u8 Adpcm3EncodeSample(AdpcmState *st, int sample)
{
    int delta;
    int pred;
    int step;
    int idx;
    int diff;
    int code;
    int np;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    if (diff < 0) {
        code = 4;
        diff = -diff;
    } else {
        code = 0;
    }
    step = gAdpcmStepTable[idx];
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
    np = pred + delta;
    if (np < -32768) np = -32768;
    if (np > 32767) np = 32767;
    idx += gAdpcmIndexTable3[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}

void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    u8 c2, c5;
    for (i = 0; i < n / 8; i++) {
        a = Adpcm3EncodeSample(st, *src++) << 5;
        a |= Adpcm3EncodeSample(st, *src++) << 2;
        c2 = Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c2 >> 1);
        a = Adpcm3EncodeSample(st, *src++) << 4;
        a |= Adpcm3EncodeSample(st, *src++) << 1;
        c5 = Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c2 << 7) | (c5 >> 2);
        a = Adpcm3EncodeSample(st, *src++) << 3;
        a |= Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c5 << 6);
    }
}
