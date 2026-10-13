/*
 * function: FLDMMDL_G3DOBJ_DelObj
 * address:  0x0219D680
 * packet:   pkt_ov021_0219D680
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   FLDMMDL_CheckSameObjCodeOther  0x0216DFC4  thumb  ov010
 *   FLDMMDL_G3DOBJ_DeleteResByCode  0x0219D604  thumb  ov021
 */
#include "../include/Obj07479.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetG3dObjCont(u8 *p);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FIELD_G3DOBJ_DeleteObject(u32, u32);
extern int FLDMMDL_CheckSameObjCodeOther(void *a, u32 id);
extern void FLDMMDL_G3DOBJ_DeleteResByCode(u8 *s, u16 k);

void FLDMMDL_G3DOBJ_DelObj(u32 a, u32 b)
{
    u8 *s = (u8 *)FLDMMDL_SysGetG3dObjCont(FLDMMDL_GetMmdlSys((void *)a));
    u16 v = FLDMMDL_GetObjCode((void *)a);
    FIELD_G3DOBJ_DeleteObject(((struct Obj07479 *)s)->f4, b);
    if (FLDMMDL_CheckSameObjCodeOther((void *)a, v) == 0) {
        FLDMMDL_G3DOBJ_DeleteResByCode(s, v);
    }
}
