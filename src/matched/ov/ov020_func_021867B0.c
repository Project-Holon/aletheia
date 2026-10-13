/*
 * function: FIELD_WFBC_DATA_LOCAL_GetNpcId
 * address: 0x021867B0
 * packet: pkt_ov020_021867B0
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Follower 021867B4 is already filed separately.
 */

typedef unsigned char u8;
int FIELD_WFBC_DATA_LOCAL_GetNpcId(u8 *p) { return p[1]; }
