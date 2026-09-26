/*
 * function: func_021C4714
 * address:  0x021C4714
 * packet:   pkt_021C4714
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
 *   func_021BCAE4  0x021BCAE4  arm
 *   func_021D55A4  0x021D55A4  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021C4794  0x021C4794  arm
 *   g_021DE5C8     0x021DE5C8  data
 */

typedef unsigned char u8;

extern int  func_021D5580(int x);
extern int  func_021C11B8(void);
extern void func_021BCAE4(void);
extern void func_021D55A4(int a, int b, int c, int d);
extern void func_021C0E40(void *p);
extern void func_021C4794(void);
extern u8   g_021DE5C8[];

void func_021C4714(void)
{
    if (func_021D5580(1) != 0)
        return;
    if (g_021DE5C8[0] == 0) {
        if (func_021C11B8() == 0)
            return;
    }
    func_021BCAE4();
    if (g_021DE5C8[0] == 0)
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40(func_021C4794);
}
