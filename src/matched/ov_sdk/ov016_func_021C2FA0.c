/*
 * function: func_021C2FA0
 * address:  0x021C2FA0
 * packet:   pkt_ov016_021C2FA0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   DWCi_EFFlCheck 0x021D5580 arm ov016
 *   DWCi_BTNlIsEnd 0x021BCB58 arm ov016
 *   DWCi_OBJlDelete 0x021D6F38 arm ov016
 *   DWCi_FOCUSlDelete 0x021BD5A8 arm ov016
 *   DWCi_COMMENTlDelete 0x021BD138 arm ov016
 *   DWCi_ARClRelease 0x021D4C68 arm ov016
 *   DWCi_GXlInvisible 0x021D6090 arm ov016
 *   DWCi_SetParam_ 0x021C0E50 arm ov016
 *   DWCi_ChangeScene 0x021C0E40 arm ov016
 *   DWCi_SceneMenu 0x021C1984 arm ov016
 *   DWCi_SceneOptInfo 0x021C255C arm ov016
 *   DWCi_SceneOptErase 0x021C1F1C arm ov016
 *   DWCi_SceneOptMovConfirm1 0x021C3824 arm ov016
 *   gSceneOptMenuWork 0x021DE5A8 data
 */

#include "../include/G_FocusPosT.h"

typedef unsigned char u8;

extern struct FocusPosT gSceneOptMenuWork;

extern int DWCi_EFFlCheck(int lcd);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_FOCUSlDelete(void);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneMenu();
extern void DWCi_SceneOptInfo();
extern void DWCi_SceneOptErase();
extern void DWCi_SceneOptMovConfirm1();

void func_021C2FA0(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_OBJlDelete(gSceneOptMenuWork.obj);
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(gSceneOptMenuWork.ptr);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    if (gSceneOptMenuWork.flag == 0) {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneMenu);
        return;
    }
    switch (gSceneOptMenuWork.idx) {
    case 0:
        DWCi_SetParam_(0, (unsigned int)((void *)1));
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptInfo);
        return;
    case 1:
        DWCi_SetParam_(0, (unsigned int)((void *)1));
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptErase);
        return;
    case 2:
        DWCi_SetParam_(0, (unsigned int)((void *)1));
        DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovConfirm1);
        return;
    }
}
