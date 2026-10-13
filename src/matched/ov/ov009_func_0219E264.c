/*
 * function: SBServerSetNext
 * address:  0x0219E264
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0x24.
 */

void SBServerSetNext(int *p, int v)
{
    p[9] = v;
}
