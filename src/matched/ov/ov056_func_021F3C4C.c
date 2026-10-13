/*
 * function: FIELD_FK_DEMO_DeleteModel
 * address:  0x021F3C4C
 * packet:   pkt_021F3C4C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteObject  0x02047738  arm
 *   G3D_SYSTEM_DeleteAnime  0x0204762C  arm
 *   G3D_SYSTEM_DeleteRender  0x02047504  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 */
#include "../include/Obj03652.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec;
struct Tagged;
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);

void FIELD_FK_DEMO_DeleteModel(u8 *p)
{
    G3D_SYSTEM_DeleteObject((struct Rec *)(((struct Obj03652 *)p)->f1C));
    G3D_SYSTEM_DeleteAnime((struct Rec *)(((struct Obj03652 *)p)->f14));
    G3D_SYSTEM_DeleteAnime((struct Rec *)(((struct Obj03652 *)p)->f18));
    G3D_SYSTEM_DeleteRender((struct Rec *)(((struct Obj03652 *)p)->f10));
    G3D_SYSTEM_FreeVramTexture((u32 *)(((struct Obj03652 *)p)->f0));
    G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj03652 *)p)->f0));
    G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj03652 *)p)->f4));
    G3D_SYSTEM_DeleteResource((struct Tagged *)(((struct Obj03652 *)p)->f8));
}
