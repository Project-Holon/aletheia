/*
 * function: NET_WHPIPE_TaskConnectChild
 * address:  0x02177DB0
 * packet:   pkt_ov014_02177DB0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   g_ChildConnectModes     0x02179680  data  ov014  a2
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_ChildConnectAuto  0x02178524  thumb  ov014
 *   WIH_SetJudgeScanFunc  0x021795C0  thumb  ov014
 *   DWCi_MOV_WH_SetReceiver  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
extern u16 g_ChildConnectModes[2];
void *GFL_NET_GetInitParam(void);
int func_02178E4C(void);
int DWCi_MOV_WH_ChildConnectAuto(u32 a, const u16 *b, u32 c);
void WIH_SetJudgeScanFunc(unsigned v);
void DWCi_MOV_WH_SetReceiver(void *fn);
void func_0217727C(u32 *p, u32 v);
int func_0217771C(u8 *obj);
int func_021775AC(int a, int b, int c);

void NET_WHPIPE_TaskConnectChild(void)
{
    u8 *st = GFL_NET_GetInitParam();
    u16 tab[2];
    tab[0] = g_ChildConnectModes[0];
    tab[1] = g_ChildConnectModes[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        DWCi_MOV_WH_ChildConnectAuto(tab[st[0x64]], (const u16 *)(g_pWhPipeWork + 0xCDE), 0);
        WIH_SetJudgeScanFunc((unsigned int)func_0217771C);
        DWCi_MOV_WH_SetReceiver(func_021775AC);
        g_pWhPipeWork[0xCE8] = 1;
        func_0217727C((u32 *)g_pWhPipeWork, 0);
    }
}
