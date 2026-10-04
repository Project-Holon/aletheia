/*
 * function: func_021C3FF4
 * address:  0x021C3FF4
 * packet:   pkt_ov016_021C3FF4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C0     0x021DE5C0  data
 *   func_021C405C  0x021C405C  arm  ov016
 */

extern int func_021D5580();
extern void func_021BCAE4();
extern void func_021D55A4();
extern void func_021C0E40(unsigned int v);
extern void func_021C405C();
extern unsigned char g_021DE5C0[];

void func_021C3FF4(void)
{
    if (func_021D5580(1))
        return;
    func_021BCAE4();
    if (!g_021DE5C0[1])
        func_021D55A4(3, 1, 1, 8);
    func_021D55A4(3, 0, 0x15, 8);
    func_021C0E40((unsigned int)func_021C405C);
}
