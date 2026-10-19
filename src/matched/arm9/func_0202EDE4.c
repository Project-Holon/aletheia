/*
 * function: SCROLLBAR_GetValueFromPos
 * address:  0x0202EDE4
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f      0x0209C2B0  arm
 *
 * Maps v into the band [a2+w/2, a3-w/2] of a0, 0 below it and a0 above it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SCROLLBAR_GetValueFromPos.c \
 *       --func SCROLLBAR_GetValueFromPos --addr 0x0202EDE4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 _u32_div_f(u32 a, u32 b);

u32 SCROLLBAR_GetValueFromPos(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h  = a4 >> 1;
    u32 lo = a2 + h;
    u32 hi = a3 - h;
    u32 n;

    if (a1 <= lo)
        return 0;
    if (a1 >= hi)
        return a0;

    n = a1 - lo;
    return (n * (a0 << 8) / (hi - lo)) >> 8;
}
