/*
 * function: NET_WHPIPE_TaskChildScanStart
 * address:  0x02177FF0
 * packet:   pkt_ov014_02177FF0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_StartScan  0x021785B4  thumb
 *   func_020056EC  0x020056EC  thumb
 *   NET_WHPIPE_SetTask  0x0217727C  thumb
 *   NET_WHPIPE_StoreScannedEntry  0x021773E0  thumb  ov014
 *   NET_WHPIPE_TaskChildScanWait  0x02177FC4  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
int WIH_GetSysState(void);
typedef unsigned short u16;
int DWCi_MOV_WH_StartScan(u32 a, u16 *b, u32 c);
u32 func_020056EC(u32 n);
void NET_WHPIPE_SetTask(u32 *p, u32 v);
int NET_WHPIPE_StoreScannedEntry(u8 *p);
void NET_WHPIPE_TaskChildScanWait(unsigned char *p);

void NET_WHPIPE_TaskChildScanStart(u8 *a)
{
    if (WIH_GetSysState() == 1) {
        if (DWCi_MOV_WH_StartScan((u32)NET_WHPIPE_StoreScannedEntry, 0, 0) != 0) {
            a[0xCF2] = func_020056EC(0x28) + 0x3C;
            NET_WHPIPE_SetTask((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskChildScanWait);
        }
    }
}
