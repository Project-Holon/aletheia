/*
 * function: func_0202B194
 * address:  0x0202B194
 * packet:   pkt_0202AFFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */

typedef int s32;

s32 func_0202B194(s32 a, s32 b, s32 c, s32 d, s32 e)
{
    return b + (d - b) * (e - a) / (c - a);
}
