/*
 * function: MSL_C_LIB_ShouldRoundUp
 * address:  0x020965B4
 * packet:   pkt_020965B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;

int MSL_C_LIB_ShouldRoundUp(u8 *p, int i)
{
    u8 *q = p + 5 + i;

    if (q[0] > 5) return 1;
    if (q[0] < 5) return -1;
    for (q++; q < p + 5 + p[4]; q++) {
        if (*q) return 1;
    }
    return ((p + 5)[i - 1] & 1) ? 1 : -1;
}
