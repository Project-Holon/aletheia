/*
 * function: FLDEFF_FISHING_FreeResources
 * address:  0x021ADF68
 * packet:   pkt_021ADF68
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
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04889.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 G3D_SYSTEM_DeleteResource(u32);
struct Rec;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);

int FLDEFF_FISHING_FreeResources(void *a)
{
G3D_SYSTEM_DeleteObject((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->fC));
G3D_SYSTEM_DeleteAnime((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f10));
G3D_SYSTEM_DeleteRender((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f14));
G3D_SYSTEM_DeleteResource(((struct Obj04889 *)((u8 *)(a)))->f8);
G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj04889 *)((u8 *)(a)))->f4));
return G3D_SYSTEM_DeleteResource(((struct Obj04889 *)((u8 *)(a)))->f4);
}

