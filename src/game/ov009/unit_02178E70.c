/*
 * file:     unit_02178E70.c
 * function: func_02178E70
 * address:  0x02178E70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at the head of the module state block.
 *
 * symbols:
 *   g_021AB1A4  0x021AB1A4  data
 */

#include "../../matched/include/G_DWCAuthState.h"

extern struct DWCAuthState g_021AB1A4;

int func_02178E70(void)
{
    return *(int *)((char *)&g_021AB1A4);
}

