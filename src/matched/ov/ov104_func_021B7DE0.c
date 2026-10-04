/*
 * unit:     yes
 * function: func_021B7DE0, func_021B7DE4, func_021B7DE8, func_021B7DEC
 * address:  0x021B7DE0
 * packet:   pkt_021B7DE0
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22220.h"
#include "../include/Obj22221.h"
#include "../include/Obj22222.h"
#include "../include/Obj22223.h"

int func_021B7DE0(void *p)
{
    return ((struct Obj22220 *)p)->f0;
}

int func_021B7DE4(void *p)
{
    return ((struct Obj22221 *)p)->f8;
}

int func_021B7DE8(void *p)
{
    return ((struct Obj22222 *)p)->f4;
}

int func_021B7DEC(void *p)
{
    return ((struct Obj22223 *)p)->fC;
}
