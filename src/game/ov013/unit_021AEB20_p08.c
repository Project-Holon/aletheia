/*
 * file:     unit_021AEB20_p08.c
 * unit:     yes
 * function: func_021AF340, func_021AF494, func_021AF628, func_021AFABC, func_021AFFE4, func_021B01FC, func_021B043C, func_021B04A8, func_021B0508, func_021B0600
 * address:  0x021AF340
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B3A0C     0x021B3A0C  data  ov013  a1
 *   d_021B3A1C     0x021B3A1C  data  ov013  a2
 *   d_021B3A04 0x021B3A04 data ov013 a1
 *   d_021B3A00     0x021B3A00  data  ov013  a1
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   d_021B3C24     0x021B3C24  data  ov013  a4
 *   d_021B60D8     0x021B60D8  data  ov013  a4
 *   d_021B3AD0     0x021B3AD0  data  ov013  a1
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   d_021B3CB0     0x021B3CB0  data  ov013  a4
 *   d_021B3CBC     0x021B3CBC  data  ov013  a4
 *   func_02087170  0x02087170  arm
 *   func_021B3250  0x021B3250  arm  ov013
 *   func_021B16E4  0x021B16E4  arm  ov013
 *   func_021B19BC  0x021B19BC  arm  ov013
 *   func_021B12FC  0x021B12FC  arm  ov013
 *   func_021B3364  0x021B3364  arm  ov013
 */
#include "../../matched/include/G_Ctx42C0.h"
#include "../../matched/include/G_021B3C84.h"

#define ADPCM_ENCODE(code, step, p, idx, diff, vp, np, sample) \
    idx = st->index;                                           \
    p = st->pred;                                              \
    step = d_021B3A1C[idx];                                    \
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
    idx += d_021B3A0C[code];                                   \
    if (idx < 0) {                                             \
        idx = 0;                                               \
    } else if (idx > 88) {                                     \
        idx = 88;                                              \
    }                                                          \
    st->pred = (s16)np;                                        \
    st->index = idx
typedef unsigned char u8;

typedef signed char s8;

typedef short s16;

typedef unsigned int u32;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

typedef struct AdpcmHdr {
    s16 pred;
    u8 index;
    u8 zero;
} AdpcmHdr;

typedef unsigned short u16;

typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[4];
    u32 fC;
    u8 pad10[0xC];
    u32 f1C;
    int f20;
    u32 f24;
} Ctx3C84;

typedef struct {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef struct {
    u8 pad0[0x10];
    int f10;
} Ctx60D8;

typedef struct {
    u8 raw[0x94];
} Slot;

typedef struct {
    u8 a;
    u8 b;
} Pair;

extern u16 func_02087170(void);
extern void func_021B3250(void);
extern void func_021B16E4(u32 i);
extern void func_021B19BC(char *p, int i, int a2);
extern void func_021B12FC(void);
extern void func_021B3364(void);
void func_021AF340(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
/* * Byte locals for all three packed input bytes reproduce the spilled step * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail. * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first. */ void func_021AF628(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
/* * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples, * with the predictor and step index carried in *st (the 4-bit IMA twin is * func_021AF340). Index table (s8[4]) at 0x021B3A00, step table (s16[89]) * at 0x021B3A1C. */ void func_021AFFE4(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
/* * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four * s16 samples to one byte, low pair first. * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed. * (1) No named step local: the table is read twice, in the compare and again for * the delta (`delta = d_021B3A1C[idx]`); with a `step` local the preheader loaded * the index table first. (2) The new predictor is its own local `np`, so the add * does not write back into `pred`. (3) `src` is not const: with const the idx store * sinks below the orr. (4) The samples are read as `*src++`: that moves the src * increment into the last sample's slot (add r1,r1,#8 early). */ void func_021B01FC(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode);
void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode);
/* * Initialize TCV session state, six counters and three request slots. * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The f1C store is written in * each arm of the mode if/else (the join no longer splits the 3C84 pointer, f1C goes through the * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which * gives the later-born address temp the lower register (r1) and the table base r2, so the table * load stays below the f1C store. */ int func_021B0508(void);
void func_021B0600(void);
extern const s8 d_021B3A0C[16];
extern const s16 d_021B3A1C[89];
extern const s8 d_021B3A04[8];
extern const s8 d_021B3A00[4];
extern Ctx3C84 d_021B3C84;
extern int d_021B3C24;
extern Ctx60D8 d_021B60D8;
extern const Pair d_021B3AD0[];
extern struct Ctx42C0 d_021B42C0;
extern void *d_021B3CB0[3];
extern Slot d_021B3CBC[3];




static inline s16 AdpcmDecodeNibble(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int step;
    int diff;

    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
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
        pred -= diff;
        if (pred < -32768) {
            pred = -32768;
        }
    } else {
        pred += diff;
        if (pred > 32767) {
            pred = 32767;
        }
    }
    idx += d_021B3A0C[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * IMA ADPCM decoder: n source bytes, low nibble first, to 2n s16 samples,
 * with the predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C.
 */
void func_021AF340(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = AdpcmDecodeNibble(st, *src & 0xF);
        *dst++ = AdpcmDecodeNibble(st, (*src >> 4) & 0xF);
        src++;
    }
}





/*
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders func_021AF340 and func_021AF628.
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
 */
void func_021AF494(u8 *dst, s16 *src, u32 n, AdpcmState *st)
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




static inline s16 Adpcm3DecodeCode(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int step;
    int diff;
    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
    diff = step >> 2;
    if (code & 2) diff += step;
    if (code & 1) diff += step >> 1;
    if (code & 4) {
        pred -= diff;
        if (pred < -32768) pred = -32768;
    } else {
        pred += diff;
        if (pred > 32767) pred = 32767;
    }
    idx += d_021B3A04[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * Byte locals for all three packed input bytes reproduce the spilled step
 * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail.
 * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first.
 */
void func_021AF628(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    u8 b;
    u8 c;
    for (i = 0; i < n / 3; i++) {
    a = src[0];
    b = src[1];
    c = src[2];
    dst[0] = Adpcm3DecodeCode(st, a >> 5);
    dst[1] = Adpcm3DecodeCode(st, (a >> 2) & 7);
    dst[2] = Adpcm3DecodeCode(st, ((a << 1) & 7) | (b >> 7));
    dst[3] = Adpcm3DecodeCode(st, (b >> 4) & 7);
    dst[4] = Adpcm3DecodeCode(st, (b >> 1) & 7);
    dst[5] = Adpcm3DecodeCode(st, ((b << 2) & 7) | (c >> 6));
    dst[6] = Adpcm3DecodeCode(st, (c >> 3) & 7);
    dst[7] = Adpcm3DecodeCode(st, c & 7);
        src += 3;
        dst += 8;
    }
}



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
    step = d_021B3A1C[idx];
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
    idx += d_021B3A04[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}




/*
 * 3-bit ADPCM encoder (twin of the decoder func_021AF628): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * pass 6 2026-10-06 P6L07: EXACT (was 352 B off; EXACT in --lang c99 and --lang c). Found with a
 * capture of the mwccarm register allocator (SelectColors at 0x5269d0) and an exact replay model of
 * its simplify/select passes. Levers: (1) the step table read once after the sign if/else (join form);
 * (2) helper locals declared delta, pred, step, idx, diff, code, np (each inline copy numbers its
 * locals in declaration order, and steady and reloaded samples are simplified in different passes);
 * (3) one u8 accumulator reused for all three output bytes (the second and third live ranges become
 * new, late-numbered webs, so they take r6 as in the original).
 */
void func_021AFABC(u8 *dst, s16 *src, u32 n, AdpcmState *st)
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




static inline s16 Adpcm2DecodeCode(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int diff;

    idx = st->index;
    pred = st->pred;
    diff = d_021B3A1C[idx];
    if (!(code & 1)) {
        diff = 0;
    }
    if (code & 2) {
        pred -= diff;
        if (pred < -32768) {
            pred = -32768;
        }
    } else {
        pred += diff;
        if (pred > 32767) {
            pred = 32767;
        }
    }
    idx += d_021B3A00[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples,
 * with the predictor and step index carried in *st (the 4-bit IMA twin is
 * func_021AF340). Index table (s8[4]) at 0x021B3A00, step table (s16[89])
 * at 0x021B3A1C.
 */
void func_021AFFE4(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = Adpcm2DecodeCode(st, *src & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 2) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 4) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 6) & 3);
        src++;
    }
}



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



/*
 * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed.
 * (1) No named step local: the table is read twice, in the compare and again for
 * the delta (`delta = d_021B3A1C[idx]`); with a `step` local the preheader loaded
 * the index table first. (2) The new predictor is its own local `np`, so the add
 * does not write back into `pred`. (3) `src` is not const: with const the idx store
 * sinks below the orr. (4) The samples are read as `*src++`: that moves the src
 * increment into the last sample's slot (add r1,r1,#8 early).
 */
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




void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode)
{
    AdpcmState st;

    st.pred = hdr->pred;
    st.index = hdr->index;
    switch (mode) {
    case 2:
        func_021AFFE4((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 3:
        func_021AF628((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 4:
        func_021AF340((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    }
}




void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode)
{
    out->pred = st->pred;
    out->index = st->index;
    out->zero = 0;
    switch (mode) {
    case 2:
        func_021B01FC((u8 *)out + 4, a, n, st);
        break;
    case 3:
        func_021AFABC((u8 *)out + 4, a, n, st);
        break;
    case 4:
        func_021AF494((u8 *)out + 4, a, n, st);
        break;
    }
}



static inline u32 pairValue(u32 k)
{
    const Pair *p;
    u32 a;
    a = d_021B3AD0[k].a;
    p = &d_021B3AD0[k];
    return a * 0x44 + p->b + 0xC;
}


/*
 * Initialize TCV session state, six counters and three request slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The f1C store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, f1C goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 */
int func_021B0508(void)
{
    u32 i;
    u32 k;

    d_021B3C84.f0 = func_02087170();
    d_021B3C24 = 1;
    d_021B3C84.f20 = 0;
    d_021B3C84.f4 = 0;
    k = 0;
    if (d_021B60D8.f10 != 1) {
        k = 4;
        d_021B3C84.f1C = k;
    } else {
        d_021B3C84.f1C = k;
    }
    d_021B3C84.f24 = 0x440;
    d_021B3C84.fC = pairValue(k);
    d_021B42C0.f8C0 = 0;
    d_021B42C0.f8C4 = 0;
    d_021B42C0.f8CC = 0;
    d_021B42C0.f8C8 = 0;
    d_021B42C0.f8D0 = 0;
    d_021B42C0.f8D4 = 0;
    func_021B3250();
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        d_021B3CB0[i] = 0;
        func_021B16E4(i);
        func_021B19BC((char *)&d_021B3CBC[i], i, -1);
    }
    func_021B12FC();
    func_021B3364();
    return 1;
}


void func_021B0600(void) { ((int *)&d_021B3C84)[8] = 0; }
