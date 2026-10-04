/*
 * function: func_021C3F84
 * address:  0x021C3F84
 * packet:   pkt_ov016_021C3F84
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021C3FD4  0x021C3FD4  arm  ov016
 */

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C3FD4();
extern unsigned char g_021DE5C0[];

void func_021C3F84(void)
{
    int r = func_021BCB14();
    if (r != 0) {
        if (r != 1)
            return;
        g_021DE5C0[1] = 1;
        func_021CFFAC(6);
    } else {
        g_021DE5C0[1] = 0;
        func_021CFFAC(7);
    }
    func_021C0E40((unsigned int)func_021C3FD4);
}
