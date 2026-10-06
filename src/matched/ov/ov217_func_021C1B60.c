/*
 * function: func_021C1B60
 * address:  0x021C1B60
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pack the bytes at +0xe, +0xf and +0x10 into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03956.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 func_021C1B60(void *p)
{
    return (u16)(((struct Obj03956 *)p)->fE | (((struct Obj03956 *)p)->fF << 5) | (((struct Obj03956 *)p)->f10 << 10));
}
