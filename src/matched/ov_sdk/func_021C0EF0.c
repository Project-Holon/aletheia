/*
 * function: func_021C0EF0
 * address:  0x021C0EF0
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0EF0   0x021C0EF0  arm
 *
 * Test the argument against bits 4.. of the word at +0x08.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EF0.c \
 *       --func func_021C0EF0 --addr 0x021C0EF0 --region ov016 --cc dsi/1.1p1 --arm
 */

int func_021C0EF0(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    return (v & (p[2] >> 4)) != 0;
}
