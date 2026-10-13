/*
 * function: DWCi_SceneOptMovConfirm1EndScene2
 * address:  0x021C3AD0
 * packet:   pkt_021C3AD0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The final DWCi_SetParam_(0, 1) is written in both arms: the original emits
 * it once per arm, not merged before the branch.
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_BTNlIsEnd  0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm
 *   DWCi_COMMENTlDelete  0x021BD138  arm
 *   DWCi_GXlInvisible  0x021D6090  arm
 *   DWCi_SetParam_  0x021C0E50  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneOptMovConfirm1Work     0x021DE5B8  data
 *   DWCi_SceneOptMenu  0x021C2A3C  arm
 *   DWCi_SceneOptMovConfirm  0x021C35F0  arm
 */

#include "../include/G_021DE5B8.h"

typedef unsigned char u8;

extern int  DWCi_EFFlCheck(int x);
extern int  DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int x);
extern void DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int a, int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern struct G_021DE5B8 gSceneOptMovConfirm1Work;
extern void DWCi_SceneOptMenu(void);
extern void DWCi_SceneOptMovConfirm(void);

void DWCi_SceneOptMovConfirm1EndScene2(void)
{
    if (DWCi_EFFlCheck(0) != 0)
        return;
    if (((u8 *)&gSceneOptMovConfirm1Work)[0] == 0) {
        if (DWCi_EFFlCheck(1) != 0)
            return;
    }
    if (DWCi_BTNlIsEnd() == 0)
        return;
    DWCi_FNTlDeleteBgLcd(0);
    if (((u8 *)&gSceneOptMovConfirm1Work)[0] == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (((u8 *)&gSceneOptMovConfirm1Work)[0] == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMenu);
    } else {
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovConfirm);
    }
}
