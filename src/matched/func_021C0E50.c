/*
 * function: func_021C0E50
 * address:  0x021C0E50
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0E50   0x021C0E50  arm
 *
 * Store two words into fields +0x10 and +0x14 of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E50.c \
 *       --func func_021C0E50 --addr 0x021C0E50 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021C0E50(unsigned int a, unsigned int b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[4] = a;
    p[5] = b;
}
