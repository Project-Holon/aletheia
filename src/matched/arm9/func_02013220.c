/*
 * function: BTL_SETUP_InitFieldSituation
 * address:  0x02013220
 * packet:   pkt_02013220
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj04041.h"

void BTL_SETUP_InitFieldSituation(char *p)
{
    ((struct Obj04041 *)p)->f0 = 0;
    ((struct Obj04041 *)p)->f4 = 0;
    ((struct Obj04041 *)p)->f9 = 0;
    ((struct Obj04041 *)p)->f8 = 0;
    ((struct Obj04041 *)p)->fA = 0;
    ((struct Obj04041 *)p)->fC = 0xa;
    ((struct Obj04041 *)p)->fD = 0;
}
