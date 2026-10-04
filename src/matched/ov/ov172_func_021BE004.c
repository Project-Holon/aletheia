/*
 * function: func_021BE004
 * address:  0x021BE004
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1f8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24111.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BE004(void *p)
{
    return ((struct Obj24111 *)p)->f1F8;
}
