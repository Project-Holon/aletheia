/*
 * function: func_02069184
 * address:  0x02069184
 * packet:   pkt_02068FF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 39 bytes of 92: the original seeds the product chain with an explicit zero (`mov r2,#0` then `mla lr, r3, r5, r2`); every spelling here - `u32 r = 0;` with `+=`, a one-expression sum, `int` accumulator - is folded to a bare `mul ip, r3, r5` and the whole chain shifts by one register
 *
 * Integer bilinear interpolation of the sub-tile fraction pair (x, y): the
 * integer parts are x >> 3 and y >> 3, the fractions are the three low bits
 * split as (bit0 + bit1) and bit2, and the four products are accumulated into
 * one register chain exactly as written here (the chain starts from an
 * explicit zero, which is what puts the addend in a register instead of
 * letting the first product be a bare `mul`).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02069184.c \
 *       --func func_02069184 --addr 0x02069184 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 func_02069184(u32 x, u32 y)
{
    u32 xh = x >> 3;
    u32 yh = y >> 3;
    u32 a = (x & 1) + ((x & 2) >> 1);
    u32 b = (y & 1) + ((y & 2) >> 1);
    u32 c = (x & 4) >> 2;
    u32 d = (y & 4) >> 2;
    u32 r = 0;

    r += xh * yh;
    r += yh * (a * 2 + c);
    r += xh * (b * 2 + d);
    return r + (a + c) * (b + d);
}
