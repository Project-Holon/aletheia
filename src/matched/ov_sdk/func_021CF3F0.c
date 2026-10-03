/*
 * function: func_021CF3F0
 * address:  0x021CF3F0
 * packet:   pkt_021CF3F0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CF3F0   0x021CF3F0  arm
 *
 * Tail-call func_021D6438 with the address of 0x021DE644.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CF3F0.c \
 *       --func func_021CF3F0 --addr 0x021CF3F0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D6438(void **mem);

void func_021CF3F0(void)
{
    func_021D6438((void *)0x021DE644);
}
