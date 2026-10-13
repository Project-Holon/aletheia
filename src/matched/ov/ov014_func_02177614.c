/*
 * function: NET_WHPIPE_TaskBeginFinalize
 * address:  0x02177614
 * packet:   pkt_ov014_02177614
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   WIH_Finalize  0x02179498  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb  ov014
 *   NET_WHPIPE_TaskWaitFinalize  0x02177660  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern int WIH_GetSysState(void);
extern int WIH_Finalize(void);
typedef unsigned int   u32;
extern void NET_WHPIPE_SetTask(u32 *p, u32 v);
extern void NET_WHPIPE_TaskWaitFinalize(u8 *p);

void NET_WHPIPE_TaskBeginFinalize(u8 *p)
{
    if (WIH_GetSysState() == 1 && WIH_Finalize() != 0) {
        p[0xCF5] = 0xFF;
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), (u32)NET_WHPIPE_TaskWaitFinalize);
    }
    if (WIH_GetSysState() == 9) {
        p[0xCF5] = 0xFF;
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), (u32)NET_WHPIPE_TaskWaitFinalize);
    }
}
