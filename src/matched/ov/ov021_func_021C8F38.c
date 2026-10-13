/*
 * function: FLDEFF_D06DENKI_FreeResources
 * address:  0x021C8F38
 * packet:   pkt_ov021_021C8F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09714.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FLDEFF_D06DENKI_FreeResources(u8 *p)
{
    u32 i;

    G3D_SYSTEM_DeleteAnime((struct Rec *)(((struct Obj09714 *)p)->f28));
    G3D_SYSTEM_DeleteObject((struct Rec *)(((struct Obj09714 *)p)->f30));
    G3D_SYSTEM_DeleteRender((struct Rec *)(((struct Obj09714 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        G3D_SYSTEM_FreeVramTexture((u32 *)(*(u32 *)(p + i * 4 + 4)));
        G3D_SYSTEM_DeleteResource((struct Tagged *)(*(u32 *)(p + i * 4 + 4)));
    }
    for (i = 0; i < 5; i++) {
        G3D_SYSTEM_DeleteResource((struct Tagged *)(*(u32 *)(p + i * 4 + 0x14)));
    }
}
