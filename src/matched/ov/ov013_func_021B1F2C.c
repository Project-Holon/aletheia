/*
 * function: VCT_SESSION_AllocPeerRecord
 * address: 0x021B1F2C
 * packet: pkt_ov013_021B1F2C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctSession 0x021B60D8 data a4
 *   VCT_SESSION_AllocPeer 0x021B24FC arm ov013
 */

#include "../include/G_Sess.h"

extern struct Sess gVctSession;
struct Node;
extern struct Node *VCT_SESSION_AllocPeer(unsigned int);
struct Node *VCT_SESSION_AllocPeerRecord(unsigned int i)
{
    if (((unsigned int *)&gVctSession)[4] == 0 || ((unsigned int *)&gVctSession)[4] == 2) return 0;
    return VCT_SESSION_AllocPeer(i);
}
