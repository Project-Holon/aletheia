/*
 * function: DRAW_SYSTEM_GetStroke
 * address:  0x021B6EC4
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pointer field at +0x10 advanced by 8 bytes per index.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04549.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 *DRAW_SYSTEM_GetStroke(void *p, int i)
{
    return (u8 *)((struct Obj04549 *)p)->f10 + i * 8;
}
