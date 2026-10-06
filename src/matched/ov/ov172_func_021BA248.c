/*
 * function: func_021BA248
 * address:  0x021BA248
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24098.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021BA248(void *p)
{
    return ((struct Obj24098 *)p)->f18;
}
