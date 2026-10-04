/*
 * function: func_021B1AA0
 * address:  0x021B1AA0
 * packet:   pkt_021B1AA0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj01641.h"

void func_021B1AA0(char *p, unsigned short v)
{
    ((struct Obj01641 *)p)->f68 = v;
    *(int *)&((struct Obj01641 *)p)->f64 = 0x00010001;
    *(int *)&((struct Obj01641 *)p)->f60 = 0;
    ((struct Obj01641 *)p)->f5C = 0;
}
