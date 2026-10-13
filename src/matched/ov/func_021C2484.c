/*
 * function: FLD3D_CI_EndSequence
 * address:  0x021C2484
 * packet:   pkt_021C2484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLD3D_CI_FreeSequence  0x021C2734  thumb  ov021
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   FLD_PARTICLE_DeleteEffect  0x021C1A84  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07228.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern u32 FLD_PARTICLE_DeleteEffect(u32);
extern void FLD3D_CI_FreeSequence(void **p);

int FLD3D_CI_EndSequence(u8 *a, u8 *b)
{
FLD3D_CI_FreeSequence((void **)b);
G3D_UTIL_RemoveUnit((struct Ctx *)(((struct Obj07228 *)((u8 *)(a)))->f14), ((((struct Obj07228 *)((u8 *)(a)))->f18 << 16) >> 16));
((struct Obj07228 *)((u8 *)(a)))->f18 = (~0);
return FLD_PARTICLE_DeleteEffect(((struct Obj07228 *)((u8 *)(a)))->f0);
}

