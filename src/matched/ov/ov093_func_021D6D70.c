/*
 * function: BTL_POKEPARAM_ClearSubstitute
 * address:  0x021D6D70
 * packet:   pkt_ov093_021D6D70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj21240.h"

void BTL_POKEPARAM_ClearSubstitute(unsigned char *p)
{
    ((struct Obj21240 *)p)->f1F2 = 0;
}
