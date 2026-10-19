/*
 * function: procInit1
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
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C3358  0x021C3358  arm  ov016
 *   DWCi_SceneOptMovComm_procScene  0x021C3280  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_MOVlChangeCallback(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3358(int state);
extern void DWCi_SceneOptMovComm_procScene(void);

void procInit1(void)
{
	if (DWCi_EFFlCheck(0))
		return;
	DWCi_MOVlChangeCallback((unsigned int)func_021C3358);
	DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovComm_procScene);
}
