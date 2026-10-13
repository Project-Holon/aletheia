/*
 * function: SNDi_GetBankWaveArcTable
 * address:  0x0208A638
 * packet:   pkt_0208A638
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16693.h"

void *SNDi_GetBankWaveArcTable(char *p)
{
    return ((struct Obj16693 *)p)->f38;
}
