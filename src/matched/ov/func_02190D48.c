/*
 * function: func_02190D48
 * address:  0x02190D48
 * packet:   pkt_02190D48
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
 *   func_0201CE48  0x0201CE48  thumb
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17932.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_020307B0(u32);

int func_02190D48(u32 a)
{
func_0201CE48((struct Rec3 *)(((struct Obj17932 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

