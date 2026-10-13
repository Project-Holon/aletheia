/*
 * function: FIELD_3DBG_FreeTexture
 * address:  0x021A1750
 * packet:   pkt_021A1750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07217.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);

int FIELD_3DBG_FreeTexture(u32 a)
{
G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj07217 *)((u8 *)(a)))->f8));
G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj07217 *)((u8 *)(a)))->f8));
((struct Obj07217 *)((u8 *)(a)))->f8 = 0;
((struct Obj07217 *)((u8 *)(a)))->f6 = 0;
return 0;
}

