/*
 * function: func_021CA560
 * address:  0x021CA560
 * packet:   pkt_021CA560
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA560   0x021CA560  arm
 *   func_021D1568   0x021D1568  arm
 *   func_021CFFAC   0x021CFFAC  arm
 *   func_021D1524   0x021D1524  arm
 *   func_021CE818   0x021CE818  arm
 *   func_021C0E40   0x021C0E40  arm
 *
 * Gate on the driver state, then reset the shared block and hand the next state off.
 * Addresses are Black-image addresses.
 */

extern int func_021D1568(void);
extern void func_021CFFAC(int);
extern void func_021D1524(void);
extern void func_021CE818(int);
extern void func_021C0E40(int);

void func_021CA560(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;

    if (func_021D1568() != 0)
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021CE818(*(int *)(*(int *)(g + 8) + 0xc));
    func_021C0E40(0x021CA5A0);
}

