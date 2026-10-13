/*
 * function: MONOLITH_TOOL_ScrollBy
 * address:  0x021BA0CC
 * packet:   pkt_ov071_021BA0CC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf following MONOLITH_TOOL_ApplyCursorChange inside its listing extent.
 */
#include "../include/Obj00044.h"

typedef unsigned char u8;

int MONOLITH_TOOL_ScrollBy(u8 *p, int d)
{
    int lim;
    int old;

    old = ((struct Obj00044 *)p)->f2D8;
    lim = p[0x27c] * 32 - 8;
    if (lim <= 0xc0) {
        return 0;
    }
    ((struct Obj00044 *)p)->f2D8 = old + d;
    if (((struct Obj00044 *)p)->f2D8 < 0x800) {
        ((struct Obj00044 *)p)->f2D8 = 0x800;
    } else if (((struct Obj00044 *)p)->f2D8 > (lim - 0xc0) << 8) {
        ((struct Obj00044 *)p)->f2D8 = (lim - 0xc0) << 8;
    }
    if ((((struct Obj00044 *)p)->f2D8 >> 8) != (old >> 8)) {
        return 1;
    }
    return 0;
}
