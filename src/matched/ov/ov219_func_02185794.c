/*
 * function: BEACON_DETAIL_SetupCamera
 * address: 0x02185794
 * packet: pkt_ov219_02185794
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane16): EXACT. The flag block is an if/else-if chain with h == 0 first; tail merging of the duplicate stores gives the bne/b pairs.
 * symbols:
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetUp 0x02048B44 arm
 *   G3D_CAMERA_SetNearClip 0x02048B80 arm
 *   G3D_CAMERA_SetFarClip 0x02048B94 arm
 *   G3D_CAMERA_SetScale 0x02048B60 arm
 *   G3D_CAMERA_SetRoll 0x02048B6C arm
 *   BEACON_DETAIL_UpdateCamera 0x02185AC8 thumb ov219
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1C78 0x020A1C78 data
 */

#include "../include/G_02185E0C.h"
#include "../include/G_Vec3.h"

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec3;
typedef struct {char pad[0x30]; short a, b;} Cfg;
extern struct G_02185E0C d_02185E0C;
extern struct Vec3 d_02185DF4;
extern Cfg d_020A1C78;
extern void G3D_CAMERA_SetEye(void *, Vec3 *);
extern void G3D_CAMERA_SetUp(void *, Vec3 *);
struct Light;
extern void G3D_CAMERA_SetNearClip(struct Light *l, u32 v);
extern void G3D_CAMERA_SetFarClip(struct Light *l, u32 v);
extern void G3D_CAMERA_SetScale(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetRoll(struct Light *l, const u32 *in);
extern int BEACON_DETAIL_UpdateCamera(char *);

void BEACON_DETAIL_SetupCamera(char *p)
{
    u32 a = 0;
    u32 b = 0x19 << 14;
    G3D_CAMERA_SetEye(*(void **)(p + 0xC36C), ((Vec3 *)&d_02185E0C));
    G3D_CAMERA_SetUp(*(void **)(p + 0xC36C), ((Vec3 *)&d_02185DF4));
    G3D_CAMERA_SetNearClip(*(void **)(p + 0xC36C), d_020A1C78.a);
    G3D_CAMERA_SetFarClip(*(void **)(p + 0xC36C), d_020A1C78.b);
    G3D_CAMERA_SetScale(*(void **)(p + 0xC36C), &a);
    G3D_CAMERA_SetRoll(*(void **)(p + 0xC36C), &b);
    if (*(u16 *)(p + 0xC31C) == 0)
        *(u16 *)(p + 0xC30C) = 1;
    else if (*(u32 *)(p + 0xC33C) == 0)
        *(u16 *)(p + 0xC30C) = 0;
    else if (*(u32 *)(p + 0xC33C) == 0xdc)
        *(u16 *)(p + 0xC30C) = 0;
    else
        *(u16 *)(p + 0xC30C) = 1;
    while (BEACON_DETAIL_UpdateCamera(p) != 1)
        ;
}
