/*
 * function: func_0218C530
 * address:  0x0218C530
 * packet:   pkt_0218C530
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09173.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

u8 func_0218C530(int a)
{
if (*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) == (~0)) {
    return ((((struct Obj09173 *)((u8 *)(a)))->f4 << 24) >> 24);
}
return ((*(u32 *)((u8 *)(((struct Obj09173 *)((u8 *)(a)))->fC)) << 24) >> 24);
}

