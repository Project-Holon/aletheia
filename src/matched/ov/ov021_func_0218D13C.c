/*
 * function: FIELD_G3D_MAPPER_FreeTexture
 * address:  0x0218D13C
 * packet:   pkt_ov021_0218D13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm  arm9
 */
#include "../include/Obj07416.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Tagged;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FIELD_G3D_MAPPER_FreeTexture(u8 *a)
{
    if (((struct Obj07416 *)a)->f60 != 0) {
        G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj07416 *)a)->f60));
        G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj07416 *)a)->f60));
        ((struct Obj07416 *)a)->f60 = 0;
    }
}
