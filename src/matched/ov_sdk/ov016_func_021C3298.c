/*
 * function: func_021C3298
 * address:  0x021C3298
 * packet:   pkt_ov016_021C3298
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C32C0  0x021C32C0  arm  ov016
 */

extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern void func_021C32C0(void);

void func_021C3298(void)
{
	func_021D55A4(3, 0, 0x15, 8);
	func_021C0E40((unsigned int)func_021C32C0);
}
