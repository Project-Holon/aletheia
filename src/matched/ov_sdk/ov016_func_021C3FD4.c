/*
 * function: func_021C3FD4
 * address:  0x021C3FD4
 * packet:   pkt_ov016_021C3FD4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C3FF4  0x021C3FF4  arm  ov016
 */

extern void func_021BCB9C();
extern void func_021D5790();
extern void func_021C0E40(unsigned int v);
extern void func_021C3FF4();

void func_021C3FD4(void)
{
    func_021BCB9C();
    func_021D5790(8);
    func_021C0E40((unsigned int)func_021C3FF4);
}
