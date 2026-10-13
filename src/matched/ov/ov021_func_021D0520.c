/*
 * function: FLDEFF_HIDE_Update
 * address:  0x021D0520
 * packet:   pkt_ov021_021D0520
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09745.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern void FIELD_EFFECT_DeleteObject(u32 a);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern int FLDMMDL_MOVE_GetMapHeight(u32 m, Vec3 *pos, int *h);
extern void FIELD_EFFECT_SetObjectPos(u32 a, Vec3 *v);

void FLDEFF_HIDE_Update(u32 a, u8 *b)
{
    int h;
    Vec3 v;

    if (FLDMMDL_CheckCheckInfo(((struct Obj09745 *)b)->f8, (int)((u16 *)(b + 0x10))) == 0) {
        FIELD_EFFECT_DeleteObject(a);
        return;
    }
    FLDMMDL_GetPos((const struct Actor *)((struct Obj09745 *)b)->f8, (struct VecFx32 *)&v);
    if (FLDMMDL_MOVE_GetMapHeight(((struct Obj09745 *)b)->f8, &v, &h) == 1) {
        v.y = h;
    }
    FIELD_EFFECT_SetObjectPos(a, &v);
}
