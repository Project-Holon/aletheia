/*
 * function: SHINKA_DEMO_VIEW_SetModelOffset
 * address:  0x022067B0
 * packet:   pkt_022067B0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj10826.h"

void SHINKA_DEMO_VIEW_SetModelOffset(char *a, int b, int c, int d, int e)
{
    ((struct Obj10826 *)a)->f1C = c;
    *(int *)(a + 0x1c + 4) = d;
    *(int *)(a + 0x1c + 8) = e;
}
