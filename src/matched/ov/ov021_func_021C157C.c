/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpArc
 * address:  0x021C157C
 * packet:   pkt_ov021_021C157C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset  0x021C12E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_SetPos(void *a, Vec3 *v);
extern void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(void *a, u8 *b);

int FIELD_PLAYER_GRID_EVENT_JumpUpArc(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = FIELD_PLAYER_GetMmdl(((struct Obj00657 *)p)->f3C);
    FLDMMDL_GetPos(r4, (struct VecFx32 *)&v);
    if (v.x < ((struct Obj00657 *)p)->f24) {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x > ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    } else {
        v.x += ((struct Obj00657 *)p)->f30;
        if (v.x < ((struct Obj00657 *)p)->f24)
            v.x = ((struct Obj00657 *)p)->f24;
    }
    if (v.z < ((struct Obj00657 *)p)->f2C) {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z > ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    } else {
        v.z += ((struct Obj00657 *)p)->f38;
        if (v.z < ((struct Obj00657 *)p)->f2C)
            v.z = ((struct Obj00657 *)p)->f2C;
    }
    v.y += ((struct Obj00657 *)p)->f34;
    ((struct Obj00657 *)p)->f34 += ((struct Obj00657 *)p)->f10;
    ((struct Obj00657 *)p)->f8 += 1;
    if (((struct Obj00657 *)p)->f8 >= 0x10) {
        v = *(Vec3 *)(p + 0x24);
        ((struct Obj00657 *)p)->f18 = 0;
        ((struct Obj00657 *)p)->f1C = 0;
        ((struct Obj00657 *)p)->f20 = 0;
        ((struct Obj00657 *)p)->f2 = ((struct Obj00657 *)p)->f2 + 1;
    }
    FLDMMDL_SetPos(r4, &v);
    FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(r4, p + 0x18);
    return 0;
}
