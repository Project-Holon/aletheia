/*
 * function: func_021AF628
 * address: 0x021AF628
 * packet: pkt_ov013_021AF628
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Byte locals for all three packed input bytes reproduce the spilled step
 * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail.
 * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first.
 * symbols:
 *   d_021B3A04 0x021B3A04 data ov013 a1
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
extern const s8 d_021B3A04[8];
extern const s16 d_021B3A1C[89];
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
