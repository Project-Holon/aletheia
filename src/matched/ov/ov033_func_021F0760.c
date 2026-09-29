/*
 * function: func_021F0760
 * address:  0x021F0760
 * packet:   pkt_ov033_021F0760
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */

extern unsigned func_020490F4(unsigned, unsigned);
extern void func_02049BDC(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_02049740(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_02049990(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_02049238(unsigned);
extern void func_020413B0(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_02041B6C(unsigned);

void func_021F0760(char *p)
{
    unsigned h = *(unsigned short *)(p + 2);
    unsigned a = func_020490F4(0xC3, h);
    unsigned b;
    func_02049BDC(a, 0, 4, 0, 0, 0x40, h);
    b = func_02049740(a, 2, 7, 0, 0, h);
    func_02049990(a, 7, 7, 0, (unsigned short)b, 0, 0, h);
    func_02049238(a);
    func_020413B0(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    *(unsigned *)(p + 0x10) = b;
}
