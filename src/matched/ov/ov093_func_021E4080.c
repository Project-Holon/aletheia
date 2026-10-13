/*
 * unit: yes
 * function: HAND_WAZA_PainSplitAverageHp, HAND_WAZA_GetBellyDrumHandlers
 * address: 0x021E4080
 * packet: pkt_ov093_021E4080
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E4148 store-and-return stub included after two padding bytes.
 * symbols:
 *   gBellyDrumHandlers 0x021F27B4 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
#include "../include/Obj02790.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_WAZA_PainSplitAverageHp(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u32 x;
    u32 y;
    u32 avg;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    k = BTL_EVENT_GetVar(6);
    m = BTL_SERVER_FLOW_GetPokeParam(b, c);
    n = BTL_SERVER_FLOW_GetPokeParam(b, k);
    x = func_021D59B4(m, 13);
    y = func_021D59B4(n, 13);
    avg = (x + y) / 2;
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 8, c);
    p[4] = 2;
    p[7] = c;
    ((struct Obj02790 *)p)->f10 = avg - x;
    p[8] = k;
    ((struct Obj02790 *)p)->f14 = avg - y;
    p[6] = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 1, 113);
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 33, c);
    p[4] = c;
    ((struct Obj02790 *)p)->f8 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 33, c);
    p[4] = k;
    ((struct Obj02790 *)p)->f8 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
}
extern u32 gBellyDrumHandlers[];
u32 *HAND_WAZA_GetBellyDrumHandlers(u32 *p)
{
    *p = 1;
    return gBellyDrumHandlers;
}
