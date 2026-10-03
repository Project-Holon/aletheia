/*
 * function: func_021C67CC
 * address:  0x021C67CC
 * packet:   pkt_021C67CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021BD8D8  0x021BD8D8  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021BDC68  0x021BDC68  arm
 *   func_021BDC7C  0x021BDC7C  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5E0     0x021DE5E0  data
 *   func_021C684C  0x021C684C  arm
 */

typedef unsigned char u8;

extern int  func_021D5580(int x);
extern void func_021BD8D8(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021BDC68(unsigned char v);
extern void func_021BDC7C(unsigned char v);
extern void func_021C0E40(void *p);
extern u8  *g_021DE5E0;
extern void func_021C684C(void);

void func_021C67CC(void)
{
    u8 *p;

    if (func_021D5580(1) != 0)
        return;
    if (func_021D5580(0) != 0)
        return;
    func_021BD8D8();
    func_021CFFAC(0x14);
    p = g_021DE5E0;
    if (p[0x29] == 0)
        func_021BDC68(0);
    p = g_021DE5E0;
    if (p[0x29] == 0x20)
        func_021BDC7C(0);
    func_021C0E40(func_021C684C);
}
