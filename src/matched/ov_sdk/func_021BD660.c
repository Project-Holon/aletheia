/*
 * function: func_021BD660
 * address:  0x021BD660
 * packet:   pkt_021BD660
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BD660 0x021BD660 arm
 *
 * Tail-call func_021D6438 with the address of 0x021DE554.
 * Addresses are Black-image addresses.
 */

extern void func_021D6438(void **mem);

void func_021BD660(void)
{
    func_021D6438((void *)0x021DE554);
}
