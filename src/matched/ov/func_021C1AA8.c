/*
 * function: FLD_PARTICLE_StartEmitter
 * address:  0x021C1AA8
 * packet:   pkt_021C1AA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   PARTICLE_SetupSystem  0x02051230  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18282.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 PARTICLE_SetupSystem(u32, u32, u32, u32);

int FLD_PARTICLE_StartEmitter(u32 a, u32 b, u32 c, u32 d)
{
return PARTICLE_SetupSystem(((struct Obj18282 *)((u8 *)(a)))->fC, b, c, d);
}

