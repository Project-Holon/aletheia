/*
 * function: func_021D556C
 * address:  0x021D556C
 * packet:   pkt_021D556C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D556C 0x021D556C arm
 *
 * Tail-call func_021D6438 with the address of 0x021DE67C.
 * Addresses are Black-image addresses.
 */

extern void func_021D6438(void **mem);

void func_021D556C(void)
{
    func_021D6438((void *)0x021DE67C);
}
