/*
 * unit:     yes
 * function: func_021B6154, func_021B6158
 * address:  0x021B6154
 * packet:   pkt_ov098_021B6154
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled getters at +0x18 and +0x1c, filed as the blocker of
 * func_021B644C (lane S25). tu range is the 8 code bytes only; the
 * listing extent runs on into func_021B615C.
 */
#include "../include/Obj22003.h"
#include "../include/Obj22004.h"

int func_021B6154(void *p)
{
    return ((struct Obj22003 *)p)->f18;
}

int func_021B6158(void *p)
{
    return ((struct Obj22004 *)p)->f1C;
}
