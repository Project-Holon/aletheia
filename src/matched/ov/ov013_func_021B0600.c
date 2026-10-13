/*
 * function: VCT_SESSION_ClearMemberCount
 * address: 0x021B0600
 * packet: pkt_ov013_021B0600
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctSendState 0x021B3C84 data a4
 */

#include "../include/G_021B3C84.h"

extern struct G_021B3C84 gVctSendState;
void VCT_SESSION_ClearMemberCount(void) { ((int *)&gVctSendState)[8] = 0; }
