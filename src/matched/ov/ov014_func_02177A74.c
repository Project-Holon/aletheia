/*
 * function: NET_WHPIPE_GetConnectedNum
 * address: 0x02177A74
 * packet: pkt_ov014_02177A74
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * evidence: original truncates the index to u16 before calling A34; extern follows caller width.
 * extent: trailing two zero bytes are alignment padding.
 * symbols:
 *   NET_WHPIPE_IsAidConnected 0x02177A34 thumb ov014
 */

extern int NET_WHPIPE_IsAidConnected(unsigned short n);
int NET_WHPIPE_GetConnectedNum(void) { int count = 0; int i = 0; for (; i < 8; i++) { if (NET_WHPIPE_IsAidConnected(i) != 0) count++; } return count; }
