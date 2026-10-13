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
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTestCompletet_procScene  0x021CD67C  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetTestCompletet_procScene(void);

void func_021CD658(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetTestCompletet_procScene);
}
