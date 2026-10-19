/*
 * function: endScene
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
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   DWCi_EFFlWait  0x021D5790  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C2F34  0x021C2F34  arm  ov016
 */

extern void DWCi_BTNlDisable(void);
extern int DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C2F34(void);

void endScene(void)
{
	DWCi_BTNlDisable();
	DWCi_EFFlWait(8);
	DWCi_ChangeScene((unsigned int)func_021C2F34);
}
