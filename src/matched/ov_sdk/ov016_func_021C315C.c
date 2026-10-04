/*
 * function: func_021C315C
 * address:  0x021C315C
 * packet:   pkt_ov016_021C315C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovComm (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   func_021C3194  0x021C3194  arm  ov016
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021BC820  0x021BC820  arm  ov016
 *   func_021BD744  0x021BD744  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C3214  0x021C3214  arm  ov016
 */

extern void func_021C3194(void);
extern void func_021BD29C(int msg);
extern void func_021BC820(int color);
extern void func_021BD744(int type);
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C3214(void);

void func_021C315C(void)
{
	func_021C3194();
	func_021BD29C(0x1e);
	func_021BC820(0);
	func_021BD744(1);
	func_021CFFAC(0xb);
	func_021C0E40((unsigned int)func_021C3214);
}
