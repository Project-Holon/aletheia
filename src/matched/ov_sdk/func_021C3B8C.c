/*
 * function: func_021C3B8C
 * address:  0x021C3B8C
 * packet:   pkt_021C3B8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C3B8C 0x021C3B8C arm
 *
 * Clear the counter, reset the sub-state and post the event at 0x021C3C28.
 * Addresses are Black-image addresses.
 */

extern void func_021C3BBC(void);
extern void func_021BD29C(int);
extern void func_021C0E40(unsigned int v);

void func_021C3B8C(void)
{
    *(unsigned char *)0x021DE5BC = 0;
    func_021C3BBC();
    func_021BD29C(0x21);
    func_021C0E40((unsigned int)((void *)0x021C3C28));
}
