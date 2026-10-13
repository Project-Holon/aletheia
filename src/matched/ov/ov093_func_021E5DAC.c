/*
 * function: HAND_WAZA_FlingUseItemOnTarget
 * address:  0x021E5DAC
 * packet:   pkt_ov093_021E5DAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 */
#include "../include/Obj10097.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);

void HAND_WAZA_FlingUseItemOnTarget(u8 *p, void *a, int b, int *c)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != BTL_EVENT_GetVar(3))
        return;
    r = BTL_SERVER_FLOW_GetPokeParam(a, b);
    v = (u32)BTL_POKEPARAM_GetItem(r);
    if (v == 0)
        return;
    q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x23, b);
    ((struct Obj10097 *)q)->f4 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(a, q);
    *c = 1;
    if (BTL_EVENT_GetVar(0x46) == 0 && BTL_EVENT_GetVar(0x47) == 0 && BTL_CALC_GetMonParamWithHeap((void *)v, 9) != 0) {
        q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x22, b);
        q[4] = BTL_EVENT_GetVar(4);
        *(u16 *)(q + 6) = v;
        BTL_SERVER_FLOW_CommitCmdRecord(a, q);
    }
}
