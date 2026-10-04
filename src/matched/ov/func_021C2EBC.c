/*
 * function: func_021C2EBC
 * address:  0x021C2EBC
 * packet:   pkt_021C2EBC
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
#include "../include/Obj18295.h"
#include "../include/Obj18296.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C2EBC(u32 a, u32 b)
{
return (((((struct Obj18296 *)((u8 *)(b)))->f0 << 16) >> 13) + ((((struct Obj18295 *)((u8 *)(a)))->f8 << 16) >> 13));
}

