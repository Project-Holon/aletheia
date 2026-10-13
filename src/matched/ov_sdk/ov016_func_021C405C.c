/*
 * function: func_021C405C
 * address:  0x021C405C
 * packet:   pkt_ov016_021C405C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovFailureWork     0x021DE5C0  data
 *   DWCi_SceneOptMenu  0x021C2A3C  arm  ov016
 *   DWCi_SceneOptMovWait  0x021C450C  arm  ov016
 */

extern int DWCi_EFFlCheck();
extern int DWCi_BTNlIsEnd();
extern void DWCi_FNTlDeleteBgLcd(int a);
extern void DWCi_COMMENTlDelete();
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneOptMenu();
extern void DWCi_SceneOptMovWait();
extern unsigned char gSceneOptMovFailureWork[];

void func_021C405C(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (!gSceneOptMovFailureWork[1]) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (!gSceneOptMovFailureWork[1]) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovWait);
    }
}
