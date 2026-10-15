/*
 * function: DWCi_Auth_IsSucceeded
 * address:  0x02178E80
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The word at +8 of the module state block.
 *
 * symbols:
 *   gDwcAuthState  0x021AB1A4  data
 */

#include "../include/G_DWCAuthState.h"

extern struct DWCAuthState gDwcAuthState;

int DWCi_Auth_IsSucceeded(void)
{
    return *(int *)(((char *)&gDwcAuthState) + 8);
}

