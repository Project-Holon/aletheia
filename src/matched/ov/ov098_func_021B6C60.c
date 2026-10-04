/*
 * function: func_021B6C60
 * address:  0x021B6C60
 * packet:   pkt_ov098_021B6C60
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf inside the handed extent of func_021B6C34.
 */
#include "../include/Obj04409.h"

typedef unsigned char u8;

void func_021B6C60(char *p)
{
    u8 s = ((struct Obj04409 *)p)->f14;

    if (s == 0 || s == 3) {
        ((struct Obj04409 *)p)->f4 = 0x1f000;
        ((struct Obj04409 *)p)->f8 = 0x7000;
        ((struct Obj04409 *)p)->fC = -0x52aa;
        ((struct Obj04409 *)p)->f10 = 0x1800;
        ((struct Obj04409 *)p)->f15 = 6;
        ((struct Obj04409 *)p)->f14 = 1;
    }
}
