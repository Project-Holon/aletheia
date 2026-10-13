/*
 * function: DWCi_SceneSetTestConfirm
 * address:  0x021CD80C
 * packet:   pkt_ov016_021CD80C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetTestConfirm (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD80C.c \n *       --func DWCi_SceneSetTestConfirm --addr 0x021CD80C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_SEARCHlEnd  0x021CEF50  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   func_021CD870  0x021CD870  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_SETTINGlSet  0x021CF8D8  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CD8DC  0x021CD8DC  arm  ov016
 */

extern void DWCi_SEARCHlEnd(void);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void func_021CD870(void);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_HLlLoadSet(void);
extern void DWCi_SETTINGlSet(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD8DC(void);

void DWCi_SceneSetTestConfirm(void)
{
    int prm;
    DWCi_SEARCHlEnd();
    DWCi_GetParam2_(0, (unsigned int *)((void **)&prm));
    func_021CD870();
    DWCi_COMMENTlDispEx(49, -1, 0);
    if (prm != 2)
        DWCi_HLlLoadSet();
    if (prm == 1)
        DWCi_SETTINGlSet();
    DWCi_ChangeScene((unsigned int)func_021CD8DC);
}
