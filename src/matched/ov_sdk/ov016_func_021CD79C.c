/*
 * function: wait
 * address:  0x021CD79C
 * packet:   pkt_ov016_021CD79C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wait (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD79C.c \n *       --func wait --addr 0x021CD79C --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   gScenesettestcompleteWork     0x021DE620  data
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_Entry  0x021C0ED8  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneEnd  0x021C1630  arm  ov016
 *   func_021CD690  0x021CD690  arm  ov016
 */

extern unsigned char gScenesettestcompleteWork;
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern unsigned int DWCi_Entry(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneEnd(void);
extern void func_021CD690(void);

void wait(void)
{
    int scene;
    int r;
    if (++gScenesettestcompleteWork < 180)
        return;
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    r = DWCi_Entry();
    if (r != 0 && r == 1 && scene != 0) {
        DWCi_ChangeScene((unsigned int)DWCi_SceneEnd);
        return;
    }
    DWCi_ChangeScene((unsigned int)func_021CD690);
}
