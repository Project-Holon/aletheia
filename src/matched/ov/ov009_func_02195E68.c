/*
 * function: gt2SetUnrecognizedMessageCallback
 * address:  0x02195E68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0x30.
 */

void gt2SetUnrecognizedMessageCallback(int *p, int v)
{
    p[0xc] = v;
}
