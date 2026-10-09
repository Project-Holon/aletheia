/*
 * file:     unit_0219E220.c
 * function: func_0219E220
 * address:  0x0219E220
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tests bit 1 of the byte at +0x15.
 */

int func_0219E220(const unsigned char *p)
{
    return (p[0x15] & 2) == 2;
}
