/*
 * function: FLD_EXP_OBJ_SetModelHidden
 * address:  0x021BE4B4
 * packet:   pkt_ov021_021BE4B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, sibling of FLD_EXP_OBJ_SetModelCullDraw: store v at +4 of slot j
 * (stride 0x44) of the array whose pointer sits at +0xC of element i
 * (stride 0x10).  Leaf of ov062 func_021F36C0.
 *
 * symbols:
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb
 */
#include "../include/Obj20143.h"

void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20143 *)e)->fC + j * 0x44 + 4) = v;
}
