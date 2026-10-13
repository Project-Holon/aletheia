/*
 * function: POKELIST_SetupLight
 * address:  0x021B6F28
 * packet:   pkt_ov091_021B6F28
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D4B0  0x0207D4B0  arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   func_0207D63C  0x0207D63C  arm
 *   PARTICLE_InitManager  0x02050B80  arm
 *   d_021BEAB8     0x021BEAB8  data  a4
 *   d_021BEAD0     0x021BEAD0  data  a4
 *   d_021BEAC4     0x021BEAC4  data  a4
 */
#include "../include/Obj07728.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D4B0(int, int, int);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern int G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void PARTICLE_InitManager(u32 heap);
extern char d_021BEAB8[];
extern char d_021BEAD0[];
extern char d_021BEAC4[];

void POKELIST_SetupLight(char *p)
{
    int r;

    func_0207D4B0(1, 0, 1);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, ((struct Obj07728 *)p)->f0, 0);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    r = G3D_CAMERA_Create(2, 0, 0x50D7, 0, 0x6BCA, 0x1000, 0x80000, 0, d_021BEAB8, d_021BEAD0, d_021BEAC4, ((struct Obj07728 *)p)->f0);
    ((struct Obj07728 *)p)->f258 = r;
    G3D_CAMERA_Reset((struct Light *)r);
    func_0207D63C(0x04000050, 4, 0x1e, 0x10, 10);
    PARTICLE_InitManager(((struct Obj07728 *)p)->f0);
}
