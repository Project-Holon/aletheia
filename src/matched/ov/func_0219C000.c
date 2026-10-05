/*
 * function: func_0219C000
 * address:  0x0219C000
 * packet:   pkt_0219C000
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216DA7C  0x0216DA7C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17962.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D438(int a0, int a1);
extern u32 func_0216D5F8(u32, u32, u32, u32);
extern u32 func_0216DA50(u32);
extern u32 func_0216DA7C(u32);
extern u32 func_02197E7C(u32, u32);

int func_0219C000(u32 a, u32 b, u32 c, u32 d)
{
func_0216D438(a, ((func_02197E7C(((func_0216D5F8(a, b, c, d) << 16) >> 16), 0) << 16) >> 16));
func_0216DA50(a);
func_0216DA7C(a);
((struct Obj17962 *)((u8 *)(b)))->f0 = 1;
return 1;
}

