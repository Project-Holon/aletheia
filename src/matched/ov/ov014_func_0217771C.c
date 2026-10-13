/*
 * function: NET_WHPIPE_NotifyEntryAcceptable
 * address: 0x0217771C
 * packet: pkt_ov014_0217771C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   NET_WHPIPE_IsBeaconAcceptable 0x0217731C thumb ov014
 */

typedef unsigned char u8;
extern u8 *g_pWhPipeWork;
extern int NET_WHPIPE_IsBeaconAcceptable(u8 *obj);
int NET_WHPIPE_NotifyEntryAcceptable(u8 *obj) { u8 *base = g_pWhPipeWork; void (*fn)(void); if (NET_WHPIPE_IsBeaconAcceptable(obj) == 0) return 0; fn = *(void (**)(void))(base + 0xC60); if (fn != 0) fn(); return 1; }
