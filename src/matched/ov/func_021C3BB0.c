/*
 * function: func_021C3BB0
 * address:  0x021C3BB0
 * packet:   pkt_021C3BB0
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
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00358.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02017E1C(void *, u32, u32);

int func_021C3BB0(u32 a)
{
if (func_02017E1C(((struct Obj00358 *)((u8 *)(a)))->f4, 5, 0) == 132) {
    return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f0;
}
return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f4;
}

