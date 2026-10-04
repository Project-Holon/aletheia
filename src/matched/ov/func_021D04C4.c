/*
 * function: func_021D04C4
 * address:  0x021D04C4
 * packet:   pkt_021D04C4
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
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18369.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_021AC1E0(u32 a);

int func_021D04C4(u32 a)
{
if (a != 0) {
    return ((struct Obj18369 *)((u8 *)(func_021AC1E0(a))))->f1C;
}
return 1;
}

