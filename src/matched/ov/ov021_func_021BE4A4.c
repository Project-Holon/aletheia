/*
 * function: FLD_EXP_OBJ_SetModelCullDraw
 * address:  0x021BE4A4
 * packet:   pkt_ov021_021BE4A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: store v into slot j (stride 0x44) of the array whose
 * pointer sits at +0xC of element i (stride 0x10).
 *
 * symbols:
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb
 */
#include "../include/Obj20142.h"

void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v)
{
    char *e = p + i * 0x10;

    *(int *)(*(char * *)&((struct Obj20142 *)e)->fC + j * 0x44) = v;
}
