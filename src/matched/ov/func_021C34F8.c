/*
 * function: func_021C34F8
 * address:  0x021C34F8
 * packet:   pkt_021C34F8
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
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04896.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0200BC2C(void *e, u32 i);
extern u32 func_0200BCA8(void *e, u32 i);

void *func_021C34F8(void *a, u32 b)
{
func_0200BCA8(((struct Obj04896 *)a)->f8, b);
return func_0200BC2C(((struct Obj04896 *)a)->f8, b);
}

