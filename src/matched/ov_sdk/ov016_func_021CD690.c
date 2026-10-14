/*
 * function: func_021CD690
 * address:  0x021CD690
 * packet:   pkt_ov016_021CD690
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD690.c \n *       --func func_021CD690 --addr 0x021CD690 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_STEPlEnd  0x021D0580  arm  ov016
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTestCompletet_endScene1  0x021CD6F0  arm  ov016
 */

extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_STEPlEnd(void);
extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetTestCompletet_endScene1(void);

void func_021CD690(void)
{
    int scene;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene != 0)
        DWCi_STEPlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 21, 8);
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetTestCompletet_endScene1);
}
