/*
 * function: func_021BC6E4
 * address:  0x021BC6E4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25872.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BC6E4(void *p)
{
    return ((struct Obj25872 *)p)->f31;
}
