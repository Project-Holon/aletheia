/*
 * function: longrand
 * address:  0x0217F774
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Refreshes the word the state object holds.
 *
 * symbols:
 *   gGsRandState  0x021A37C8  data
 *   nextlongrand  0x0217F730  arm  ov009
 */

extern char gGsRandState[];
extern int nextlongrand(int v);

void longrand(void)
{
    *(int *)gGsRandState = nextlongrand(*(int *)gGsRandState);
}

