/*
 * function: func_021B1A48
 * address:  0x021B1A48
 * packet:   pkt_021B1A48
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 */
#include "../include/Obj07347.h"

extern void func_021B2FE4(void *p);

void func_021B1A48(char *p)
{
    if (((struct Obj07347 *)p)->f3C) {
        func_021B2FE4(((struct Obj07347 *)p)->f3C);
        *(int *)&((struct Obj07347 *)p)->f3C = 0;
    }
    ((struct Obj07347 *)p)->f38 = -1;
}
