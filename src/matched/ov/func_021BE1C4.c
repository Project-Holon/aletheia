/*
 * function: func_021BE1C4
 * address:  0x021BE1C4
 * packet:   pkt_021BE1C4
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
 *   func_021BE180  0x021BE180  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09202.h"
#include "../include/Obj18257.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_021BE180(u8 *p);

int func_021BE1C4(u32 a)
{
if (((struct Obj18257 *)((u8 *)(func_021BE180((u8 *)a))))->f4 == 0) {
    return ((struct Obj09202 *)((u8 *)(a)))->f68;
}
return ((struct Obj09202 *)((u8 *)(a)))->f6C;
}

