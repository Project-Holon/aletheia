/*
 * function: FLDMMDL_AddGridNowZ
 * address:  0x0216D87C
 * packet:   pkt_0216D87C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19131.h"

void FLDMMDL_AddGridNowZ(char *p, short v)
{
    ((struct Obj19131 *)p)->f40 += v;
}
