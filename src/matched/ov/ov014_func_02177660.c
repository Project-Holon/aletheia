/*
 * function: NET_WHPIPE_TaskWaitFinalize
 * address:  0x02177660
 * packet:   pkt_ov014_02177660
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_StateInEndKeyShare  0x0217945C  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb  ov014
 *   NET_WHPIPE_TaskBeginFinalize  0x02177614  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern int WIH_GetSysState(void);
extern void DWCi_MOV_WH_StateInEndKeyShare(void);
typedef unsigned int   u32;
extern void NET_WHPIPE_SetTask(u32 *p, u32 v);
extern void NET_WHPIPE_TaskBeginFinalize(u8 *p);

void NET_WHPIPE_TaskWaitFinalize(u8 *p)
{
    p[0xCF5]--;
    if (WIH_GetSysState() == 0 || WIH_GetSysState() == 1) {
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), 0);
        return;
    }
    if (WIH_GetSysState() == 9) {
        DWCi_MOV_WH_StateInEndKeyShare();
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), (u32)NET_WHPIPE_TaskBeginFinalize);
        return;
    }
    if (p[0xCF5] == 0) {
        DWCi_MOV_WH_StateInEndKeyShare();
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), (u32)NET_WHPIPE_TaskBeginFinalize);
    }
}
