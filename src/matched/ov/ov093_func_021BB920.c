/*
 * function: BTL_SERVER_ClearPokeChangeRequests
 * address: 0x021BB920
 * packet: pkt_ov093_021BB920
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void BTL_SERVER_ClearPokeChangeRequests(u8 *p) { p[0xcba] = 0; p[0xcbf] = 0; }
