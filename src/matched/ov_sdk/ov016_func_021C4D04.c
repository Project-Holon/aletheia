/*
 * function: endScene2
 * address:  0x021C4D04
 * packet:   pkt_ov016_021C4D04
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_AOSSlEnd  0x021C08B0  arm  ov016
 *   DWCi_ANIMElEnd  0x021BC8EC  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneSetAossButtonWork     0x021DE5CC  data
 *   DWCi_SceneSetSelectWay  0x021CC998  arm  ov016
 *   DWCi_SceneSetAossComplete  0x021C4EC8  arm  ov016
 */

#include "../include/G_SCENESETAOSSBUTT_BSS.h"

extern int DWCi_EFFlCheck();
extern int DWCi_BTNlIsEnd();
extern void DWCi_AOSSlEnd(int a);
extern void DWCi_ANIMElEnd();
extern void DWCi_FNTlDeleteBgLcd(int a);
extern void DWCi_COMMENTlDelete();
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetSelectWay();
extern void DWCi_SceneSetAossComplete();
extern struct SCENESETAOSSBUTT_BSS gSceneSetAossButtonWork;

void endScene2(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        if (DWCi_EFFlCheck(1))
            return;
    }
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_AOSSlEnd((*(unsigned char *)&gSceneSetAossButtonWork) != 0);
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if ((*(unsigned char *)&gSceneSetAossButtonWork) == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetAossComplete);
    }
}
