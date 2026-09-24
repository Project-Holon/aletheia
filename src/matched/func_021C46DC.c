/*
 * function: func_021C46DC
 * address:  0x021C46DC
 * packet:   pkt_021C46DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C46DC 0x021C46DC arm
 *
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */

extern void func_021C115C(void);
extern void func_021BCB9C(void);
extern void func_021D5790(int);
extern void func_021C0E40(void *);

void func_021C46DC(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        func_021C115C();
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((void *)0x021C4714);
}
