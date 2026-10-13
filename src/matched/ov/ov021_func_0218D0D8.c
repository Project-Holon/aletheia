/*
 * function: FIELD_G3D_MAPPER_TintTexture
 * address:  0x0218D0D8
 * packet:   pkt_ov021_0218D0D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_ConvertGrayTable  0x02022040  thumb
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm  arm9
 *   NNS_G3dGetTex  0x0206E964  arm  arm9
 *
 * 2026-10-01: MATCH, capped only by the call to PALANM_ConvertGrayTable (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */
#include "../include/Obj12581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Tagged;
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);

int FIELD_G3D_MAPPER_TintTexture(void *a, void *b)
{
    u8 *p = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(a));
    if (p != 0) {
        u32 size = ((struct Obj12581 *)p)->f30 << 3;
        u32 off = ((struct Obj12581 *)p)->f38;
        if (b != 0)
            PALANM_ConvertGrayTable((u16 *)(p + off), size >> 1, b);
        return 1;
    }
    return 0;
}
