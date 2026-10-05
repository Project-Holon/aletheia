/*
 * function: func_02187FD0
 * address:  0x02187FD0
 * packet:   pkt_02187FD0
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
 *   func_02188B58  0x02188B58  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17856.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188B58(u32, u32, u32, u32);

int func_02187FD0(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188B58(c, ((struct Obj17856 *)((u8 *)(d)))->f0, c, d) == 1) {
    return 1;
}
return 0;
}

