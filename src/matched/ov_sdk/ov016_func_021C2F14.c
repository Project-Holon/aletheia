/*
 * function: func_021C2F14
 * address:  0x021C2F14
 * packet:   pkt_ov016_021C2F14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C2F34  0x021C2F34  arm  ov016
 */

extern void func_021BCB9C(void);
extern int func_021D5790(int frame);
extern void func_021C0E40(void (*scene)());
extern void func_021C2F34(void);

void func_021C2F14(void)
{
	func_021BCB9C();
	func_021D5790(8);
	func_021C0E40(func_021C2F34);
}
