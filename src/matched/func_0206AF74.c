/*
 * function: func_0206AF74
 * address:  0x0206AF74
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Mixes two three-word vectors into dst: with `flag` set it just adds the
 * scalar v to each word, otherwise it accumulates the 12.12 fixed-point
 * product (v * src[i]) >> 12.
 *
 * `dst` must be spelled `volatile`: with a plain `s32 *` mwcc schedules the
 * two arms differently.  The plain-pointer spelling matches the `else` arm
 * exactly (ldr src, ldr dst, mul, add, str) but groups the `if` arm into
 * three hoisted loads, three adds and three stores; the volatile spelling
 * reproduces the original's strictly sequential ldr/add/str per word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AF74.c \
 *       --func func_0206AF74 --addr 0x0206AF74 --arm --cc 1.1p1
 */

typedef signed int s32;

void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag)
{
    if (flag) {
        dst[0] += v;
        dst[1] += v;
        dst[2] += v;
    } else {
        dst[0] += (v * src[0]) >> 12;
        dst[1] += (v * src[1]) >> 12;
        dst[2] += (v * src[2]) >> 12;
    }
}
