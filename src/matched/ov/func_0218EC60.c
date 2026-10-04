/*
 * function: func_0218EC60
 * address:  0x0218EC60
 * packet:   pkt_0218EC60
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
#include "../include/Obj01653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_0218EC60(u32 a, u32 b)
{
*(u32 *)&((struct Obj01653 *)((u8 *)(a)))->f1C = ((struct Obj01653 *)((u8 *)(a)))->f18;
return a;
}

