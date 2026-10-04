/*
 * function: func_021C1D24
 * address:  0x021C1D24
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26017.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C1D24(void *p)
{
    return ((struct Obj26017 *)p)->f4;
}
