/*
 * function: FLDEFF_D06DENKI_FollowUpdate
 * address:  0x021C9190
 * packet:   pkt_ov021_021C9190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckStatusBitUse  0x0216DA30  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02730.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct V3 { int v[3]; } V3;

extern int FLDMMDL_CheckStatusBitUse(int a0, int a1);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FIELD_EFFECT_SetObjectPos(u32, V3 *);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);

void FLDEFF_D06DENKI_FollowUpdate(u32 a, u8 *b)
{
    V3 v;

    if (FLDMMDL_CheckStatusBitUse(((struct Obj02730 *)b)->f10, (int)b) != 0) {
        FLDMMDL_GetPos((const struct Actor *)((struct Obj02730 *)b)->f10, (struct VecFx32 *)&v);
        *(V3 *)(b + 0x28) = v;
        FIELD_EFFECT_SetObjectPos(a, &v);
        ((struct Obj02730 *)b)->f2C -= 0x4000;
        ((struct Obj02730 *)b)->f30 += 0x2800;
        if (b[0x14] == 0) {
            G3D_SYSTEM_LoopObjectAnimeFrame((void *)(((struct Obj02730 *)b)->f18), 0, 0x1000);
        }
        if (b[0x15] == 1 && b[0x16] == 0) {
            if (G3D_SYSTEM_IncObjectAnimeFrame((void *)(((struct Obj02730 *)b)->f18), 1, 0x1000) == 0) {
                b[0x16] = 1;
            }
        }
    }
}
