/*
 * function: func_021C14F4
 * address:  0x021C14F4
 * packet:   pkt_021C14F4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C14F4 0x021C14F4 arm
 *   func_021BC724 0x021BC724 thumb
 *
 * Post the event at 0x021DE594 when func_021BC724 does not report one.
 * Addresses are Black-image addresses.
 */

extern int func_021BC724(void);
extern void func_02088234(void);
extern void func_021D6438(void **mem);

void func_021C14F4(void)
{
    if (func_021BC724() != 1)
        func_02088234();
    func_021D6438((void *)0x021DE594);
}
