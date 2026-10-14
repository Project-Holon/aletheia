/*
 * function: IRCNET_SetRecvCallback
 * address: 0x021799B4
 * packet: pkt_ov015_021799B4
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 021799C0 already filed separately.
 * symbols:
 *   gIrcNetWork 0x0217AAC0 data ov015 a4
 */
extern unsigned gIrcNetWork;
void IRCNET_SetRecvCallback(unsigned v) { gIrcNetWork = v; }
