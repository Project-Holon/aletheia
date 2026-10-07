/*
 * function: func_02178E90
 * address:  0x02178E90
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
 *   g_021AB1A4  0x021AB1A4  data
 */

#include "../include/G_DWCAuthState.h"

extern struct DWCAuthState g_021AB1A4;

int func_02178E90(void)
{
    return *(int *)(((char *)&g_021AB1A4) + 4);
}

