/*
 * function: DWCi_SceneSetTestCompletet
 * address:  0x021CD580
 * packet:   pkt_ov016_021CD580
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetTestCompletet (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD580.c \n *       --func DWCi_SceneSetTestCompletet --addr 0x021CD580 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gScenesettestcompleteWork     0x021DE620  data
 *   func_021CD5B0  0x021CD5B0  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CD61C  0x021CD61C  arm  ov016
 */

extern unsigned char gScenesettestcompleteWork;
extern void func_021CD5B0(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD61C(void);

void DWCi_SceneSetTestCompletet(void)
{
    gScenesettestcompleteWork = 0;
    func_021CD5B0();
    DWCi_CMNlMsgDraw(45);
    DWCi_ChangeScene((unsigned int)func_021CD61C);
}
