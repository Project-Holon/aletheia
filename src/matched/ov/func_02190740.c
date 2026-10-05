/*
 * function: func_02190740
 * address:  0x02190740
 * packet:   pkt_02190740
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
 *   func_02190550  0x02190550  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12066.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020409B4(u32);
struct Descriptor;
struct Slot;
extern u8 func_02045730(struct Descriptor *p);
extern void func_02190550(struct Slot *s, int x, int y, u32 z);

int func_02190740(u32 a, u32 b, u32 c, u32 d)
{
func_02190550((struct Slot *)(((struct Obj12066 *)((u8 *)(a)))->f4), b, c, d);
return func_020409B4(func_02045730((struct Descriptor *)(((struct Obj12066 *)((u8 *)(a)))->f0)));
}

