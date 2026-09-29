/*
 * function: func_021C3358
 * address:  0x021C3358
 * packet:   pkt_ov016_021C3358
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbMov (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   func_021CFC20  0x021CFC20  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021C115C  0x021C115C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5B4  0x021DE5B4  data
 *   func_021C3298  0x021C3298  arm  ov016
 */

extern void func_021CFC20(void);
extern void func_021D0014(void);
extern void func_021CFFAC(int no);
extern void func_021C11D4(void (*callback)(int));
extern void func_021C115C(void);
extern void func_021C0E40(void (*scene)());
extern void func_021C3298(void);
extern unsigned char g_021DE5B4;

void func_021C3358(int state)
{
	if (state == 2) {
		func_021CFC20();
		g_021DE5B4 = 1;
		func_021D0014();
		func_021CFFAC(0x10);
	} else if (state == 3) {
		g_021DE5B4 = 2;
		func_021D0014();
		func_021CFFAC(0x12);
	} else {
		g_021DE5B4 = 0;
		func_021D0014();
		func_021CFFAC(0x12);
	}
	func_021C11D4(0);
	func_021C115C();
	func_021C0E40(func_021C3298);
}
