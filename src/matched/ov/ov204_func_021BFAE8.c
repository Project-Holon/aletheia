/*
 * function: func_021BFAE8
 * address: 0x021BFAE8
 * packet: pkt_ov204_021BFAE8
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj03922.h"

void func_021BFAE8(char *p, unsigned int v)
{
    ((struct Obj03922 *)p)->f1C = v;
    ((struct Obj03922 *)p)->f20 = 0;
    switch (v)
    {
    case 0:
        ((struct Obj03922 *)p)->f28 = 60;
        ((struct Obj03922 *)p)->f1C = 1;
        break;
    case 1: ((struct Obj03922 *)p)->f28 = 70; break;
    case 2: ((struct Obj03922 *)p)->f28 = 50; break;
    case 3: ((struct Obj03922 *)p)->f28 = 50; break;
    case 4: ((struct Obj03922 *)p)->f28 = 70; break;
    }
}
