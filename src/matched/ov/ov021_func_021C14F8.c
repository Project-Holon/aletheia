/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpRise
 * address:  0x021C14F8
 * packet:   pkt_ov021_021C14F8
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
 *   func_0209C0A4  0x0209C0A4  arm
 *   FIELDMAP_TCB_CAMERA_ZOOM_Create  0x021C6B18  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01506.h"

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
extern int func_0209C0A4(int a, int b);
extern void FIELDMAP_TCB_CAMERA_ZOOM_Create(u32 a, u16 b, u32 c);
extern void FIELD_EFFECT_DeleteObject(u32 a);

int FIELD_PLAYER_GRID_EVENT_JumpUpRise(u8 *p)
{
    Vec3 v;
    void *r4;

    r4 = FIELD_PLAYER_GetMmdl(((struct Obj01506 *)p)->f3C);
    FLDMMDL_GetPos(r4, (struct VecFx32 *)&v);
    v.y += ((struct Obj01506 *)p)->f34;
    if (v.y >= ((struct Obj01506 *)p)->f28) {
        v.y = ((struct Obj01506 *)p)->f28;
        ((struct Obj01506 *)p)->f2 = ((struct Obj01506 *)p)->f2 + 1;
        ((struct Obj01506 *)p)->f30 = (((struct Obj01506 *)p)->f24 - v.x) / 16;
        ((struct Obj01506 *)p)->f38 = (((struct Obj01506 *)p)->f2C - v.z) / 16;
        ((struct Obj01506 *)p)->f10 = -0x8000;
        ((struct Obj01506 *)p)->f34 = 0x6000;
        ((struct Obj01506 *)p)->f10 = func_0209C0A4(-0x8000, 0xb);
        FIELDMAP_TCB_CAMERA_ZOOM_Create(((struct Obj01506 *)p)->f40, 0x10, (u32)-0x8000 << 2);
        FIELD_EFFECT_DeleteObject(((struct Obj01506 *)p)->f48);
    }
    FLDMMDL_SetPos(r4, &v);
    return 0;
}
