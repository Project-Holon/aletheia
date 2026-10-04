/*
 * function: func_021DEE90
 * address:  0x021DEE90
 * packet:   pkt_021DEE90
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13960.h"

typedef unsigned int u32;

void func_021DEE90(char *p)
{
    if (((struct Obj13960 *)p)->f4 == 0)
        (*(void (**)(char *, char *, u32))p)(p, p + 8, ((struct Obj13960 *)p)->fC);
}
