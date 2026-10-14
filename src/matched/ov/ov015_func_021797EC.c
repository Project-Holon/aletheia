/*
 * unit: yes
 * function: IRCNET_CbResend, IRCNET_CbReturnTrue
 * address: 0x021797EC
 * packet: pkt_ov015_021797EC
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes constant-return follower 021797F8; root claimed.
 * symbols:
 *   IRCNET_ResendPending 0x02179AAC thumb ov015
 */
extern void IRCNET_ResendPending(void);
int IRCNET_CbResend(void) { IRCNET_ResendPending(); return 0; }
int IRCNET_CbReturnTrue(void) { return 1; }
