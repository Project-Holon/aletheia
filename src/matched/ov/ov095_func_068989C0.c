/*
 * function: HAND_POS_GetHandlersFutureSight
 * address: 0x068989C0
 * packet: pkt_ov095_068989C0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower of the non-C veneer at 0x068989B0; code and pool end at 0x068989CC.
 * symbols:
 *   gHandPosFutureSightHandlers 0x0689D6A0 data a4
 */
typedef unsigned int u32;
extern char gHandPosFutureSightHandlers[];
void *HAND_POS_GetHandlersFutureSight(u32 *p)
{
    *p = 1;
    return gHandPosFutureSightHandlers;
}
