/*
 * function: endScene1
 * address:  0x021CB21C
 * packet:   pkt_ov016_021CB21C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(scenesetaosscomp))
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_SetParam2_  0x021C0E8C  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_SceneSetTestConfirm  0x021CD80C  arm
 */
extern int DWCi_EFFlCheck(int x);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetTestConfirm(void);

void endScene1(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 0);
    DWCi_SetParam2_(0, 1);
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetTestConfirm);
}
