/*
 * function: func_021B624C
 * address:  0x021B624C
 * packet:   pkt_021B624C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 */
#include "../include/Obj24464.h"

extern int func_020056A0(void *, int *, int);

void func_021B624C(int *p)
{
    ((struct Obj24464 *)p)->f6014 = func_020056A0((void *)0x021B6279, p, 0);
}
