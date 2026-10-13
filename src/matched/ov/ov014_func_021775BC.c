/*
 * function: NET_WHPIPE_StartScan
 * address:  0x021775BC
 * packet:   pkt_ov014_021775BC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   NET_WHPIPE_ResetState  0x0217758C  thumb  ov014
 *   NET_WHPIPE_ClearEntries  0x02177560  thumb  ov014
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   NET_WHPIPE_ForwardEvent  0x021775AC  thumb  ov014
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_StartScan  0x021785B4  thumb  ov014
 *   NET_WHPIPE_StoreScannedEntry  0x021773E0  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern void NET_WHPIPE_ResetState(u8 *w);
extern void NET_WHPIPE_ClearEntries(void);
extern void DWCi_MOV_WH_SetReceiver(void *cb);
extern int NET_WHPIPE_ForwardEvent(int a, int b, int c);
extern int WIH_GetSysState(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int DWCi_MOV_WH_StartScan(u32 a, u16 *b, u32 c);
extern int NET_WHPIPE_StoreScannedEntry(u8 *p);

int NET_WHPIPE_StartScan(int arg)
{
    u8 *w = ((u8 *)g_pWhPipeWork);

    if (w == 0)
        return 0;
    NET_WHPIPE_ResetState(w);
    if (arg != 0)
        NET_WHPIPE_ClearEntries();
    DWCi_MOV_WH_SetReceiver(NET_WHPIPE_ForwardEvent);
    w[0xCE8] = 1;
    if (WIH_GetSysState() == 1 && DWCi_MOV_WH_StartScan((u32)NET_WHPIPE_StoreScannedEntry, 0, 0) != 0)
        return 1;
    return 0;
}
