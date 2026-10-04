/*
 * function: func_021BF834
 * address:  0x021BF834
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25944.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021BF834(void *p)
{
    u32 i = ((struct Obj25944 *)p)->f2B8;
    return *(u16 *)((char *)p + i * 0xd4 + 0x3e);
}
