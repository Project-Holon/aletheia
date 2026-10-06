/*
 * function: func_021C1B4C
 * address:  0x021C1B4C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pack the bytes at +0xb, +0xc and +0xd into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03956.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u16 func_021C1B4C(void *p)
{
    return (u16)(((struct Obj03956 *)p)->fB | (((struct Obj03956 *)p)->fC << 5) | (((struct Obj03956 *)p)->fD << 10));
}
