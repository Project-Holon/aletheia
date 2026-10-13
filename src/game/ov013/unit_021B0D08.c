/*
 * file:     unit_021B0D08.c
 * function: CTRDG_SetPulledOutCallback
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
 *   d_021B3C84                   0x021B3C84  data
*/

#include "vct_types.h"

/* Switch the echo suppression stage of the voice chat on or off. */
void CTRDG_SetPulledOutCallback(int enabled)
{
	d_021B3C84.echoSuppressEnabled = enabled;
}
