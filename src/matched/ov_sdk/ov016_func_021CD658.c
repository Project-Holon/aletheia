/*
 * function: func_021CD658
 * address:  0x021CD658
 * packet:   pkt_ov016_021CD658
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD658.c \n *       --func func_021CD658 --addr 0x021CD658 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTestCompletet_procScene  0x021CD67C  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021C0E40(unsigned int v);
extern void DWCi_SceneSetTestCompletet_procScene(void);

void func_021CD658(void)
{
    if (func_021D5580(0))
        return;
    func_021C0E40((unsigned int)DWCi_SceneSetTestCompletet_procScene);
}
