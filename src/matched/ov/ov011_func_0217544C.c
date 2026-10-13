/*
 * function: INTRUDE_COMM_SetRequestOpen
 * address: 0x0217544C
 * packet: pkt_ov011_0217544C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void INTRUDE_COMM_SetRequestOpen(u8 *p) { p[0x8F8] |= 0x10; }
