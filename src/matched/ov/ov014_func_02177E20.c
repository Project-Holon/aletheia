/*
 * function: NET_WHPIPE_StartChild
 * address:  0x02177E20
 * packet:   pkt_ov014_02177E20
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_EndScan  0x021788FC  thumb  ov014
 *   NET_WHPIPE_SetTask  0x0217727C  thumb
 *   NET_WHPIPE_TaskConnectChild  0x02177DB0  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
void *GFL_NET_GetInitParam(void);
int WIH_GetSysState(void);
int DWCi_MOV_WH_EndScan(void);
void NET_WHPIPE_SetTask(u32 *p, u32 v);
void NET_WHPIPE_TaskConnectChild(void);
void MI_CpuCopy8(void *d, void *s, u32 n);

int NET_WHPIPE_StartChild(u32 a, u8 *b, u32 c, u32 d)
{
    GFL_NET_GetInitParam();
    if (*(u32 *)g_pWhPipeWork != 0)
        return 0;
    if (WIH_GetSysState() == 2) {
        g_pWhPipeWork[0xCE9] = 0;
        DWCi_MOV_WH_EndScan();
    }
    NET_WHPIPE_SetTask((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskConnectChild);
    if (b != 0)
        MI_CpuCopy8(b, g_pWhPipeWork + 0xCDE, 6);
    else
        MI_CpuCopy8(g_pWhPipeWork + 0xC + c * 0xC0, g_pWhPipeWork + 0xCDE, 6);
    *(u32 *)(g_pWhPipeWork + 0xC60) = d;
    return 1;
}
