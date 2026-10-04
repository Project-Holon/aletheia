/*
 * function: func_021BDC80
 * address:  0x021BDC80
 * packet:   pkt_021BDC80
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns one of three words selected by +0x10, or -1.
 */
#include "../include/Obj07227.h"


int func_021BDC80(char *p)
{
    switch (((struct Obj07227 *)p)->f10) {
    case 0:
        return ((struct Obj07227 *)p)->f44;
    case 1:
        return ((struct Obj07227 *)p)->f50;
    case 2:
        return ((struct Obj07227 *)p)->f5C;
    }
    return -1;
}

