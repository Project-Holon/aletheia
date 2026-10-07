/*
 * function: func_02155388
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

int func_02155388(void)
{
    return ((char *)g_021A8264) != 0;
}

