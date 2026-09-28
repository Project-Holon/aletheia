/*
 * function: func_021C0F98
 * address:  0x021C0F98
 * packet:   pkt_021C0E40
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0F98   0x021C0F98  arm
 *
 * Tail-call func_021D6438 with the address of 0x021DE58C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0F98.c \
 *       --func func_021C0F98 --addr 0x021C0F98 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D6438(void *);

void func_021C0F98(void)
{
    func_021D6438((void *)0x021DE58C);
}
