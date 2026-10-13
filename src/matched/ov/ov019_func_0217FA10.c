/*
 * function: UNION_EFF_CreateAnimObj
 * address:  0x0217FA10
 * packet:   pkt_ov019_0217FA10
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02366.h"
#include "../include/Obj09421.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8(void *p, u32 v, u32 n);
struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

void UNION_EFF_CreateAnimObj(char *self, u32 *out, u32 a2, u16 a3)
{
    MI_CpuFill8(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj02366 *)out)->f10 = a3;
    out[1] = (u32)G3D_SYSTEM_CreateRender((void *)(((struct Obj09421 *)self)->f14), 0, (void *)(((struct Obj09421 *)self)->f14));
    out[2] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)out[1], (const struct G3dOwner *)(((struct Obj09421 *)self)->f18), 0);
    out[3] = (u32)G3D_SYSTEM_CreateObject(out[1], &out[2], 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)out[3], 0);
}
