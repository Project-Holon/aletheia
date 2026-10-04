/*
 * function: func_021BA2E0
 * address:  0x021BA2E0
 * packet:   pkt_021BA2E0
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA330 0x021BA330 thumb
 */
#include "../include/Obj08419.h"

extern void func_021BA330(void *, int);

void func_021BA2E0(char *a)
{
    if (*(int *)&((struct Obj08419 *)a)->f50 == 0x2d)
        func_021BA330(a, ((struct Obj08419 *)a)->fC);
}