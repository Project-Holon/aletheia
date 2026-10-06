/*
 * function: func_021C5424
 * address:  0x021C5424
 * packet:   pkt_021C5424
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
 *   func_021C59A8  0x021C59A8  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18305.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02082BCC(u32, u32, u32);
extern int func_021C59A8(u32 a, u32 b, u32 c);

int func_021C5424(u32 a, u32 b)
{
func_021C59A8(a, b, (b + 2));
func_020452E8((struct Descriptor *)(((struct Obj18305 *)((u8 *)(a)))->f8));
return func_02082BCC(a, 0, 76);
}

