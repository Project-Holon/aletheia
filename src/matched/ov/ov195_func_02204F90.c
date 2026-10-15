/*
 * function: SHINKA_DEMO_IsBgmState6
 * address:  0x02204F90
 * packet:   pkt_02204F90
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24949.h"

int SHINKA_DEMO_IsBgmState6(int a, char *b)
{
    if (((struct Obj24949 *)b)->f30 == 6)
        return 1;
    return 0;
}
