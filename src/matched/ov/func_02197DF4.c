/*
 * function: func_02197DF4
 * address:  0x02197DF4
 * packet:   pkt_02197DF4
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
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12072.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D3CC(int a0);

int func_02197DF4(u32 a)
{
if (func_0216D3CC(((struct Obj12072 *)((u8 *)(a)))->fC) == 0) {
    return 0;
}
((struct Obj12072 *)((u8 *)(a)))->f0 = 2;
return 1;
}

