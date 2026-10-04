/*
 * function: func_021C09CC
 * address:  0x021C09CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x38.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25981.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021C09CC(void *p)
{
    return ((struct Obj25981 *)p)->f38;
}
