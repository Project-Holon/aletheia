/*
 * function: SODATEYA_GetPokemonCount
 * address:  0x021C340C
 * packet:   pkt_021C340C
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
 *   func_0200BCB8  0x0200BCB8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18301.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0200BCB8(u32, u32, u32, u32);

int SODATEYA_GetPokemonCount(u32 a, u32 b, u32 c, u32 d)
{
return ((func_0200BCB8(((struct Obj18301 *)((u8 *)(a)))->f8, b, c, d) << 24) >> 24);
}

