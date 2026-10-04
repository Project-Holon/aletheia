/*
 * function: func_0219545C
 * address:  0x0219545C
 * packet:   pkt_0219545C
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
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B54  0x02048B54  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07211.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02048AE8(u32, u32, u32, u32);
extern u32 func_02048B0C(u32, u32);
extern u32 func_02048B30(u32, u32);
extern u32 func_02048B54(u32, u32);

int func_0219545C(u32 a, u32 b, u32 c, u32 d)
{
func_02048AE8(((struct Obj07211 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B0C(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B30(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
return func_02048B54(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 36)));
}

