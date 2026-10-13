/*
 * function: NET_WHPIPE_IsIdle
 * address: 0x02177AA8
 * packet: pkt_ov014_02177AA8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   WIH_GetSysState 0x02178E4C thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
extern int WIH_GetSysState(void);
int NET_WHPIPE_IsIdle(void) { if (g_pWhPipeWork != 0) { if (WIH_GetSysState() == 1) return 1; return 0; } return 1; }
