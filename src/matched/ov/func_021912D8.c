/*
 * function: func_021912D8
 * address:  0x021912D8
 * packet:   pkt_021912D8
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
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_02194950  0x02194950  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_021927E8(u32 *p);
extern u32 func_02194950(u32, u32);

int func_021912D8(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
func_021927E8((u32 *)(a + 12));
return func_02194950(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1));
}

