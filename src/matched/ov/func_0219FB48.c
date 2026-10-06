/*
 * function: func_0219FB48
 * address:  0x0219FB48
 * packet:   pkt_0219FB48
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
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0219C8D4  0x0219C8D4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17983.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D6F0(void *p);
extern u32 func_0219C8D4(u32, u32);

int func_0219FB48(u32 a, u32 b, u32 c, u32 d)
{
return func_0219C8D4(a, ((struct Obj17983 *)((u8 *)(func_0216D6F0((void *)a))))->f0);
}

