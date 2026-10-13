/*
 * function: FLDMMDL_AddGridNowX
 * address:  0x0216D848
 * packet:   pkt_0216D848
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj19129.h"

void FLDMMDL_AddGridNowX(char *p, short v)
{
    ((struct Obj19129 *)p)->f3C += v;
}
