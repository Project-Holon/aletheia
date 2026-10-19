/*
 * function: DWCi_SceneSetEditAddressEndScene3
 * address:  0x021C77F4
 * packet:   pkt_ov016_021C77F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene3 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_OBJlDelete  0x021D6F38  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 *   sSceneSetEditAddressPathYbObjMainPltt     0x021DB550  data
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   DWCi_SceneSetList  0x021C82FC  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern void DWCi_COMMENTlDelete();
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_FNTlDeleteBgLcd(int a);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_HEAPlFree_(void **mem);
extern void GX_LoadOBJPltt();
extern void DWCi_SceneSetList();
extern struct MemSsea *gMemSsea;
extern unsigned char sSceneSetEditAddressPathYbObjMainPltt[];

void DWCi_SceneSetEditAddressEndScene3(void)
{
    int prm;

    DWCi_COMMENTlDelete();
    DWCi_OBJlDelete(gMemSsea->caret);
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_CMNlLoadResource((char *)sSceneSetEditAddressPathYbObjMainPltt, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_((unsigned int *)(&prm), 0);
    if (prm >= 3)
        prm++;
    DWCi_SetParam_(2, 1);
    DWCi_SetParam2_(0, prm + 3);
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetList);
    DWCi_HEAPlFree_((void *)0x021DE5E4);
}
