/*
 * file:     unit_021B0D08.c
 * function: VCT_SESSION_SetFilterEnabled
 * address:  0x021B0D08
 * packet:   pkt_ov013_021B0D08
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSendState                   0x021B3C84  data
*/

#include "vct_types.h"

/* Switch the echo suppression stage of the voice chat on or off. */
void VCT_SESSION_SetFilterEnabled(int enabled)
{
	gVctSendState.echoSuppressEnabled = enabled;
}
