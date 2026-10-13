/*
 * function: BTL_SERVER_FLOW_StartTurn
 * address:  0x021BBC44
 * packet:   pkt_ov093_021BBC44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C84E8  0x021C84E8  thumb  ov093
 *   func_021BBCC4  0x021BBCC4  thumb  ov093
 *   BTL_EVENT_ClearSuspendedFlags  0x021D6EE8  thumb  ov093
 *   BTL_SERVER_ClearPokeChangeRequests  0x021BB920  thumb  ov093
 *   BTL_EVENT_ResetVarStackIfUsed  0x021D74E4  thumb  ov093
 *   BTL_SERVER_FLOW_ProcTurnStartEvents  0x021BBCD4  thumb  ov093
 *   BTL_SERVER_FLOW_BuildActionOrder  0x021BC610  thumb  ov093
 *   BTL_SERVER_FLOW_RunActionOrder  0x021BBFA8  thumb  ov093
 */
#include "../include/Obj02776.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021C84E8(u8 *p);
extern void func_021BBCC4(u8 *p);
extern void BTL_EVENT_ClearSuspendedFlags(void);
extern void BTL_SERVER_ClearPokeChangeRequests(u8 *p);
extern void BTL_EVENT_ResetVarStackIfUsed(void);
extern void BTL_SERVER_FLOW_ProcTurnStartEvents(u8 *p);
extern u8 BTL_SERVER_FLOW_BuildActionOrder(u8 *p, int a, u8 *q, int n);
extern u8 BTL_SERVER_FLOW_RunActionOrder(u8 *p, u8 k);

int BTL_SERVER_FLOW_StartTurn(u8 *p, int a)
{
    int *q;
    u32 i;

    ((struct Obj02776 *)p)->f14 = 0;
    q = *(int * *)&((struct Obj02776 *)p)->fC;
    q[0] = 0;
    q[1] = 0;
    if (p[0x77c] == 0) {
        func_021C84E8(p);
        func_021BBCC4(p + 0x3e0);
        for (i = 0; i < 4; i++)
            p[i + 0x1fe8] = 0;
        BTL_EVENT_ClearSuspendedFlags();
        BTL_SERVER_ClearPokeChangeRequests((u8 *)(((struct Obj02776 *)p)->f0));
        BTL_EVENT_ResetVarStackIfUsed();
        BTL_SERVER_FLOW_ProcTurnStartEvents(p);
        p[0x782] = BTL_SERVER_FLOW_BuildActionOrder(p, a, p + 0x7e0, 6);
        p[0x77c] = 1;
    }
    p[0x783] = BTL_SERVER_FLOW_RunActionOrder(p, p[0x783]);
    return ((struct Obj02776 *)p)->f14;
}
