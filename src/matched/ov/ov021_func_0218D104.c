/*
 * function: FIELD_G3D_MAPPER_LoadTexture
 * address:  0x0218D104
 * packet:   pkt_ov021_0218D104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_TintTexture  0x0218D0D8  thumb
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm  arm9
 *   G3D_SYSTEM_TransVramTextureAndCut  0x020470A8  arm  arm9
 */
#include "../include/Obj07415.h"
#include "../include/Obj19550.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
extern u32 G3D_SYSTEM_TransVramTextureAndCut(void *p);
extern int FIELD_G3D_MAPPER_TintTexture(void *a, void *b);

void FIELD_G3D_MAPPER_LoadTexture(u8 *a, u8 *b, void *c)
{
    u32 v = ((struct Obj19550 *)b)->f20;
    if (v != 0) {
        if (v == 1) {
            u32 *q = (u32 *)(b + 0x24);
            ((struct Obj07415 *)a)->f60 = (u32)G3D_SYSTEM_CreateResourceArc(q[0], q[1]);
            if (c != 0)
                FIELD_G3D_MAPPER_TintTexture((void *)(((struct Obj07415 *)a)->f60), c);
            G3D_SYSTEM_TransVramTextureAndCut((void *)(((struct Obj07415 *)a)->f60));
        }
    } else {
        ((struct Obj07415 *)a)->f60 = 0;
    }
}
