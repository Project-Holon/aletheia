/*
 * function: func_021C4890
 * address:  0x021C4890
 * packet:   pkt_ov016_021C4890
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbMov (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 *
 * symbols:
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C8     0x021DE5C8  data
 *   func_021C46DC  0x021C46DC  arm  ov016
 */

extern void func_021D0014();
extern void func_021CFFAC();
extern void func_021C11D4();
extern void func_021C0E40();
extern void func_021C46DC();
extern unsigned char g_021DE5C8;

void func_021C4890(int state)
{
    func_021D0014();
    if (state == 0) {
        g_021DE5C8 = 1;
        func_021CFFAC(0x10);
    } else {
        g_021DE5C8 = 2;
        func_021CFFAC(0x12);
    }
    func_021C11D4(0);
    func_021C0E40(func_021C46DC);
}
