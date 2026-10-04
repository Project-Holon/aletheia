/*
 * unit:     yes
 * function: func_021B7CBC, func_021B7CC0, func_021B7CC4
 * address:  0x021B7CBC
 * packet:   pkt_021B7CBC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * three int getters at +0, +8, +4.
 */
#include "../include/Obj22144.h"
#include "../include/Obj22145.h"
#include "../include/Obj22146.h"

int func_021B7CBC(void *p)
{
    return ((struct Obj22144 *)p)->f0;
}

int func_021B7CC0(void *p)
{
    return ((struct Obj22145 *)p)->f8;
}

int func_021B7CC4(void *p)
{
    return ((struct Obj22146 *)p)->f4;
}
