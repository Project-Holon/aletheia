/*
 * function: func_021C8B5C
 * address:  0x021C8B5C
 * packet:   pkt_021C8B5C
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
 *   func_021C8A8C  0x021C8A8C  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00876.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021639C0(u32, u32);
extern int func_021C8A8C(u32 a);

int func_021C8B5C(u32 a)
{
if (func_021639C0(((struct Obj00876 *)((u8 *)(a)))->fC, func_021C8A8C(a)) != 0) {
    return 1;
}
return 0;
}

