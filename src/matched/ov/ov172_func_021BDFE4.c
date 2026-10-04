/*
 * function: func_021BDFE4
 * address:  0x021BDFE4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1e4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24108.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BDFE4(void *p)
{
    return ((struct Obj24108 *)p)->f1E4;
}
