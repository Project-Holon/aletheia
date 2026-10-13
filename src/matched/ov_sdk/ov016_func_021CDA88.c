/*
 * function: DWCi_SceneSetUsbComplete
 * address:  0x021CDA88
 * packet:   pkt_ov016_021CDA88
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetUsbComplete (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA88.c \n *       --func DWCi_SceneSetUsbComplete --addr 0x021CDA88 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gSceneSetUsbCompleteWork     0x021DE624  data
 *   func_021CDAC8  0x021CDAC8  arm  ov016
 *   DWCi_HLlLoad  0x021BD674  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CDB48  0x021CDB48  arm  ov016
 */

extern unsigned char gSceneSetUsbCompleteWork;
extern void func_021CDAC8(void);
extern void DWCi_HLlLoad(int idx);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CDB48(void);

void DWCi_SceneSetUsbComplete(void)
{
    gSceneSetUsbCompleteWork = 0;
    func_021CDAC8();
    DWCi_HLlLoad(8);
    DWCi_CMNlMsgDraw(41);
    DWCi_SNDlPlay(16);
    DWCi_ChangeScene((unsigned int)func_021CDB48);
}
