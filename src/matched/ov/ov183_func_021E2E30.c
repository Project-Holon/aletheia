/*
 * function: func_021E2E30
 * address:  0x021E2E30
 * packet:   pkt_021E2E30
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj14443.h"

void func_021E2E30(char *p, int a1, int a2)
{
    if (((struct Obj14443 *)p)->f0 != 0) {
        ((void (*)(int, int)) * (void **)p)(a1, a2);
        *(int *)&((struct Obj14443 *)p)->f0 = 0;
    }
}
