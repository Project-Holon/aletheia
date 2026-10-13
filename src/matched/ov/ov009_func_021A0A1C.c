/*
 * function: SBServerListSetLastError
 * address:  0x021A0A1C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0x6b0.
 */

void SBServerListSetLastError(int *p, int v)
{
    p[0x1ac] = v;
}
