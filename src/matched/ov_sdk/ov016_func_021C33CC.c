/*
 * function: func_021C33CC
 * address:  0x021C33CC
 * packet:   pkt_ov016_021C33CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovComplete (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 *
 * symbols:
 *   func_021C33EC  0x021C33EC  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C3454  0x021C3454  arm  ov016
 */

extern void func_021C33EC(void);
extern void func_021BD29C(int msg);
extern void func_021C0E40(void (*scene)());
extern void func_021C3454(void);

void func_021C33CC(void)
{
	func_021C33EC();
	func_021BD29C(0x1f);
	func_021C0E40(func_021C3454);
}
