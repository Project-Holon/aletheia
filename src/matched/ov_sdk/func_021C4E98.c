/*
 * function: func_021C4E98
 * address:  0x021C4E98
 * packet:   pkt_021C4E98
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4E98 0x021C4E98 arm
 *
 * Tear down the sequence and post the event at 0x021C4C60.
 * Addresses are Black-image addresses.
 */

extern void func_021D0014(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(void *);

void func_021C4E98(void)
{
    func_021D0014();
    func_021CFFAC(7);
    *(unsigned char *)0x021DE5CC = 0;
    func_021C0E40((void *)0x021C4C60);
}
