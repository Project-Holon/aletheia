/*
 * function: func_021C18C4
 * address:  0x021C18C4
 * packet:   pkt_ov016_021C18C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procFade (libdwcutil.TWL.HYB.a(sceneinit.o))
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C1908  0x021C1908  arm  ov016
 */

extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(void (*scene)());
extern void func_021C1908(void);

void func_021C18C4(void)
{
	func_021D55A4(2, 1, 2, 0x14);
	func_021D55A4(2, 0, 2, 0x14);
	func_021C0E40(func_021C1908);
}
