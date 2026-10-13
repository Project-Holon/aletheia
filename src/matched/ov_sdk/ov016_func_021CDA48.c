/*
 * function: func_021CDA48
 * address:  0x021CDA48
 * packet:   pkt_ov016_021CDA48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestconf)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDA48.c \n *       --func func_021CDA48 --addr 0x021CDA48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTest  0x021CD160  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetTest(void);

void func_021CDA48(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_GXlInvisible(0, 20);
    DWCi_SetParam_(0, (unsigned int)((void *)1));
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetTest);
}
