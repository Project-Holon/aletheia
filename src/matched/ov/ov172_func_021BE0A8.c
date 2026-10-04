/*
 * function: func_021BE0A8
 * address:  0x021BE0A8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24128.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BE0A8(void *p, u8 v)
{
    ((struct Obj24128 *)p)->f19 = v;
}
