/*
 * unit:     yes
 * function: HAND_WAZA_PluckEatTargetBerry, HAND_WAZA_AddStruggle
 * address:  0x021E65B0
 * packet:   pkt_ov093_021E65B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   ITEM_IsBerry  0x020213C0  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gStruggleHandlers     0x021F2B28  data   ov093  a4
 */
#include "../include/Obj06277.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int ITEM_IsBerry(u32 a);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern int gStruggleHandlers[];

void HAND_WAZA_PluckEatTargetBerry(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;
    u16 t;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        t = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(a, k));
        if (ITEM_IsBerry(t) != 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x20, b);
            e[6] = k;
            ((struct Obj06277 *)e)->f4 = 0;
            BTL_SERVER_FLOW_InitMsgRecord(e + 0xc, 2, 0x308);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 0xc), b);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 0xc), t);
            BTL_SERVER_FLOW_CommitCmdRecord(a, e);
            e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x22, b);
            ((struct Obj06277 *)e)->f0 |= 2 << 23;
            ((struct Obj06277 *)e)->f6 = t;
            e[4] = b;
            BTL_SERVER_FLOW_CommitCmdRecord(a, e);
        }
    }
}

int *HAND_WAZA_AddStruggle(int *p)
{
    *p = 3;
    return gStruggleHandlers;
}
