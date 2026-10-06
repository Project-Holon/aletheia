/*
 * function: func_021A3624
 * address:  0x021A3624
 * packet:   pkt_021A3624
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
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A54A0  0x021A54A0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06010.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CFC(u8 *p);
extern int func_021A54A0(u32 a);

int func_021A3624(void *a)
{
if (func_02188CFC((u8 *)(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f0)) == 0) {
    if (func_021A54A0(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f8) == 1) {
        return 1;
    }
}
return 0;
}

