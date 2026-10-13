/*
 * function: DWCi_RAKUlEnd
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
 *   DWCi_RAKUlEnd 0x021C14F4 arm
 *   func_021BC724 0x021BC724 thumb
 *   OS_Terminate  0x02088234  arm  arm9
 *   DWCi_HEAPlFree_  0x021D6438  arm
 *
 * Post the event at 0x021DE594 when func_021BC724 does not report one.
 * Addresses are Black-image addresses.
 */

extern int func_021BC724(void);
extern void OS_Terminate(void);
extern void DWCi_HEAPlFree_(void **mem);

void DWCi_RAKUlEnd(void)
{
    if (func_021BC724() != 1)
        OS_Terminate();
    DWCi_HEAPlFree_((void *)0x021DE594);
}
