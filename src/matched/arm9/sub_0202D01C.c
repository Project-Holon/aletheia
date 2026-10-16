/*
 * function: BGWINFRM_ScaleRatio
 * address:  0x0202D01C
 * packet:   pkt_0202CC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c)
{
    u8 res = (a * c) / b;

    if (res != 0 || a == 0) {
        return res;
    }
    return 1;
}
