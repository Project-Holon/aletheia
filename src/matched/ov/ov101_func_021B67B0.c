/*
 * function: COMPATIBLE_IRC_SYS_ProfileSyncPollRequest
 * address: 0x021B67B0
 * packet: pkt_ov101_021B67B0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
int COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(int *p) { if(p[6]==1) { p[6]=0; return 1; } return 0; }
