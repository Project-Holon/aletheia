/*
 * function: func_021B68B0
 * address:  0x021B68B0
 * packet:   pkt_021B68B0
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 */
#include "../include/Obj24152.h"

extern int func_020221A4(int *);

int func_021B68B0(int *p)
{
    if (func_020221A4(p) == 1)
        return ((struct Obj24152 *)p)->f1B0;
    return 0;
}
