/*
 * function: func_021C0E40
 * address:  0x021C0E40
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0E40   0x021C0E40  arm
 *
 * Store a word into the global object at 0x021DE56C, field +0x0c.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E40.c \
 *       --func func_021C0E40 --addr 0x021C0E40 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021C0E40(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[3] = v;
}
