/*
 * function: func_021BBD14
 * address:  0x021BBD14
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25853.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BBD14(void *p, u32 v)
{
    ((struct Obj25853 *)p)->f2C = v;
}
