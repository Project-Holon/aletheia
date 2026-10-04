/*
 * function: func_021B6390
 * address:  0x021B6390
 * packet:   pkt_ov173_021B6390
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028178  0x02028178  thumb
 */
#include "../include/Obj06564.h"

typedef unsigned char  u8;
extern void func_02028178(u8 *p);

void func_021B6390(int *p)
{
    if (((struct Obj06564 *)p)->f220) {
        func_02028178((u8 *)(((struct Obj06564 *)p)->f220));
        func_02028178((u8 *)(((struct Obj06564 *)p)->f224));
    }
}
