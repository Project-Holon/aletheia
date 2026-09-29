/*
 * function: func_021AFFE4
 * address:  0x021AFFE4
 * packet:   pkt_ov013_021AFFE4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples,
 * with the predictor and step index carried in *st (the 4-bit IMA twin is
 * func_021AF340). Index table (s8[4]) at 0x021B3A00, step table (s16[89])
 * at 0x021B3A1C.
 *
 * symbols:
 *   d_021B3A00     0x021B3A00  data  ov013  a1
 *   d_021B3A1C     0x021B3A1C  data  ov013  a2
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
