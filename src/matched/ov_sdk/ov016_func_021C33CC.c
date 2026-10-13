/*
 * function: DWCi_SceneOptMovComplete
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
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C3454  0x021C3454  arm  ov016
 */

extern void func_021C33EC(void);
extern void DWCi_CMNlMsgDraw(int msg);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3454(void);

void DWCi_SceneOptMovComplete(void)
{
	func_021C33EC();
	DWCi_CMNlMsgDraw(0x1f);
	DWCi_ChangeScene((unsigned int)func_021C3454);
}
