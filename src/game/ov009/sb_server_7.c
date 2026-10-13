/*
 * file:     sb_server_7.c
 * function: func_0219E240
 * address:  0x0219E240
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword at +0xc with its two bytes exchanged.
 */

unsigned short func_0219E240(const unsigned short *p)
{
    int v = p[6];

    return (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
}
