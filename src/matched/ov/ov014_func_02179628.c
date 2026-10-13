/*
 * function: WIH_SetConnectCallback
 * address: 0x02179628
 * packet: pkt_ov014_02179628
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *g_021797A8;
void WIH_SetConnectCallback(unsigned v) { *(unsigned *)(g_021797A8 + 0x1E84) = v; }
