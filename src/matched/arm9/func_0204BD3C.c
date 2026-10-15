/*
 * unit:     no
 * function: CLACT_InitOamManager
 * address:  0x0204BD3C
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  02063138 has no witness outside this range
 *
 * symbols:
 *   NNSi_G2dReserveOamManagerSpan  0x02063138  arm
 */
#include "../include/Obj11428.h"

extern unsigned int NNSi_G2dReserveOamManagerSpan(void *p, int a, int b, int which);
void CLACT_InitOamManager(char *p, int a, int b, int which)
{
    if (b == 0) {
        ((struct Obj11428 *)p)->f1C = 0;
        return;
    }
    NNSi_G2dReserveOamManagerSpan(p, a, b, which);
    ((struct Obj11428 *)p)->f1C = 1;
}
