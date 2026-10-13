/*
 * unit: yes
 * function: HAND_WAZA_StockpileOnMoveEffect, HAND_WAZA_AddSpitUp
 * address: 0x021E1668
 * packet: pkt_ov093_021E1668
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E1778 store-return stub included; zero local reused for n+1.
 * symbols:
 *   gSpitUpHandlers 0x021F2BD0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 */
#include "../include/Obj00889.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
void HAND_WAZA_StockpileOnMoveEffect(int unused, void *q, int id)
{
    void *m;
    u8 *r;
    u32 n;
    int zero;
    if (id == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(q, id);
        zero = 0;
        n = BTL_POKEPARAM_GetCounter(m, 0);
        if (n >= 3) return;
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 38, id);
        r[4] = id;
        r[5] = zero;
        zero = n + 1;
        r[6] = zero;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x2d1);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), zero);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 2;
        r[12] = 1;
        r[14] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 38, id);
        ((struct Obj00889 *)r)->f0 |= 0x1000000;
        r[4] = id;
        r[5] = 1;
        r[6] = BTL_POKEPARAM_GetCounter(m, 1) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 4;
        r[12] = 1;
        r[14] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = BTL_SERVER_FLOW_AllocCmdRecord(q, 38, id);
        ((struct Obj00889 *)r)->f0 |= 0x1000000;
        r[4] = id;
        r[5] = 2;
        r[6] = BTL_POKEPARAM_GetCounter(m, 2) + 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
}
extern u32 gSpitUpHandlers[];
u32 *HAND_WAZA_AddSpitUp(u32 *p)
{
    *p = 3;
    return gSpitUpHandlers;
}
