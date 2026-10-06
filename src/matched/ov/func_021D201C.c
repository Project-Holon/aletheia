/*
 * function: func_021D201C
 * address:  0x021D201C
 * packet:   pkt_021D201C
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
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04135.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
struct Bank;
extern u32 func_0204B1CC(struct Bank *bank);
struct Obj;
extern void func_0204B3B4(struct Obj *p);

int func_021D201C(u32 a, u32 b, u32 c, u32 d)
{
func_0204B3B4((struct Obj *)(((struct Obj04135 *)((u8 *)(a)))->f3C));
func_0204A8D4(((struct Obj04135 *)((u8 *)(a)))->f40);
func_0204ADA4(((struct Obj04135 *)((u8 *)(a)))->f44);
func_0204AFD8(((struct Obj04135 *)((u8 *)(a)))->f48);
return func_0204B1CC((struct Bank *)(((struct Obj04135 *)((u8 *)(a)))->f38));
}

