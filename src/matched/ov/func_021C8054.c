/*
 * function: FLD_WIPE_3DOBJ_Delete
 * address:  0x021C8054
 * packet:   pkt_021C8054
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   G3D_SYSTEM_GetObjectRender  0x02047788  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09214.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern int G3D_SYSTEM_GetObjectRender(int *p);

int FLD_WIPE_3DOBJ_Delete(void *a)
{
G3D_SYSTEM_DeleteRender((struct Rec *)G3D_SYSTEM_GetObjectRender((int *)(((struct Obj09214 *)((u8 *)(a)))->f4)));
G3D_SYSTEM_DeleteObject((struct Rec *)(((struct Obj09214 *)((u8 *)(a)))->f4));
G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj09214 *)((u8 *)(a)))->f0));
return func_020307B0(a);
}

