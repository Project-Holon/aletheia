/*
 * function: func_02195E80
 * address:  0x02195E80
 * packet:   pkt_02195E80
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
 *   func_02195E54  0x02195E54  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09176.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02195E54(u32, u32, u32, u32);

int func_02195E80(u32 a, u32 b)
{
return func_02195E54(a, ((struct Obj09176 *)((u8 *)(b)))->fC, ((struct Obj09176 *)((u8 *)(b)))->f3, ((struct Obj09176 *)((u8 *)(b)))->f58);
}

