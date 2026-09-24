/*
 * function: func_021D551C
 * address:  0x021D551C
 * packet:   pkt_021D551C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D551C 0x021D551C arm
 *
 * Allocate a 0x18-byte block, publish it, and clear two 0x1000-wide register spans.
 * Addresses are Black-image addresses.
 */

extern void *func_021D6414(int, int);
extern void func_0207D658(unsigned short *, int, int);

void func_021D551C(void)
{
    unsigned short *p;

    *(int *)0x021DE67C = (int)func_021D6414(0x18, 4);
    p = (unsigned short *)0x04000050;
    func_0207D658(p, 0x3f, 0x10);
    func_0207D658(p + 0x800, 0x3f, 0x10);
}

