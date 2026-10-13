/*
 * function: DWCi_SceneSetAossComplete
 * address:  0x021C4EC8
 * packet:   pkt_ov016_021C4EC8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetAossComplete (libdwcutil.TWL.HYB.a scenesetaosscomplete.o)
 *
 * symbols:
 *   func_021C4F04  0x021C4F04  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneSetAossCompleteWork     0x021DE5D4  data
 *   func_021C4F70  0x021C4F70  arm  ov016
 */

extern void func_021C4F04();
extern void DWCi_HLlLoadSet();
extern void DWCi_CMNlMsgDraw();
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C4F70();
extern unsigned char gSceneSetAossCompleteWork;

void DWCi_SceneSetAossComplete(void)
{
    gSceneSetAossCompleteWork = 0;
    func_021C4F04();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x23);
    DWCi_SNDlPlay(0x10);
    DWCi_ChangeScene((unsigned int)func_021C4F70);
}
