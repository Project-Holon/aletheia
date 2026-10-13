/*
 * function: NET_WHPIPE_RequestFinalize
 * address:  0x021776C4
 * packet:   pkt_ov014_021776C4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   func_02179498  0x02179498  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb  ov014
 *   NET_WHPIPE_TaskWaitFinalize  0x02177660  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern int func_02179498(void);
typedef unsigned int   u32;
extern void NET_WHPIPE_SetTask(u32 *p, u32 v);
extern void NET_WHPIPE_TaskWaitFinalize(u8 *p);

int NET_WHPIPE_RequestFinalize(void)
{
    u8 *w = ((u8 *)g_pWhPipeWork);

    if (w == 0)
        return 1;
    if (w[0xCE7] == 0 && func_02179498() != 0) {
        w[0xCF5] = 0xFF;
        NET_WHPIPE_SetTask((u32 *)((u8 *)g_pWhPipeWork), (u32)NET_WHPIPE_TaskWaitFinalize);
        return 1;
    }
    return 0;
}
