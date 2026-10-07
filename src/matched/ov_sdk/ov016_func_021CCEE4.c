/*
 * function: endScene2
 * address:  0x021CCEE4
 * packet:   pkt_ov016_021CCEE4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesetselectwa)
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetListReturn               0x021CA5C0  arm
 *   g_021DE614                       0x021DE614  data
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetSearch              0x021CB780  arm
 *   DWCi_SceneSetAossButton          0x021C4904  arm
 *   DWCi_SceneSetRakuReady           0x021CB2E8  arm
 *   DWCi_SceneSetList                0x021C82FC  arm
 */

#include "../include/G_FocusState.h"

typedef _Bool bool;
typedef signed char s8;
typedef unsigned char u8;

extern struct FocusState g_021DE614;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_FOCUSlDelete(void);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(int param0, int param1);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam2_(int param2, int param3);
extern void DWCi_SetListReturn(int scene);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetSearch(void);
extern void DWCi_SceneSetAossButton(void);
extern void DWCi_SceneSetRakuReady(void);
extern void DWCi_SceneSetList(void);

static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(g_021DE614.screen);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    if (g_021DE614.flag == 0) {
        DWCi_SetParam_(2, 0);
        DWCi_ChangeScene(DWCi_SceneSetSelectAp);
        return;
    }
    switch (g_021DE614.cur) {
    case 0:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetSearch);
        break;
    case 1:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetAossButton);
        break;
    case 2:
        DWCi_SetParam_(2, 1);
        DWCi_ChangeScene(DWCi_SceneSetRakuReady);
        break;
    case 3:
        DWCi_SetParam_(2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_SetListReturn(1);
        DWCi_ChangeScene(DWCi_SceneSetList);
        break;
    }
}
