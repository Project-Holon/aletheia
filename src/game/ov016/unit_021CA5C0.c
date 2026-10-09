/*
 * file:     unit_021CA5C0.c
 * function: func_021CA5C0
 * address:  0x021CA5C0
 * packet:   pkt_021CA5C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA5C0   0x021CA5C0  arm
 *
 * Store a byte at 0x021DE5EC + 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CA5C0.c \
 *       --func func_021CA5C0 --addr 0x021CA5C0 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021CA5C0(unsigned char v)
{
    unsigned char *p = (unsigned char *)0x021DE5EC;
    p[1] = v;
}
