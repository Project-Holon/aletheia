/*
 * function: NET_WHPIPE_TaskParentSearchStart
 * address:  0x02177F48
 * packet:   pkt_ov014_02177F48
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   g_SearchChannels     0x02179678  data  a1
 *   NET_WHPIPE_IsIdle  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb  ov014
 *   WIH_ParentConnect  0x02179288  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb
 *   NET_WHPIPE_TaskParentSearchWait  0x02177EFC  thumb
 */
#include "../include/Obj04956.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
extern u8 g_SearchChannels[3];
int NET_WHPIPE_IsIdle(void);
u32 func_020056EC(u32 n);
void NET_WHPIPE_PublishBeacon(void);
int WIH_ParentConnect(int mode, u16 a, int b, u16 c);
void NET_WHPIPE_SetTask(u32 *p, u32 v);
void NET_WHPIPE_TaskParentSearchWait(u8 *a);

void NET_WHPIPE_TaskParentSearchStart(u8 *a)
{
    u8 tab[3];
    if (NET_WHPIPE_IsIdle() != 0) {
        tab[0] = g_SearchChannels[0];
        tab[1] = g_SearchChannels[1];
        tab[2] = g_SearchChannels[2];
        a[0xCF1] = func_020056EC(3);
        if (a[0xCF1] >= 3)
            a[0xCF1] = 0;
        NET_WHPIPE_PublishBeacon();
        if (WIH_ParentConnect(0, ((struct Obj04956 *)a)->fC68, tab[a[0xCF1]], 1) != 0) {
            a[0xCF2] = func_020056EC(0x98) + 0x3C;
            NET_WHPIPE_SetTask((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskParentSearchWait);
        }
    }
}
