/*
 * function: DWC_RAP_IsWorkAllocated
 * address:  0x02155388
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True when the block pointer is set.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 */

#include "../include/G__anon_Work.h"

extern struct _anon_Work *g_021A8264;

int DWC_RAP_IsWorkAllocated(void)
{
    return ((char *)g_021A8264) != 0;
}

