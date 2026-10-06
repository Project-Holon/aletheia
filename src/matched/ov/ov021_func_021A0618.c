/*
 * function: func_021A0618
 * address:  0x021A0618
 * packet:   pkt_ov021_021A0618
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0C50  0x021A0C50  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19694.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_021A0C50(u32 a, u16 b, u32 c, u32 d);

void func_021A0618(u8 *p, u32 a, u32 b, u32 c)
{
    func_021A0C50((u32)(p + 0x484), b, (u16)c, a);
    ((struct Obj19694 *)p)->f0 = 1;
}
