/*
 * file:     unit_021CD80C.c
 * function: func_021CD80C
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD80C.c \n *       --func func_021CD80C --addr 0x021CD80C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021CEF50  0x021CEF50  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021CD870  0x021CD870  arm  ov016
 *   func_021BD060  0x021BD060  arm  ov016
 *   func_021BD6D4  0x021BD6D4  arm  ov016
 *   func_021CF8D8  0x021CF8D8  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CD8DC  0x021CD8DC  arm  ov016
 */

extern void func_021CEF50(void);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021CD870(void);
extern int func_021BD060(int messageId, int n, int num);
extern void func_021BD6D4(void);
extern void func_021CF8D8(void);
extern void func_021C0E40(unsigned int v);
extern void func_021CD8DC(void);

void func_021CD80C(void)
{
    int prm;
    func_021CEF50();
    func_021C0EA0(0, (unsigned int *)((void **)&prm));
    func_021CD870();
    func_021BD060(49, -1, 0);
    if (prm != 2)
        func_021BD6D4();
    if (prm == 1)
        func_021CF8D8();
    func_021C0E40((unsigned int)func_021CD8DC);
}
