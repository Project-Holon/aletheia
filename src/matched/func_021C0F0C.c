/*
 * function: func_021C0F0C
 * address:  0x021C0F0C
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0F0C   0x021C0F0C  arm
 *
 * Set byte +0x01 of the global object to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0F0C.c \
 *       --func func_021C0F0C --addr 0x021C0F0C --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021C0F0C(void)
{
    unsigned char *p = (unsigned char *)0x021DE56C;
    p[1] = 1;
}
