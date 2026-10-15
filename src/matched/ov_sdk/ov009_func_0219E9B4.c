/*
 * function: SBServerSetPrivateAddr
 * address:  0x0219E9B4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +8 and a halfword at +0xc.
 */

void SBServerSetPrivateAddr(char *p, int v, unsigned short w)
{
    *(int *)(p + 8) = v;
    *(unsigned short *)(p + 0xc) = w;
}
