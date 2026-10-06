/*
 * function: func_021CA338
 * address:  0x021CA338
 * packet:   pkt_ov021_021CA338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws the three +0x628 entries through 0x021CBED8 and stores each result byte at +0x664.
 *
 * symbols:
 *   func_021CBED8  0x021CBED8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09722.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_021CBED8(u8 *p, u8 *list, u16 v, u8 n, u16 *a, u16 *b, u8 *e, u16 id);

void func_021CA338(u8 *p, u8 alt)
{
    int base = 300;
    int i;

    if (alt)
        base += 3;
    for (i = 0; i < 3; i++)
        p[0x664 + i] = func_021CBED8(p, p + 0x2c8 + i * 0x120, base + i, p[8],
                                     (u16 *)(p + 0x22), (u16 *)(p + 0x2a),
                                     p + 0x628 + i * 0x14, ((struct Obj09722 *)p)->f4);
}
