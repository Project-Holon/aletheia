/*
 * function: func_021D1418
 * address:  0x021D1418
 * packet:   pkt_021D1418
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
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18373.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02040588(u32, u32);
extern void func_02041B6C(u32 bit);
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);

int func_021D1418(u32 a, u32 b, u32 c, u32 d)
{
func_020456F8((struct Descriptor *)(((struct Obj18373 *)((u8 *)(a)))->f4));
func_02041B6C(3);
return func_02040588(3, 0);
}

