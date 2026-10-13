/*
 * function: SHORTCUT_MENU_GetResult
 * address:  0x021C5394
 * packet:   pkt_ov021_021C5394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the result word and optionally its argument.
 */
#include "../include/Obj12942.h"

typedef unsigned char u8;
typedef unsigned int u32;

u32 SHORTCUT_MENU_GetResult(u8 *p, u32 *out)
{
    if (out != 0)
        *out = ((struct Obj12942 *)p)->f78;
    return ((struct Obj12942 *)p)->f74;
}
