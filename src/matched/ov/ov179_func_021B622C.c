/*
 * function: func_021B622C
 * address:  0x021B622C
 * packet:   pkt_ov179_021B622C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B68E4  0x021B68E4  data  a4
 */
#include "../include/Obj10716.h"
#include "../include/Obj24463.h"

extern int d_021B68E4[];

void func_021B622C(char *p)
{
    unsigned short idx = ((struct Obj24463 *)(((struct Obj10716 *)p)->f0))->f0;
    int v = d_021B68E4[idx];

    ((struct Obj10716 *)p)->f6018 = v;
    ((struct Obj10716 *)p)->f601C = v;
}
