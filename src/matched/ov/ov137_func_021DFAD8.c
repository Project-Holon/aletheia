/*
 * function: func_021DFAD8
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
 *   func_021DFA68 0x021DFA68 thumb ov137
 *   d_021E2020 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E1D00 0x021E1D00 data a4
 *   d_021E1D0C 0x021E1D0C data a4
 */
#include "../include/Obj14228.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } Vec3;
extern const Vec3 d_021E2020;
extern const s16 d_020A1EB8[];
extern Vec3 d_021E1D00, d_021E1D0C;
extern void func_021DFA68(void);
struct Light;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void *G3D_CAMERA_Create(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);
extern void G3D_CAMERA_Reset(struct Light *l);
void func_021DFAD8(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, 114, func_021DFA68);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    position = d_021E2020;
    ((struct Obj14228 *)section)->f14 = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &d_021E1D00, &position, &d_021E1D0C, 114);
    G3D_CAMERA_Reset(((struct Obj14228 *)section)->f14);
}
