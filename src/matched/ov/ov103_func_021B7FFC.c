/*
 * unit:     yes
 * function: func_021B7FFC, func_021B8000, func_021B8004, func_021B8008
 * address:  0x021B7FFC
 * packet:   pkt_021B7FFC
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * four int getters at +0, +8, +4, +c.
 */
#include "../include/Obj22186.h"
#include "../include/Obj22187.h"
#include "../include/Obj22188.h"
#include "../include/Obj22189.h"

int func_021B7FFC(void *p)
{
    return ((struct Obj22186 *)p)->f0;
}

int func_021B8000(void *p)
{
    return ((struct Obj22187 *)p)->f8;
}

int func_021B8004(void *p)
{
    return ((struct Obj22188 *)p)->f4;
}

int func_021B8008(void *p)
{
    return ((struct Obj22189 *)p)->fC;
}
