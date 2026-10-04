/*
 * unit:     yes
 * function: func_021B7CA0, func_021B7CA4, func_021B7CA8, func_021B7CAC
 * address:  0x021B7CA0
 * packet:   pkt_021B7CA0
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22244.h"
#include "../include/Obj22245.h"
#include "../include/Obj22246.h"
#include "../include/Obj22247.h"

int func_021B7CA0(void *p)
{
    return ((struct Obj22244 *)p)->f0;
}

int func_021B7CA4(void *p)
{
    return ((struct Obj22245 *)p)->f8;
}

int func_021B7CA8(void *p)
{
    return ((struct Obj22246 *)p)->f4;
}

int func_021B7CAC(void *p)
{
    return ((struct Obj22247 *)p)->fC;
}
