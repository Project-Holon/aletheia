/*
 * function: NET_WHPIPE_StartAutoSearch
 * address:  0x02178034
 * packet:   pkt_ov014_02178034
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   NET_WHPIPE_StartJoinLock  0x021780E4  thumb  ov014
 *   NET_WHPIPE_ResetState  0x0217758C  thumb  ov014
 *   NET_WHPIPE_ClearEntries  0x02177560  thumb  ov014
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb
 *   NET_WHPIPE_ForwardEvent  0x021775AC  thumb  ov014
 *   NET_WHPIPE_TaskChildScanStart  0x02177FF0  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
void NET_WHPIPE_StartJoinLock(int a);
void NET_WHPIPE_ResetState(u8 *p);
void NET_WHPIPE_ClearEntries(void);
void DWCi_MOV_WH_SetReceiver(void *fn);
void NET_WHPIPE_SetTask(u32 *p, u32 v);
int NET_WHPIPE_ForwardEvent(int a, int b, int c);
void NET_WHPIPE_TaskChildScanStart(u8 *a);

int NET_WHPIPE_StartAutoSearch(void)
{
    u8 *p = g_pWhPipeWork;
    if (p == 0)
        return 0;
    NET_WHPIPE_StartJoinLock(0);
    NET_WHPIPE_ResetState(p);
    NET_WHPIPE_ClearEntries();
    DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
    p[0xCE8] = 1;
    NET_WHPIPE_SetTask((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskChildScanStart);
    return 1;
}
