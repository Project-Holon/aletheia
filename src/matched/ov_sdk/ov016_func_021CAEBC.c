/*
 * function: endScene2
 * address:  0x021CAEBC
 * packet:   pkt_ov016_021CAEBC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_BTNlIsEnd  0x021BCB58  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_RAKUlEnd  0x021C14F4  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_SceneSetSelectWay  0x021CC998  arm
 *   DWCi_SceneSetRakuComplete  0x021CB0A8  arm
 *   gSceneSetRakuButton1Work  0x021DE5FC  data  a1
 */

#include "../include/G_021DE5FC.h"

extern int DWCi_EFFlCheck(int x);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_RAKUlEnd(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetRakuComplete(void);
extern struct G_021DE5FC gSceneSetRakuButton1Work;

void endScene2(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if ((*(unsigned char *)&gSceneSetRakuButton1Work) == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if ((*(unsigned char *)&gSceneSetRakuButton1Work) == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_RAKUlEnd();
    if ((*(unsigned char *)&gSceneSetRakuButton1Work) == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetRakuComplete);
    }
}
