/*
 * function: func_021C2ECC
 * address:  0x021C2ECC
 * packet:   pkt_021C2ECC
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
#include "../include/Obj18297.h"
#include "../include/Obj18298.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C2ECC(u32 a, u32 b)
{
return ((((struct Obj18298 *)((u8 *)(b)))->f0 << 3) + ((((struct Obj18297 *)((u8 *)(a)))->f2C << 16) >> 13));
}

