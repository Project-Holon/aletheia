/*
 * function: FLDEFF_BTRAIN_SetAnime
 * address:  0x021D024C
 * packet:   pkt_ov021_021D024C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Highlights button sel of four and records it.
 *
 * symbols:
 *   FIELD_EFFECT_GetObjectWork  0x021AC1E0  thumb
 *   G3D_SYSTEM_ResetObjectAnimeFrame  0x02047804  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_DisableObjectAnime  0x020477D4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06104.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_EFFECT_GetObjectWork(u32 a);
struct AnmCtl;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
struct G3dSys;
struct Owner;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);

void FLDEFF_BTRAIN_SetAnime(void *obj, u32 sel)
{
    int i;
    u8 *q;

    if (obj == 0)
        return;
    q = (u8 *)FIELD_EFFECT_GetObjectWork((u32)obj);
    for (i = 0; i < 4; i++) {
        G3D_SYSTEM_ResetObjectAnimeFrame((struct AnmCtl *)(((struct Obj06104 *)q)->fC), (u16)i);
        if (i == sel)
            G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)(((struct Obj06104 *)q)->fC), (u16)i);
        else
            G3D_SYSTEM_DisableObjectAnime((struct Owner *)(((struct Obj06104 *)q)->fC), (u16)i);
    }
    q[2] = sel;
    q[3] = 0;
}
