/*
 * function: func_021C0E8C
 * address:  0x021C0E8C
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0E8C   0x021C0E8C  arm
 *
 * Store two words into fields +0x18 and +0x1c of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E8C.c \
 *       --func func_021C0E8C --addr 0x021C0E8C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021C0E8C(unsigned int a, unsigned int b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[6] = a;
    p[7] = b;
}
