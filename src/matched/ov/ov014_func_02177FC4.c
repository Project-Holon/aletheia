/*
 * function: NET_WHPIPE_TaskChildScanWait
 * address: 0x02177FC4
 * packet: pkt_ov014_02177FC4
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   DWCi_MOV_WH_EndScan 0x021788FC thumb ov014
 *   NET_WHPIPE_SetTask 0x0217727C thumb ov014
 *   NET_WHPIPE_TaskParentSearchStart 0x02177F48 thumb ov014
 */

extern unsigned char *g_pWhPipeWork;
extern int DWCi_MOV_WH_EndScan(void);
extern void NET_WHPIPE_SetTask(unsigned int *p, unsigned int v);
extern void NET_WHPIPE_TaskParentSearchStart(unsigned char *p);
void NET_WHPIPE_TaskChildScanWait(unsigned char *p) { p[0xCF2]--; if (p[0xCF2] == 0) { DWCi_MOV_WH_EndScan(); NET_WHPIPE_SetTask((unsigned int *)g_pWhPipeWork, (unsigned int)NET_WHPIPE_TaskParentSearchStart); } }
