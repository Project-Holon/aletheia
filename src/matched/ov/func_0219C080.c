/*
 * function: func_0219C080
 * address:  0x0219C080
 * packet:   pkt_0219C080
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17964.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D438(int a0, int a1);
extern u16 func_0216D608(void *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_02197E7C(int a, int b);

int func_0219C080(u32 a, u32 b, u32 c, u32 d)
{
func_0216D438(a, (((u32)func_02197E7C((u32)func_0216D608(func_0216DEE0((void *)func_0216D67C((void *)a))), (u32)0) << 16) >> 16));
((struct Obj17964 *)((u8 *)(b)))->f0 = 4;
return 1;
}

