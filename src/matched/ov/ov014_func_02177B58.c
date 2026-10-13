/*
 * function: NET_WHPIPE_GetEntryBssid
 * address: 0x02177B58
 * packet: pkt_ov014_02177B58
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_pWhPipeWork;
u8 *NET_WHPIPE_GetEntryBssid(int i) { u8 *base = g_pWhPipeWork; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return base + 0xC + i * 0xC0; return 0; }
