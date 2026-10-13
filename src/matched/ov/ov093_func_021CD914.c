/*
 * function: BTL_CLIENT_MarkCommandIssued
 * address: 0x021CD914
 * packet: pkt_ov093_021CD914
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void BTL_CLIENT_MarkCommandIssued(u8 *p) {p[0x1b2]|=2;}
