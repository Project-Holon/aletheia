/*
 * function: func_021D1254
 * address:  0x021D1254
 * packet:   pkt_021D1254
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
 *   func_020437AC  0x020437AC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04299.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);

u32 func_021D1254(u32 a)
{
func_020437AC((struct Obj020437AC *)(((struct Obj04299 *)((u8 *)(a)))->f10));
((struct Obj04299 *)((u8 *)(a)))->f10 = 0;
return 0;
}

