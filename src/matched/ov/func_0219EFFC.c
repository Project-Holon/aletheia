/*
 * function: func_0219EFFC
 * address:  0x0219EFFC
 * packet:   pkt_0219EFFC
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
 *   func_020307B0  0x020307B0  arm
 *   func_0219EF14  0x0219EF14  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09178.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern u32 func_0219EF14(u32);

int func_0219EFFC(u32 a)
{
if (((struct Obj09178 *)((u8 *)(a)))->f0 != 0) {
    func_020307B0((void *)(((struct Obj09178 *)((u8 *)(a)))->f0));
    ((struct Obj09178 *)((u8 *)(a)))->f0 = 0;
}
return func_0219EF14((a + 8));
}

