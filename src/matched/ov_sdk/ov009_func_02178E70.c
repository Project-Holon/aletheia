/*
 * function: DWCi_Auth_IsFinished
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
 *   gDwcAuthState  0x021AB1A4  data
 */

#include "../include/G_DWCAuthState.h"

extern struct DWCAuthState gDwcAuthState;

int DWCi_Auth_IsFinished(void)
{
    return *(int *)((char *)&gDwcAuthState);
}

