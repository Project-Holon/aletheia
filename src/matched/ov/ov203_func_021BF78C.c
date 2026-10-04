/*
 * function: func_021BF78C
 * address:  0x021BF78C
 * packet:   pkt_021BF78C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9B8 0x021BE9B8 thumb
 */
#include "../include/Obj14597.h"

extern void *func_021BE9B8(void *p, unsigned a, unsigned b);

void func_021BF78C(char *a, int unused, int *p)
{
    ((struct Obj14597 *)a)->f2C = (int)func_021BE9B8((void *)(((struct Obj14597 *)a)->f20), p[0], p[1]);
}
