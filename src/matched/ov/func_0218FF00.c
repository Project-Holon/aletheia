/*
 * function: func_0218FF00
 * address:  0x0218FF00
 * packet:   pkt_0218FF00
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
 *   func_021901E8  0x021901E8  thumb  ov021
 *   func_02190110  0x02190110  thumb  ov021
 *   func_0219014C  0x0219014C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17918.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02190110(u32);
extern u32 func_0219014C(u32);
extern u32 func_021901E8(u32, u32, u32, u32);

int func_0218FF00(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj17918 *)((u8 *)(func_021901E8(a, b, c, d))))->f0 == 0) {
    return func_02190110(a);
}
return func_0219014C(a);
}

