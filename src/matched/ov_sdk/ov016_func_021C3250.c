/*
 * function: func_021C3250
 * address:  0x021C3250
 * packet:   pkt_ov016_021C3250
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C3358  0x021C3358  arm  ov016
 *   DWCi_SceneOptMovComm_procScene  0x021C3280  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021C11D4(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021C3358(int state);
extern void DWCi_SceneOptMovComm_procScene(void);

void func_021C3250(void)
{
	if (func_021D5580(0))
		return;
	func_021C11D4((unsigned int)func_021C3358);
	func_021C0E40((unsigned int)DWCi_SceneOptMovComm_procScene);
}
