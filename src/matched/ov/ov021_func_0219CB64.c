/*
 * function: FLDMMDL_BLACT_AddResObjCodeParam
 * address:  0x0219CB64
 * packet:   pkt_ov021_0219CB64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParamBlActRes  0x0216E3C8  thumb  ov010
 *   FLDMMDL_SysGetResArcHandle  0x0216D518  thumb  ov010
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FLDMMDL_BLACT_AddRes  0x0219CB24  thumb  ov021
 */
#include "../include/Obj19659.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;
extern void *FLDMMDL_GetObjCodeParamBlActRes(void *p);
extern u32 FLDMMDL_SysGetResArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern void FLDMMDL_BLACT_AddRes(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);

void FLDMMDL_BLACT_AddResObjCodeParam(u8 *s, const D *d, u32 g)
{
    u16 *q = FLDMMDL_GetObjCodeParamBlActRes((void *)d);
    FLDMMDL_BLACT_AddRes(s, (u32)G3D_SYSTEM_CreateResourceArcHandle(FLDMMDL_SysGetResArcHandle((u8 *)(((struct Obj19659 *)s)->f10)), *q), d->id, d->f7, d->f8, g);
}
