/*
 * function: func_021C8A8C
 * address:  0x021C8A8C
 * packet:   pkt_021C8A8C
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00876.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021C8A8C(u32 a)
{
if (*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10 != 0) {
    return *(u16 *)((u8 *)(*(u32 *)&((struct Obj00876 *)((u8 *)(a)))->f10) + 4);
}
return 0;
}

