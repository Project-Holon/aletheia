/*
 * function: procScene
 * address:  0x021CD9CC
 * packet:   pkt_ov016_021CD9CC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD9CC.c \n *       --func procScene --addr 0x021CD9CC --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_SceneSetTestConfNopA  0x021CDA0C  arm  ov016
 *   DWCi_SceneSetTestConfNopB  0x021CDA10  arm  ov016
 *   DWCi_WINlGet  0x021D1568  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_WINlEnd  0x021D1524  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CDA14  0x021CDA14  arm  ov016
 */

extern void DWCi_SceneSetTestConfNopA(void);
extern void DWCi_SceneSetTestConfNopB(void);
extern signed char DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CDA14(void);

void procScene(void)
{
    DWCi_SceneSetTestConfNopA();
    DWCi_SceneSetTestConfNopB();
    if (DWCi_WINlGet())
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_SNDlPlay(6);
    DWCi_ChangeScene((unsigned int)func_021CDA14);
}
