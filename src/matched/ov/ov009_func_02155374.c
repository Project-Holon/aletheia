/*
 * function: DWC_RAP_SetState
 * address:  0x02155374
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores a word at +0x754 of the block the pointer holds.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 */

#include "../include/G__anon_Work.h"

extern struct _anon_Work *g_021A8264;

void DWC_RAP_SetState(int v)
{
    *(int *)(((char *)g_021A8264) + 0x754) = v;
}

