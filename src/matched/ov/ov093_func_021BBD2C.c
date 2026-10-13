/*
 * function: BTL_SERVER_FLOW_StartAfterPokeSelect
 * address:  0x021BBD2C
 * packet:   pkt_ov093_021BBD2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_ClearPokeChangeRequests  0x021BB920  thumb  ov093
 *   BTL_EVENT_ResetVarStackIfUsed  0x021D74E4  thumb  ov093
 *   BTL_SERVER_FLOW_ProcPokeChangeActions  0x021BC220  thumb  ov093
 *   BTL_SERVER_FLOW_RunActionOrder  0x021BBFA8  thumb  ov093
 */
#include "../include/Obj02777.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void BTL_SERVER_ClearPokeChangeRequests(u8 *p);
extern void BTL_EVENT_ResetVarStackIfUsed(void);
extern int BTL_SERVER_FLOW_ProcPokeChangeActions(u8 *p, u8 *o);
extern u8 BTL_SERVER_FLOW_RunActionOrder(u8 *p, u8 k);

int BTL_SERVER_FLOW_StartAfterPokeSelect(u8 *p, int a)
{
    int *q;

    ((struct Obj02777 *)p)->f14 = 0;
    q = *(int * *)&((struct Obj02777 *)p)->fC;
    q[0] = 0;
    q[1] = 0;
    if (p[0x77c] == 0) {
        BTL_SERVER_ClearPokeChangeRequests((u8 *)(((struct Obj02777 *)p)->f0));
        BTL_EVENT_ResetVarStackIfUsed();
        p[0x77d] = 0;
        p[0x77c] = 1;
        if (BTL_SERVER_FLOW_ProcPokeChangeActions(p, (u8 *)a) != 0) {
            ((struct Obj02777 *)p)->f14 = 3;
            return 3;
        }
    }
    p[0x783] = BTL_SERVER_FLOW_RunActionOrder(p, p[0x783]);
    return ((struct Obj02777 *)p)->f14;
}
