/*
 * function: DWCi_SceneSetUsbComplete_endScene1
 * address:  0x021CDC00
 * packet:   pkt_ov016_021CDC00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDC00.c \n *       --func DWCi_SceneSetUsbComplete_endScene1 --addr 0x021CDC00 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetTestConfirm  0x021CD80C  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetTestConfirm(void);

void DWCi_SceneSetUsbComplete_endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 21);
    DWCi_SetParam_(0, 0);
    DWCi_SetParam2_(0, (unsigned int)((void *)2));
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetTestConfirm);
}
