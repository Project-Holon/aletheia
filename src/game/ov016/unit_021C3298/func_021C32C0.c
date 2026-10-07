/*
 * function: func_021C32C0
 * address:  0x021C32C0
 * packet:   pkt_021C32C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm
 *   func_021C11B8  0x021C11B8  arm
 *   func_021BD7F4  0x021BD7F4  arm
 *   func_021BC8EC  0x021BC8EC  arm
 *   func_021D5CA8  0x021D5CA8  arm
 *   func_021D6090  0x021D6090  arm
 *   func_021C0E50  0x021C0E50  arm
 *   func_021C0E40  0x021C0E40  arm
 *   g_021DE5B4     0x021DE5B4  data
 *   func_021C3D8C  0x021C3D8C  arm
 *   func_021C3B8C  0x021C3B8C  arm
 *   func_021C33CC  0x021C33CC  arm
 */

typedef unsigned char u8;

extern int  func_021D5580(int x);
extern int  func_021C11B8(void);
extern void func_021BD7F4(void);
extern void func_021BC8EC(void);
extern void func_021D5CA8(int x);
extern void func_021D6090(int a, int b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E40(unsigned int v);
extern u8   g_021DE5B4[];
extern void func_021C3D8C(void);
extern void func_021C3B8C(void);
extern void func_021C33CC(void);

void func_021C32C0(void)
{
    if (func_021D5580(0) != 0)
        return;
    if (func_021C11B8() == 0)
        return;
    func_021BD7F4();
    func_021BC8EC();
    func_021D5CA8(0);
    func_021D6090(0, 0x15);
    func_021C0E50(0, 1);
    if (g_021DE5B4[0] == 0) {
        func_021C0E40((unsigned int)func_021C3D8C);
        return;
    }
    if (g_021DE5B4[0] == 2) {
        func_021C0E40((unsigned int)func_021C3B8C);
        return;
    }
    func_021C0E40((unsigned int)func_021C33CC);
}
