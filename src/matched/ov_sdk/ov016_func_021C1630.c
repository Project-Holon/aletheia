/*
 * function: func_021C1630
 * address:  0x021C1630
 * packet:   pkt_ov016_021C1630
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneEnd (libdwcutil.TWL.HYB.a(sceneend.o))
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C1678  0x021C1678  arm  ov016
 */

extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(void (*scene)());
extern void func_021C1678(void);

void func_021C1630(void)
{
	func_021D55A4(3, 1, 0x3f, 0x14);
	func_021D55A4(3, 0, 0x3f, 0x14);
	func_021C0E40(func_021C1678);
}
