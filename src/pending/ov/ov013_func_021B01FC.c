/*
 * function: func_021B01FC
 * address: 0x021B01FC
 * packet: pkt_ov013_021B01FC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * 2026-10-05 (wave P3 R6): DIFF, 576 B compiled (size, push list, frame and 2-literal
 * pool match; 323 B differ). Draft of the 4-bit-twin shape: u8 helper, accumulator byte
 * `a |= code << 2k`, loop test `i < n / 4`. Residue: register colours (image: step table r5,
 * index table ip, -32768 r4, 32767 lr; ours r4, r2, lr, ip) and pool word order (image
 * 3A1C first, ours 3A00 first; same residue as the 3-bit encoder func_021AFABC).
 * Tries (16 compiles): four u8 locals then one OR (580 B, frame 0xc); int helper return
 * (564 B); declaration order of step/idx; diff before step load; inner j<4 loop (not
 * unrolled, 260 B, but flips the pool order to 3A1C first); *src++ walk (250 B differ,
 * but the image indexes src with offsets and adds 8 once); six per-function pragmas
 * (no gain). Idioms checked: a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (matches the diagnosis, no source lever found).
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
    int step;
    int diff;
    int code;
    int delta;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    step = d_021B3A1C[idx];
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= step) {
        code |= 1;
    }
    delta = step;
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    pred += delta;
    if (pred < -32768) pred = -32768;
    if (pred > 32767) pred = 32767;
    idx += d_021B3A00[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)pred;
    st->index = idx;
    return code;
}
void func_021B01FC(u8 *dst, const s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    for (i = 0; i < n / 4; i++) {
        a = Adpcm2EncodeSample(st, src[0]);
        a |= Adpcm2EncodeSample(st, src[1]) << 2;
        a |= Adpcm2EncodeSample(st, src[2]) << 4;
        a |= Adpcm2EncodeSample(st, src[3]) << 6;
        *dst++ = a;
        src += 4;
    }
}
