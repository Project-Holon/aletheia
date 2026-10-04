/*
 * function: func_021C09AC
 * address:  0x021C09AC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25976.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C09AC(void *p)
{
    return ((struct Obj25976 *)p)->f0;
}
