/*
 * function: DWCi_SceneOptMovComm
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
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   DWCi_ICONlInit  0x021BD744  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C3214  0x021C3214  arm  ov016
 */

extern void func_021C3194(void);
extern void DWCi_CMNlMsgDraw(int msg);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_ICONlInit(int type);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3214(void);

void DWCi_SceneOptMovComm(void)
{
	func_021C3194();
	DWCi_CMNlMsgDraw(0x1e);
	DWCi_ANIMElInitEx(0);
	DWCi_ICONlInit(1);
	DWCi_SNDlPlay(0xb);
	DWCi_ChangeScene((unsigned int)func_021C3214);
}
