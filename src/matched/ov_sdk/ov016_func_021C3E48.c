/*
 * function: func_021C3E48
 * address:  0x021C3E48
 * packet:   pkt_ov016_021C3E48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021C3EC4  0x021C3EC4  arm  ov016
 */

extern void func_021D55A4();
extern void func_021D603C(int lcd, int plane);
extern void func_021C0E40();
extern void func_021C3EC4();
extern unsigned char g_021DE5C0;

void func_021C3E48(void)
{
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(0, 0x15);
    if (g_021DE5C0) {
        func_021D55A4(2, 1, 1, 8);
        func_021D603C(1, 1);
    }
    func_021C0E40(func_021C3EC4);
}
