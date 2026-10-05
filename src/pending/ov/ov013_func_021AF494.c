/*
 * function: func_021AF494
 * address:  0x021AF494
 * packet:   pkt_ov013_021AF494
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders func_021AF340 and func_021AF628.
 *
 * 2026-10-05 (wave P5 T10): size exact (404 B), prologue, loop and every
 * statement match. Residue is colour only: the halved count is in r5 here
 * and r8 in the image (image temps: code r5, idx r6, pred r7, step sb; ours
 * code r6, step r7, idx r8, pred sb). Declaration order of half/i/lo/hi, n /= 2,
 * u8 code, int return, and the six per-function pragmas were tried (best 226 B
 * differ; opt_propagation off 188 B but also changes code). The tail needs
 * lo | (u8)(hi << 4) to get the and/lsl/and; the late and on lo is still missing.
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

static inline u8 AdpcmEncodeSample(AdpcmState *st, int sample)
{
    int pred;
    int idx;
    int step;
    int diff;
    int code;
    int vp;

    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
    diff = sample - pred;
    if (diff < 0) {
        code = 8;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= step) {
        code |= 4;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 2;
        diff -= step >> 1;
    }
    if (diff >= (step >> 2)) {
        code |= 1;
    }
    vp = step >> 3;
    if (code & 4) {
        vp += step;
    }
    if (code & 2) {
        vp += step >> 1;
    }
    if (code & 1) {
        vp += step >> 2;
    }
    if (code & 8) {
        vp = -vp;
    }
    pred += vp;
    if (pred < -32768) {
        pred = -32768;
    }
    if (pred > 32767) {
        pred = 32767;
    }
    idx += d_021B3A0C[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->index = idx;
    st->pred = (s16)pred;
    return code;
}

void func_021AF494(u8 *dst, const s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u32 half;
    u8 lo;
    u8 hi;

    half = n / 2;
    for (i = 0; i < half; i++) {
        lo = AdpcmEncodeSample(st, src[0]);
        hi = AdpcmEncodeSample(st, src[1]);
        src += 2;
        *dst++ = lo | (u8)(hi << 4);
    }
}
