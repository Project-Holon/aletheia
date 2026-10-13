/*
 * function: FIELD_G3D_MAPPER_SetCellPos
 * address:  0x0218DD9C
 * packet:   pkt_0218DD9C
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09174.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_G3D_MAPPER_SetCellPos(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj09174 *)((u8 *)(a)))->f4 = b;
((struct Obj09174 *)((u8 *)(a)))->f8 = c;
((struct Obj09174 *)((u8 *)(a)))->fC = d;
return a;
}

