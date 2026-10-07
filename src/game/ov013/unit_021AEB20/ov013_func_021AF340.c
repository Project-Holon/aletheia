/*
 * function: func_021AF340
 * address:  0x021AF340
 * packet:   pkt_ov013_021AF340
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * IMA ADPCM decoder: n source bytes, low nibble first, to 2n s16 samples,
 * with the predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C.
 *
 * symbols:
 *   d_021B3A0C     0x021B3A0C  data  ov013  a1
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

extern const s8 d_021B3A0C[16];
extern const s16 d_021B3A1C[89];

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

void func_021AF340(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = AdpcmDecodeNibble(st, *src & 0xF);
        *dst++ = AdpcmDecodeNibble(st, (*src >> 4) & 0xF);
        src++;
    }
}
