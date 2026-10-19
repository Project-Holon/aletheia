/*
 * function: VCT_MIXER_SetFilterEnabled
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

#include "../include/G_021B3C84.h"

extern struct G_021B3C84 gVctSendState;

void VCT_MIXER_SetFilterEnabled(void *cb)
{
	*(void **)(((unsigned char *)&gVctSendState) + 0x18) = cb;
}

