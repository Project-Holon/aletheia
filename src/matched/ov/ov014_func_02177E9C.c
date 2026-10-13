/*
 * function: NET_WHPIPE_TaskFinishEnd
 * address: 0x02177E9C
 * packet: pkt_ov014_02177E9C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   NET_WHPIPE_Destroy 0x02177704 thumb ov014
 */

extern int WIH_GetSysState(void);
extern void WIH_FreeWork(void);
extern void NET_WHPIPE_Destroy(void);
void NET_WHPIPE_TaskFinishEnd(void) { if (WIH_GetSysState() == 0) { WIH_FreeWork(); NET_WHPIPE_Destroy(); } }
