/*
 * function: func_021BE864
 * address:  0x021BE864
 * packet:   pkt_021BE864
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRO_G3D_SetVisible 0x021BFAE4 thumb
 */
#include "../include/Obj25370.h"

extern void INTRO_G3D_SetVisible(char *p, int v);

int func_021BE864(char *a, int b, int *p)
{
    INTRO_G3D_SetVisible((char *)(((struct Obj25370 *)a)->fC), *p);
    return 1;
}
