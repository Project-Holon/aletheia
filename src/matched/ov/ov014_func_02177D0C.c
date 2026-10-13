/*
 * function: NET_WHPIPE_StartParent
 * address:  0x02177D0C
 * packet:   pkt_ov014_02177D0C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_021775AC  0x021775AC  thumb  ov014
 *   NET_WHPIPE_TaskStartParent  0x02177CE4  thumb  ov014
 */
#include "../include/Obj12469.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
void DWCi_MOV_WH_SetReceiver(void *fn);
void func_0217727C(u32 *p, u32 v);
int func_021775AC(int a, int b, int c);
void NET_WHPIPE_TaskStartParent(void);

int NET_WHPIPE_StartParent(int a)
{
    u8 *p = g_pWhPipeWork;
    if (((struct Obj12469 *)p)->f0 != 0)
        return 0;
    if (a != 0)
        p[0xCE6] = 0xff;
    DWCi_MOV_WH_SetReceiver(func_021775AC);
    g_pWhPipeWork[0xCE8] = 1;
    func_0217727C((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskStartParent);
    return 1;
}
