/*
 * function: COMPATIBLE_IRC_SYS_PollProfileAck
 * address: 0x021B6554
 * packet: pkt_ov101_021B6554
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncPollAck 0x021B67E4 thumb ov101
 */
extern int COMPATIBLE_IRC_SYS_ProfileSyncPollAck(int *);
int COMPATIBLE_IRC_SYS_PollProfileAck(int *p) { if(p[30]) return 1; return COMPATIBLE_IRC_SYS_ProfileSyncPollAck(p+1); }
