/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpStart
 * address:  0x021C1318
 * packet:   pkt_ov021_021C1318
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartOnEffect  0x021AD564  thumb  ov021
 *   FIELDMAP_TCB_CAMERA_ZOOM_Create  0x021C6B18  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01665.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern void FLDMMDL_MOVE_GetMapHeight(void *a, Vec3 *v, int *out);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FIELD_EFFECT_LoadResources(int a, int *b, int c);
extern u32 FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(u32 a, u32 b, u32 c);
extern void FIELDMAP_TCB_CAMERA_ZOOM_Create(u32 a, u16 b, u32 c);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

int FIELD_PLAYER_GRID_EVENT_JumpUpStart(u8 *p)
{
    u32 k;
    void *o;
    u32 r6;
    u32 r7;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = FIELD_PLAYER_GetMmdl(((struct Obj01665 *)p)->f3C);
    k = 1;
    FLDMMDL_SetStatusBitHeightGetOff(o, 1);
    FLDMMDL_GetPos(o, (struct VecFx32 *)&v);
    a = v;
    b = a;
    c = a;
    FLDMMDL_MOVE_AddDirVector(((struct Obj01665 *)p)->f4, (int *)(&b), 0x10000);
    FLDMMDL_MOVE_AddDirVector(((struct Obj01665 *)p)->f4, (int *)(&c), 0x20000);
    FLDMMDL_MOVE_GridToVectorPos((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
    FLDMMDL_MOVE_GridToVectorPos((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(p + 0x24));
    *(Vec3 *)(p + 0x24) = c;
    FLDMMDL_MOVE_GetMapHeight(o, &c, (int *)(p + 0x28));
    ((struct Obj01665 *)p)->f30 = (b.x - v.x) / 2 / 16;
    ((struct Obj01665 *)p)->f38 = (b.z - v.z) / 2 / 16;
    ((struct Obj01665 *)p)->f34 = 0x6000;
    ((struct Obj01665 *)p)->f1C = 0x1000;
    r6 = FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj01665 *)p)->f3C));
    FLDEFF_NAMIPOKE_SetFollowMode(r6, 2);
    if ((u16)(((struct Obj01665 *)p)->f4 + 0xfffe) <= 1)
        k = 3;
    r7 = FIELDMAP_GetEffect((u8 *)(((struct Obj01665 *)p)->f40));
    n = 9;
    FIELD_EFFECT_LoadResources(r7, &n, 1);
    ((struct Obj01665 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(r7, k, r6);
    FIELDMAP_TCB_CAMERA_ZOOM_Create(((struct Obj01665 *)p)->f40, 0x10, 0x20000);
    GFL_USE_PlaySeDefaultVolume(0x6e0);
    ((struct Obj01665 *)p)->f2 = ((struct Obj01665 *)p)->f2 + 1;
    return 1;
}
