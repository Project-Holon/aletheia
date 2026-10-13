/*
 * function: MONOLITH_TOOL_SetCursor
 * address:  0x021B9F2C
 * packet:   pkt_ov071_021B9F2C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00044.h"

typedef unsigned char u8;

int MONOLITH_TOOL_SetCursor(u8 *p, int i, int v)
{
    int old;

    if (i != 0xFFFF) {
        if (i >= p[0x27c] - 1 || i < 1) {
            return 0;
        }
    }
    old = ((struct Obj00044 *)p)->f2F4;
    ((struct Obj00044 *)p)->f2F8 = old;
    ((struct Obj00044 *)p)->f2FC = old;
    ((struct Obj00044 *)p)->f2F4 = i;
    ((struct Obj00044 *)p)->f304 = 1;
    ((struct Obj00044 *)p)->f308 = v;
    return 1;
}
