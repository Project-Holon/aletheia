/*
 * function: func_021CC2D0
 * address:  0x021CC2D0
 * packet:   pkt_ov016_021CC2D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_STEPlIsEnd  0x021D0A84  arm  ov016
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_FOCUSlDelete  0x021BD5A8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_ARClRelease  0x021D4C68  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SETTIGNlGet  0x021CF404  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_SetListReturn  0x021CA5C0  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 *   DWCi_SceneSetSelectWay  0x021CC998  arm  ov016
 *   DWCi_SceneSetList  0x021C82FC  arm  ov016
 *   func_021CDCAC  0x021CDCAC  arm  ov016
 *   g_021DE60C  0x021DE60C  data
 *   sSceneSetSelectApFocusPos  0x021DE610  data
 *   @21063  0x021DB760  data
 *
 * The object reaches MemSssa (0x021DE610) through FocusPos (0x021DE60C) + 4, and
 * takes &MemSssa through its own pool word; both spellings are declared.
 */

#include "../include/G_SCENESETSELECTAP_BSS.h"

typedef unsigned char u8;
typedef unsigned long u32;

#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))

typedef struct tagMEMSSSA {
    void *arc;          /* +0x00 */
    void *cellA[3];     /* +0x04 */
    void *cellB[3];     /* +0x10 */
    char pad1c;
    u8 mode;            /* +0x1d */
} MEMSSSA;

typedef struct tagSETTINGINFO {
    char pad[0xe7];
    u8 e7;
} SETTINGINFO;

extern struct SCENESETSELECTAP_BSS g_021DE60C;
extern MEMSSSA *sSceneSetSelectApFocusPos;

extern int DWCi_EFFlCheck(int lcd);
extern int DWCi_STEPlIsEnd(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_CELLlDelete(u8 *p);
extern void DWCi_FOCUSlDelete(void);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SetListReturn(unsigned char v);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_HEAPlFree_(void **mem);
extern void GX_LoadOBJPltt(void *, u32, u32);
extern void DWCi_SceneMenu();
extern void DWCi_SceneSetSelectWay();
extern void DWCi_SceneSetList();
extern void func_021CDCAC();

static void func_021CC2D0(void)
{
    int i;

    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_STEPlIsEnd())
        return;
    if (!DWCi_BTNlIsEnd())
        return;

    for (i = 0; i < NELEMS(((MEMSSSA *)g_021DE60C.MemSssa)->cellA); i++) {
        if (((MEMSSSA *)g_021DE60C.MemSssa)->cellA[i])
            DWCi_CELLlDelete(((MEMSSSA *)g_021DE60C.MemSssa)->cellA[i]);
    }
    for (i = 0; i < NELEMS(((MEMSSSA *)g_021DE60C.MemSssa)->cellB); i++) {
        if (((MEMSSSA *)g_021DE60C.MemSssa)->cellB[i])
            DWCi_CELLlDelete(((MEMSSSA *)g_021DE60C.MemSssa)->cellB[i]);
    }
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(((MEMSSSA *)g_021DE60C.MemSssa)->arc);
    DWCi_CMNlLoadResource("char/ybObjMain.ncl.l", GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);

    if (((MEMSSSA *)g_021DE60C.MemSssa)->mode == 2) {
        DWCi_SetParam_((unsigned int)((void *)0), (unsigned int)((void *)0));
        DWCi_ChangeScene((unsigned int)DWCi_SceneMenu);
    } else {
        switch (g_021DE60C.FocusPos) {
        case 0:
        case 1:
        case 2:
            DWCi_SetParam_((unsigned int)((void *)2), (unsigned int)((void *)0));
            if (DWCi_SETTIGNlGet()->e7 == 0xff) {
                DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectWay);
            } else {
                DWCi_SetParam2_((unsigned int)((void *)0), (unsigned int)((void *)0));
                DWCi_SetListReturn(0);
                DWCi_ChangeScene((unsigned int)DWCi_SceneSetList);
            }
            break;
        case 3:
            DWCi_SetParam_((unsigned int)((void *)2), (unsigned int)((void *)1));
            DWCi_ChangeScene((unsigned int)func_021CDCAC);
            break;
        }
    }
    DWCi_HEAPlFree_((void **)&sSceneSetSelectApFocusPos);
}
