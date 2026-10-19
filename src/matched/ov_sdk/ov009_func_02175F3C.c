/*
 * function: DWCi_GetMatchCnt
 * address:  0x02175F3C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at +4 of the module state block.
 *
 * symbols:
 *   g_021AAA20  0x021AAA20  data
 */

#include "../include/G_NNThinkGlobal.h"

extern struct NNThinkGlobal g_021AAA20;

int DWCi_GetMatchCnt(void)
{
    return *(int *)(((char *)&g_021AAA20) + 4);
}

