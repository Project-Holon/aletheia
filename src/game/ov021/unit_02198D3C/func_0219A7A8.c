/*
 * function: func_0219A7A8
 * address:  0x0219A7A8
 * packet:   pkt_0219A7A8
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
 *   func_02197EDC  0x02197EDC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj12075.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02197EDC(u8 *p);

int func_0219A7A8(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
((struct Obj12075 *)((u8 *)(b)))->f4 = 0;
((struct Obj12075 *)((u8 *)(b)))->f2 = 2;
return 1;
}

