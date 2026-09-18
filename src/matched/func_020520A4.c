/*
 * function: func_020520A4
 * address:  0x020520A4
 * packet:   pkt_020520A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Three signed fixed-point multiplies of a 3-vector by one scalar, each with
 * the +0x800 round term, then >> 12 back to 32 bits: the `smull`/`adds`/`adc`
 * pair per lane is the 64-bit product, and `lsr #12` + `orr ... lsl #20` is the
 * 64-bit shift truncated back to a word.  No calls and no pool - the whole
 * function is 88 bytes of straight-line code.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520A4.c \
 *       --func func_020520A4 --addr 0x020520A4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

void func_020520A4(int *v, int s, int *out)
{
    out[0] = (int)(((long long)v[0] * s + 0x800) >> 12);
    out[1] = (int)(((long long)v[1] * s + 0x800) >> 12);
    out[2] = (int)(((long long)v[2] * s + 0x800) >> 12);
}
