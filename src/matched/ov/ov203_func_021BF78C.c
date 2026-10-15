/*
 * function: DEMO3D_DATA_TaskCreateCapture
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
 *   DEMO3D_DATA_CreateCapture 0x021BE9B8 thumb
 */
#include "../include/Obj14597.h"

extern void *DEMO3D_DATA_CreateCapture(void *p, unsigned a, unsigned b);

void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p)
{
    ((struct Obj14597 *)a)->f2C = (int)DEMO3D_DATA_CreateCapture((void *)(((struct Obj14597 *)a)->f20), p[0], p[1]);
}
