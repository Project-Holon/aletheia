/*
 * function: FIELDMAP_CreateG3dResources
 * address:  0x02188EE4
 * packet:   pkt_ov021_02188EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_ACT_Create  0x0204FE94  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetQuadShape  0x0204EDBC  arm
 *   BILLBOARD_SetImageOffset  0x0204EDC4  arm
 *   BILLBOARD_SetScale  0x0204ED70  arm
 *   BILLBOARD_SetPolyIdBase  0x0204EDB0  arm
 *   FIELDMAP_SetupBbdColor  0x021891C0  thumb  ov021
 *   FIELD_G3DOBJ_Create  0x021C63AC  thumb  ov021
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_LIGHT_CreateSlots  0x02048BC4  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   FIELDMAP_BbdActTransCallback  0x02189140  thumb  ov021
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   sGroundBbdScale     0x021D36F4  data  a4
 *   sCameraUp     0x021D36E8  data  a4
 *   sCameraPos     0x021D35C0  data  a4
 *   sCameraTarget     0x021D35CC  data  a4
 *   sLightSetup     0x021D35AC  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01344.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 w[3];
} Vec12;

extern const s16 d_020A1EB8[];
extern const Vec12 sGroundBbdScale;
extern const Vec12 sCameraUp;
extern Vec12 sCameraPos;
extern Vec12 sCameraTarget;
extern u8 sLightSetup[];

extern void FIELDMAP_BbdActTransCallback(int x, int b, void *c, int d);
struct Light;
struct LightSet;
struct LightSlot;
extern void *BILLBOARD_ACT_Create(u16 a0, u16 a1, u32 a2, int heap);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetQuadShape(u8 *dst, u8 val);
extern void BILLBOARD_SetImageOffset(u8 *dst, int a, int b);
struct Blk3;
extern void BILLBOARD_SetScale(u8 *dst, struct Blk3 *src);
extern void BILLBOARD_SetPolyIdBase(u8 *dst, u8 *src);
extern void FIELDMAP_SetupBbdColor(u8 *p);
extern u32 FIELD_G3DOBJ_Create(u16 heap, int a, int b);
extern u32 G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);

void FIELDMAP_CreateG3dResources(u8 *p)
{
    Vec12 v30;
    Vec12 v24;
    u8 v20;
    u8 *h;
    u16 heap;

    ((struct Obj01344 *)p)->fB0 = (u32)BILLBOARD_ACT_Create(0x40, 0x80, (u32)FIELDMAP_BbdActTransCallback, ((struct Obj01344 *)p)->f0);
    h = (u8 *)BILLBOARD_ACT_GetBoard((u32 *)(((struct Obj01344 *)p)->fB0));
    BILLBOARD_SetQuadShape(h, 2);
    BILLBOARD_SetImageOffset(h, 0, -0xA00);
    ((struct Obj01344 *)p)->fB4 = (u32)BILLBOARD_ACT_Create(0x3A, 0x50, (u32)FIELDMAP_BbdActTransCallback, ((struct Obj01344 *)p)->f0);
    ((struct Obj01344 *)p)->fB8 = (u32)BILLBOARD_ACT_Create(0x1E, 0x28, (u32)FIELDMAP_BbdActTransCallback, ((struct Obj01344 *)p)->f0);
    h = (u8 *)BILLBOARD_ACT_GetBoard((u32 *)(((struct Obj01344 *)p)->fB8));
    v30 = sGroundBbdScale;
    BILLBOARD_SetScale(h, (struct Blk3 *)(&v30));
    v20 = 0;
    BILLBOARD_SetPolyIdBase(h, &v20);
    FIELDMAP_SetupBbdColor(p);
    ((struct Obj01344 *)p)->f130 = FIELD_G3DOBJ_Create(((struct Obj01344 *)p)->f0, 0x40, 0x40);
    heap = ((struct Obj01344 *)p)->f0;
    v24 = sCameraUp;
    ((struct Obj01344 *)p)->fA4 = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                                       &sCameraPos, &v24, &sCameraTarget, heap);
    ((struct Obj01344 *)p)->fA8 = (u32)G3D_LIGHT_CreateSlots((const struct LightSet *)sLightSetup, ((struct Obj01344 *)p)->f0);
    G3D_CAMERA_Reset((struct Light *)(((struct Obj01344 *)p)->fA4));
    G3D_LIGHT_ApplySlots((struct LightSlot *)(((struct Obj01344 *)p)->fA8));
}
