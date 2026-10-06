/*
 * function: func_021C1094
 * address:  0x021C1094
 * packet:   pkt_021C1094
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
 *   func_02030EE8  0x02030EE8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18274.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);

int func_021C1094(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj18274 *)((u8 *)(func_02030EE8((struct S02030EE8 *)a))))->f4;
}

