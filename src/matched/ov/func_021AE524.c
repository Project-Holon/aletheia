/*
 * function: func_021AE524
 * address:  0x021AE524
 * packet:   pkt_021AE524
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
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07220.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D3CC(int a0);
extern u32 func_0216D410(u32, u32);
extern int func_02197E7C(int a, int b);

int func_021AE524(u32 a)
{
if (func_0216D3CC(((struct Obj07220 *)((u8 *)(a)))->f8) == 1) {
    func_0216D410(((struct Obj07220 *)((u8 *)(a)))->f8, func_02197E7C(((((struct Obj07220 *)((u8 *)(a)))->f10 << 16) >> 16), 0));
    ((struct Obj07220 *)((u8 *)(a)))->f0 = 4;
}
return 0;
}

