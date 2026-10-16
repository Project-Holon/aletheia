/*
 * function: BGWINFRM_GetScaleRank
 * address:  0x0202D034
 * packet:   pkt_0202CC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned int u32;

int BGWINFRM_GetScaleRank(u32 a, u32 b)
{
    a <<= 8;
    b <<= 8;

    if (a > b / 2) {
        return 0;
    }
    if (a > b / 5) {
        return 1;
    }
    if (a != 0) {
        return 2;
    }
    return 3;
}
