/*
 * function: func_0219B984
 * address:  0x0219B984
 * packet:   pkt_0219B984
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0219B9B0  0x0219B9B0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern void func_0219B9B0(u32 a, u8 *s);

int func_0219B984(u32 a, u32 b)
{
if (func_0216DEE0((void *)func_0216D67C((void *)a)) == 0) {
    ((struct Obj05008 *)((u8 *)(b)))->f1 = 0;
    return 0;
}
if (((struct Obj05008 *)((u8 *)(b)))->f1 == 0) {
    func_0219B9B0(a, (u8 *)b);
}
return 1;
}

