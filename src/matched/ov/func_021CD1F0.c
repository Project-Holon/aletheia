/*
 * function: func_021CD1F0
 * address:  0x021CD1F0
 * packet:   pkt_021CD1F0
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
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18362.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern void func_02049238(u32 arc);

int func_021CD1F0(u32 a)
{
func_02049238(((struct Obj18362 *)((u8 *)(a)))->f0);
return func_020307B0(a);
}

