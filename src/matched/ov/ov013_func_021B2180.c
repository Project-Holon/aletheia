/*
 * function: VCT_SESSION_SendPeerReply
 * address: 0x021B2180
 * packet: pkt_ov013_021B2180
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctSession 0x021B60D8 data a4
 *   VCT_SESSION_SendReply 0x021B25B0 arm ov013
 */

#include "../include/G_Sess.h"

extern struct Sess gVctSession;
extern int VCT_SESSION_SendReply(int, int);
int VCT_SESSION_SendPeerReply(int a, int b)
{
    if (((int *)&gVctSession)[4] == 2) return -3;
    return VCT_SESSION_SendReply(a,b);
}
