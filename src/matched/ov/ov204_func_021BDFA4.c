/*
 * function: INTRO_GRAPHIC_InitCamera
 * address: 0x021BDFA4
 * packet: pkt_ov204_021BDFA4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the fourth 02048A24 argument is the pooled 0x1555 (earlier notes
 * decoded it as 0x155, which also moved the pool order). The heap parameter
 * is u8: with the callees' own prototypes (02046440 s16 heap, 02048A24 u16
 * heap, 02048BC4 u32 heap) a u8 converts to all three with no code, matching
 * the original's unnarrowed full-word stack stores; u16/s16/u32 each add a
 * lsls/asr|lsr pair (156-160 bytes). Twin: ov204_func_021BE03C.c.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_SetRoll 0x02048B6C arm
 *   G3D_CAMERA_SetScale 0x02048B60 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   INTRO_GRAPHIC_Setup3d 0x021BDB70 thumb ov204
 *   gIntroGraphicCameraPos 0x021BFD68 data a4
 *   gIntroGraphicCameraTarget 0x021BFD5C data a4
 *   gIntroGraphicCameraUp 0x021BFD74 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021BFD4C 0x021BFD4C data a4
 *   gIntroG3dUnitSetup  0x021C093C  data
 */

#include "../include/G_021BFD68.h"
#include "../include/G_021BFD5C.h"
#include "../include/G_021BFD74.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 x, y, z; } Vec3;
struct Light; struct LightSet; struct LightSlot;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*gIntroG3dUnitSetup)(void));
extern u32 *G3D_CAMERA_Create(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                          Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
extern void G3D_CAMERA_SetRoll(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetScale(struct Light *l, const u32 *in);
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void INTRO_GRAPHIC_Setup3d(void);
extern struct G_021BFD68 gIntroGraphicCameraPos;
extern struct G_021BFD5C gIntroGraphicCameraTarget;
extern struct G_021BFD74 gIntroGraphicCameraUp;
extern const short d_020A1EB8[];
extern const struct LightSet d_021BFD4C;
void INTRO_GRAPHIC_InitCamera(char *p, u8 heap)
{
    u32 far_clip, near_clip;
    G3D_SYSTEM_Init(0, 4, 0, 2, 0, heap, INTRO_GRAPHIC_Setup3d);
    *(u32 **)p = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&gIntroGraphicCameraPos), ((Vec3 *)&gIntroGraphicCameraTarget), ((Vec3 *)&gIntroGraphicCameraUp), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    G3D_CAMERA_SetRoll(*(struct Light **)p, &far_clip);
    G3D_CAMERA_SetScale(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = G3D_LIGHT_CreateSlots(&d_021BFD4C, heap);
    G3D_LIGHT_ApplySlots(*(struct LightSlot **)(p + 4));
}
