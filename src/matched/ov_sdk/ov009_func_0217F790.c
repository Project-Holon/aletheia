/*
 * function: Util_RandSeed
 * address:  0x0217F790
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * probe
 *
 * symbols:
 *   gGsRandState  0x021A37C8  data
 */

extern char gGsRandState[];

void Util_RandSeed(unsigned int v)
{
    *(int *)gGsRandState = v ? (int)(v & 0x7fffffff) : 1;
}

