/*
 * file:     sb_server_3.c
 * function: func_0219E1F4
 * address:  0x0219E1F4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword at +4 with its two bytes exchanged.
 */

unsigned short func_0219E1F4(const unsigned short *p)
{
    int v = p[2];

    return (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
}
