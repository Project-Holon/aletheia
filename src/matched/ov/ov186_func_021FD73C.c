/*
 * function: BR_UTIL_SetTaskStep
 * address:  0x021FD73C
 * packet:   pkt_021FD73C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int *BR_UTIL_SetTaskStep(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
    return p;
}
