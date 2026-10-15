/*
 * function: FLD3D_CI_SetupEffectUnit
 * address:  0x021C1C24
 * packet:   pkt_021C1C24
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
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03528.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 G3D_UTIL_AddUnit(u32, u32, u32, u32);
extern u32 MTX_Identity33_(u32);

int FLD3D_CI_SetupEffectUnit(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj03528 *)((u8 *)(a)))->f18 = G3D_UTIL_AddUnit(((struct Obj03528 *)((u8 *)(a)))->f14, b, c, d);
((struct Obj03528 *)((u8 *)(a)))->f28 = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f2C = (1 << 12);
((struct Obj03528 *)((u8 *)(a)))->f30 = (1 << 12);
MTX_Identity33_((a + 52));
((struct Obj03528 *)((u8 *)(a)))->f1C = 0;
((struct Obj03528 *)((u8 *)(a)))->f20 = 0;
((struct Obj03528 *)((u8 *)(a)))->f24 = 0;
return 0;
}

