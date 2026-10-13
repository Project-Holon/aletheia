/*
 * function: NET_WHPIPE_TaskStartParent
 * address: 0x02177CE4
 * packet: pkt_ov014_02177CE4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   WIH_GetSysState 0x02178E4C thumb ov014
 *   WIH_StartMeasureChannel 0x02178E84 thumb ov014
 *   NET_WHPIPE_SetTask 0x0217727C thumb ov014
 *   NET_WHPIPE_TaskConnectParent 0x02177C4C thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
extern int WIH_GetSysState(void);
extern int WIH_StartMeasureChannel(void);
extern void NET_WHPIPE_SetTask(unsigned int *p, unsigned int v);
extern void NET_WHPIPE_TaskConnectParent(unsigned char *p);
void NET_WHPIPE_TaskStartParent(void) { if (WIH_GetSysState() == 1 && WIH_StartMeasureChannel() != 0) NET_WHPIPE_SetTask((unsigned int *)g_pWhPipeWork, (unsigned int)NET_WHPIPE_TaskConnectParent); }
