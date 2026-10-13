/*
 * function: DWCi_SceneSetTest
 * address:  0x021CD160
 * packet:   pkt_ov016_021CD160
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetTest (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD160.c \n *       --func DWCi_SceneSetTest --addr 0x021CD160 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gSceneSetTestWork     0x021DE61C  data
 *   func_021CD1F8  0x021CD1F8  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_CMNlStep  0x021BD214  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   func_021CD2A0  0x021CD2A0  arm  ov016
 *   DWCi_ICONlInit  0x021BD744  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CD338  0x021CD338  arm  ov016
 */

extern unsigned char gSceneSetTestWork;
extern void func_021CD1F8(void);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_HLlLoadSet(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void func_021CD2A0(void);
extern void DWCi_ICONlInit(int type);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD338(void);

void DWCi_SceneSetTest(void)
{
    int scene;
    gSceneSetTestWork = 0;
    func_021CD1F8();
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 0)
        DWCi_COMMENTlDispEx(49, -1, 0);
    DWCi_CMNlStep(2);
    if (scene == 0)
        DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(44);
    DWCi_ANIMElInitEx(0);
    func_021CD2A0();
    DWCi_ICONlInit(0);
    DWCi_SNDlPlay(12);
    DWCi_ChangeScene((unsigned int)func_021CD338);
}
