/*
 * function: MCSS_SetShadowAlpha
 * address:  0x02015FD4
 * packet:   pkt_02015FD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor, the follower of MCSS_SetAlpha: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that MCSS_SetAlpha's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 *
 * symbols:
 *   MCSS_SetShadowAlpha  0x02015FD4  thumb
 */
#include "../include/Obj11257.h"

void MCSS_SetShadowAlpha(char *p, int v)
{
    ((struct Obj11257 *)p)->f140 = (((struct Obj11257 *)p)->f140 & 0xFF803FFF) | ((v & 0x1FF) << 14);
}
