/*
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

#include "../../../matched/include/G_021B3C84.h"

extern struct G_021B3C84 d_021B3C84;

void CTRDG_SetPulledOutCallback(void *cb)
{
	*(void **)(((unsigned char *)&d_021B3C84) + 0x18) = cb;
}

