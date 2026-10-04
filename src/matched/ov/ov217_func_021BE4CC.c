/*
 * function: func_021BE4CC
 * address:  0x021BE4CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BE4CC(void *p, u32 v)
{
    ((struct Obj00021 *)p)->f20 = v;
    ((struct Obj00021 *)p)->f24 = 0;
    ((struct Obj00021 *)p)->f28 = 0;
    ((struct Obj00021 *)p)->f3DC = 0;
}
