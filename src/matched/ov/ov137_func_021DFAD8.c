/*
 * function: GURU2_MAIN_Setup3dSystem
 * address: 0x021DFAD8
 * packet: pkt_ov137_021DFAD8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   GURU2_MAIN_Setup3dState 0x021DFA68 thumb ov137
 *   gGuru2CameraTarget 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   gGuru2CameraEye 0x021E1D00 data a4
 *   gGuru2CameraUp 0x021E1D0C data a4
 */
#include "../include/Obj14228.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } Vec3;
extern const Vec3 gGuru2CameraTarget;
extern const s16 d_020A1EB8[];
extern Vec3 gGuru2CameraEye, gGuru2CameraUp;
extern void GURU2_MAIN_Setup3dState(void);
struct Light;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void *G3D_CAMERA_Create(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);
extern void G3D_CAMERA_Reset(struct Light *l);
void GURU2_MAIN_Setup3dSystem(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, 114, GURU2_MAIN_Setup3dState);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    position = gGuru2CameraTarget;
    ((struct Obj14228 *)section)->f14 = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &gGuru2CameraEye, &position, &gGuru2CameraUp, 114);
    G3D_CAMERA_Reset(((struct Obj14228 *)section)->f14);
}
