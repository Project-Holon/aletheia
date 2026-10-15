/*
 * function: RESEARCH_TOP_MoveSelection
 * address:  0x021BA388
 * packet:   pkt_ov217_021BA388
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_TOP_IsSelectionValid  0x021BA3B4  thumb  ov217
 */
#include "../include/Obj00511.h"

typedef unsigned int   u32;
extern u32 RESEARCH_TOP_IsSelectionValid(u32 a0, u32 a1);

void RESEARCH_TOP_MoveSelection(char *self, int d)
{
    int n = *(int *)&((struct Obj00511 *)self)->f28;
    do {
        n = (n + d + 2) % 2;
    } while (!RESEARCH_TOP_IsSelectionValid((u32)self, n));
    *(int *)&((struct Obj00511 *)self)->f28 = n;
}
