/*
 * function: func_021B7D38
 * address:  0x021B7D38
 * packet:   pkt_021B7D38
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
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj07526.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021B7EE4(u32, u32, u32, u32);
extern u32 func_021B8028(u32, u32);

int func_021B7D38(u32 a, u32 b, u32 c, u32 d)
{
func_021B7EE4(((struct Obj07526 *)((u8 *)(a)))->f1C, b, c, d);
return func_021B8028(((struct Obj07526 *)((u8 *)(a)))->f1C, c);
}

