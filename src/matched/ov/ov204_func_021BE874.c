/*
 * function: func_021BE874
 * address:  0x021BE874
 * packet:   pkt_021BE874
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRO_G3D_SetAnimFrame 0x021BFBC8 thumb
 */
#include "../include/Obj25372.h"

extern void INTRO_G3D_SetAnimFrame(char *p, unsigned value);

int func_021BE874(char *a, int b, int *p)
{
    INTRO_G3D_SetAnimFrame((char *)(((struct Obj25372 *)a)->fC), *p);
    return 1;
}
