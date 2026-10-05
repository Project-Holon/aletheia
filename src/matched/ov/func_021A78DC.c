/*
 * function: func_021A78DC
 * address:  0x021A78DC
 * packet:   pkt_021A78DC
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18065.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A78DC(u32 a)
{
if (((struct Obj18065 *)((u8 *)(a)))->f1C != 0) {
    return 1;
}
return 0;
}

