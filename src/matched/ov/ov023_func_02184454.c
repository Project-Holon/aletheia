/*
 * function: func_02184454
 * address:  0x02184454
 * packet:   pkt_02184454
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 */
#include "../include/Obj20339.h"

typedef unsigned short u16;
extern u16 func_02039338(void);

void func_02184454(int a0, int a1, int a2, char *a3)
{
    if (func_02039338())
        return;
    ((struct Obj20339 *)a3)->f9280 |= 1 << a0;
}
