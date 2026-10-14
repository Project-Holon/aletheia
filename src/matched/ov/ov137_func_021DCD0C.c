/*
 * function: GURU2_COMM_GetOwnPlayerId
 * address: 0x021DCD0C
 * packet: pkt_ov137_021DCD0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
extern int GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_COMM_GetOwnPlayerId(void) {return GFL_NET_SYSTEM_GetCurrentAid();}
