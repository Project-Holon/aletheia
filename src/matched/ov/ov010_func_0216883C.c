/*
 * function: func_0216883C
 * address:  0x0216883C
 * packet:   pkt_ov010_0216883C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: func_02168924
 * stores the result to its u8 local without an extension.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 func_0216883C(u32 n)
{
    if (n < 50)
        return 3;
    if (n < 70)
        return 6;
    if (n < 90)
        return 9;
    if (n < 110)
        return 12;
    if (n < 160)
        return 15;
    if (n < 180)
        return 18;
    if (n < 200)
        return 21;
    return 31;
}
