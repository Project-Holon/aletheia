/*
 * function: FIFOClear
 * address:  0x0219D5B0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the two words and the word after them.
 */

void FIFOClear(int *p)
{
    p[1] = 0;
    p[0] = 0;
    p[2] = 0;
}
