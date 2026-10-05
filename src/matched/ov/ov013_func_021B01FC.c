/*
 * function: func_021B01FC
 * address: 0x021B01FC
 * packet: pkt_ov013_021B01FC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed.
 * (1) No named step local: the table is read twice, in the compare and again for
 * the delta (`delta = d_021B3A1C[idx]`); with a `step` local the preheader loaded
 * the index table first. (2) The new predictor is its own local `np`, so the add
 * does not write back into `pred`. (3) `src` is not const: with const the idx store
 * sinks below the orr. (4) The samples are read as `*src++`: that moves the src
 * increment into the last sample's slot (add r1,r1,#8 early).
 * symbols:
 *   d_021B3A00 0x021B3A00 data ov013 a1
 *   d_021B3A1C 0x021B3A1C data ov013 a2
 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;
extern const s8 d_021B3A00[4];
extern const s16 d_021B3A1C[89];
static inline u8 Adpcm2EncodeSample(AdpcmState *st, int sample)
{
    int pred;
    int idx;
    int diff;
    int code;
    int delta;
    int np;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= d_021B3A1C[idx]) {
        code |= 1;
    }
    delta = d_021B3A1C[idx];
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    np = pred + delta;
    if (np < -32768) np = -32768;
    if (np > 32767) np = 32767;
    idx += d_021B3A00[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}
void func_021B01FC(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    for (i = 0; i < n / 4; i++) {
        a = Adpcm2EncodeSample(st, *src++);
        a |= Adpcm2EncodeSample(st, *src++) << 2;
        a |= Adpcm2EncodeSample(st, *src++) << 4;
        a |= Adpcm2EncodeSample(st, *src++) << 6;
        *dst++ = a;
    }
}
