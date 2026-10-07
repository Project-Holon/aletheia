/*
 * file:     unit_021AEB20_p06.c
 * unit:     yes
 * function: func_021AFABC, func_021AFFE4, func_021B01FC, func_021B043C, func_021B04A8
 * address:  0x021AFABC
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
 *   d_021B3A04 0x021B3A04 data ov013 a1
 *   d_021B3A1C 0x021B3A1C data ov013 a2
 *   d_021B3A00     0x021B3A00  data  ov013  a1
 *   func_021AF628  0x021AF628  arm  ov013
 *   func_021AF340  0x021AF340  arm  ov013
 *   func_021AF494  0x021AF494  arm  ov013
 */
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

extern void func_021AF628(const u8 *src, s16 *dst, u32 n, struct AdpcmState *st);
extern void func_021AF340(const u8 *src, s16 *dst, u32 n, struct AdpcmState *st);
extern void func_021AF494(u8 *dst, s16 *src, u32 n, struct AdpcmState *st);
void func_021AFABC(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021AFFE4(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
void func_021B01FC(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode);
void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode);
extern const s8 d_021B3A04[8];
extern const s16 d_021B3A1C[89];
extern const s8 d_021B3A00[4];

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
