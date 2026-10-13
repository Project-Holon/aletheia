/*
 * function: FIELD_PLAYER_GRID_EVENT_UpdateJumpDown
 * address:  0x021C16AC
 * packet:   pkt_ov021_021C16AC
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
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FIELD_EFFECT_FreeResource  0x021ABE64  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartOnEffect  0x021AD564  thumb  ov021
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELDMAP_TCB_CAMERA_ZOOM_Create  0x021C6B18  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset  0x021C12E4  thumb  ov021
 *   FIELD_PLAYER_SetGridMoveState  0x021A35A0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00129.h"

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
extern void FLDMMDL_SetPos(void *a, Vec3 *v);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern void FLDMMDL_MOVE_GetMapHeight(void *a, Vec3 *v, int *out);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FIELD_EFFECT_LoadResources(int a, int *b, int c);
extern void FIELD_EFFECT_FreeResource(u32 a, int b);
extern u32 FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(u32 a, u32 b, void *c);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern void FIELDMAP_TCB_CAMERA_ZOOM_Create(u32 a, u16 b, u32 c);
extern void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(void *a, u8 *b);
extern void FIELD_PLAYER_SetGridMoveState(u32 *p, int a);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

void FIELD_PLAYER_GRID_EVENT_UpdateJumpDown(u8 *p)
{
    void *o;
    u32 k;
    void *r7;
    u32 t;
    Vec3 w;
    Vec3 v;
    Vec3 b;
    Vec3 c;
    Vec3 a;
    int n;

    o = FIELD_PLAYER_GetMmdl(((struct Obj00129 *)p)->f3C);
    switch (((struct Obj00129 *)p)->f2) {
    case 0:
        k = 1;
        FLDMMDL_SetStatusBitHeightGetOff(o, 1);
        FLDMMDL_GetPos(o, (struct VecFx32 *)&v);
        a = v;
        b = a;
        c = a;
        FLDMMDL_MOVE_AddDirVector(((struct Obj00129 *)p)->f4, (int *)(&b), 0x10000);
        FLDMMDL_MOVE_AddDirVector(((struct Obj00129 *)p)->f4, (int *)(&c), 0x20000);
        FLDMMDL_MOVE_GridToVectorPos((s16)((b.x >> 4) / 0x1000), (s16)((b.z >> 4) / 0x1000), (int *)(&b));
        FLDMMDL_MOVE_AddDirVector(((struct Obj00129 *)p)->f4, (int *)(&b), 0x4000);
        FLDMMDL_MOVE_GridToVectorPos((s16)((c.x >> 4) / 0x1000), (s16)((c.z >> 4) / 0x1000), (int *)(&c));
        *(Vec3 *)(p + 0x24) = c;
        FLDMMDL_MOVE_GetMapHeight(o, &c, (int *)(p + 0x28));
        ((struct Obj00129 *)p)->f30 = (b.x - v.x) / 16;
        ((struct Obj00129 *)p)->f38 = (b.z - v.z) / 16;
        ((struct Obj00129 *)p)->f34 = -0x6000;
        ((struct Obj00129 *)p)->f1C = 0x1000;
        r7 = (void *)FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
        FLDEFF_NAMIPOKE_SetFollowMode((u32)r7, 2);
        if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
            k = 3;
        t = FIELDMAP_GetEffect((u8 *)(((struct Obj00129 *)p)->f40));
        n = 9;
        FIELD_EFFECT_LoadResources(t, &n, 1);
        ((struct Obj00129 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(t, k, r7);
        FIELDMAP_TCB_CAMERA_ZOOM_Create(((struct Obj00129 *)p)->f40, 0x10, 0x20000);
        GFL_USE_PlaySeDefaultVolume(0x6e1);
        ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
    case 1:
        FLDMMDL_GetPos(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        FLDMMDL_SetPos(o, &w);
        ((struct Obj00129 *)p)->f1C = -((struct Obj00129 *)p)->f1C;
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            ((struct Obj00129 *)p)->f8 = 0;
            ((struct Obj00129 *)p)->f1C = 0;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            FIELD_EFFECT_DeleteObject(((struct Obj00129 *)p)->f48);
            r7 = (void *)FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            {
                u32 k2 = 2;
                if ((u16)(((struct Obj00129 *)p)->f4 + 0xfffe) <= 1)
                    k2 = 2;
                ((struct Obj00129 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect((u8 *)(((struct Obj00129 *)p)->f40)), k2, r7);
            }
        }
        FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(o, p + 0x18);
        break;
    case 2:
        FLDMMDL_GetPos(o, (struct VecFx32 *)&w);
        w.y += ((struct Obj00129 *)p)->f34;
        if (w.y <= ((struct Obj00129 *)p)->f28) {
            w.y = ((struct Obj00129 *)p)->f28;
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
            ((struct Obj00129 *)p)->f30 = (((struct Obj00129 *)p)->f24 - w.x) / 16;
            ((struct Obj00129 *)p)->f38 = (((struct Obj00129 *)p)->f2C - w.z) / 16;
            FIELDMAP_TCB_CAMERA_ZOOM_Create(((struct Obj00129 *)p)->f40, 0x10, -0x20000);
            FIELD_EFFECT_DeleteObject(((struct Obj00129 *)p)->f48);
            r7 = (void *)FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj00129 *)p)->f3C));
            FLDEFF_NAMIPOKE_SetFollowMode((u32)r7, 1);
            ((struct Obj00129 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect((u8 *)(((struct Obj00129 *)p)->f40)), 0, r7);
        }
        FLDMMDL_SetPos(o, &w);
        break;
    case 3:
        FLDMMDL_GetPos(o, (struct VecFx32 *)&w);
        w.x += ((struct Obj00129 *)p)->f30;
        w.z += ((struct Obj00129 *)p)->f38;
        FLDMMDL_SetPos(o, &w);
        ((struct Obj00129 *)p)->f8 += 1;
        if (((struct Obj00129 *)p)->f8 >= 0x10) {
            t = FIELDMAP_GetEffect((u8 *)(((struct Obj00129 *)p)->f40));
            FLDMMDL_SetStatusBitHeightGetOff(o, 0);
            FLDMMDL_InitPosition(o, (int *)(p + 0x24), ((struct Obj00129 *)p)->f4);
            FIELD_EFFECT_DeleteObject(((struct Obj00129 *)p)->f48);
            FIELD_EFFECT_FreeResource(t, 9);
            FIELD_PLAYER_SetGridMoveState((u32 *)(*(u32 *)&((struct Obj00129 *)p)->f3C), 1);
            ((struct Obj00129 *)p)->f48 = 0;
            ((struct Obj00129 *)p)->f6 = 1;
            GFL_USE_PlaySeDefaultVolume(0x6e2);
            ((struct Obj00129 *)p)->f2 = ((struct Obj00129 *)p)->f2 + 1;
        }
        break;
    }
}
