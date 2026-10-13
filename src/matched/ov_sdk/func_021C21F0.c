/*
 * function: func_021C21F0
 * address:  0x021C21F0
 * packet:   pkt_021C21F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same shape as DWCi_SceneOptMovConfirm1EndScene2 with a different flag byte and last stage.
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_BTNlIsEnd  0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneOptEraseWork     0x021DE5A4  data
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 *   DWCi_SceneOptErase1  0x021C231C  arm
 */

#include "../include/G_SCENEOPTERASE_BSS.h"

typedef unsigned char u8;

extern int  DWCi_EFFlCheck(int x);
extern int  DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern struct SCENEOPTERASE_BSS gSceneOptEraseWork;
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptErase1(void);

void func_021C21F0(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (((u8 *)&gSceneOptEraseWork)[0] == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptErase1);
    }
}
