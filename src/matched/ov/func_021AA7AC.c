/*
 * function: func_021AA7AC
 * address:  0x021AA7AC
 * packet:   pkt_021AA7AC
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
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AA7DC  0x021AA7DC  thumb  ov021
 *   func_021AAB74  0x021AAB74  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07219.h"
#include "../include/Obj09585.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CD0(u8 *p);
extern u32 func_021AA7DC(u32, u32);
extern u32 func_021AAB74(u32, u32);

int func_021AA7AC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj09585 *)((u8 *)(b)))->f0 = func_02188CD0((u8 *)(*(u32 *)&((struct Obj07219 *)((u8 *)(a)))->f0));
func_021AA7DC(a, b);
return func_021AAB74(a, b);
}

