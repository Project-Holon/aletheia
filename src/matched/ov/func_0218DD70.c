/*
 * function: FIELD_G3D_MAPPER_ResetCell
 * address:  0x0218DD70
 * packet:   pkt_0218DD70
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
#include "../include/Obj07208.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_G3D_MAPPER_ResetCell(u32 a)
{
((struct Obj07208 *)((u8 *)(a)))->f0 = (~0);
((struct Obj07208 *)((u8 *)(a)))->f4 = 0;
((struct Obj07208 *)((u8 *)(a)))->f8 = 0;
((struct Obj07208 *)((u8 *)(a)))->fC = 0;
return a;
}

