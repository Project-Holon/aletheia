/*
 * unit:     yes
 * function: HAND_WAZA_ShadowForceBreakProtect, HAND_WAZA_GetBounceHandlers
 * address:  0x021E6278
 * packet:   pkt_ov093_021E6278
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
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gBounceHandlers     0x021F2AA8  data   ov093  a4
 */
#include "../include/Obj13532.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern int gBounceHandlers[];

void HAND_WAZA_ShadowForceBreakProtect(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(a, k), 7) != 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x16, b);
            e[8] = k;
            ((struct Obj13532 *)e)->f4 = 7;
            BTL_SERVER_FLOW_CommitCmdRecord(a, e);
            e = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(e + 4, 2, 0x208);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 4), k);
            BTL_SERVER_FLOW_CommitCmdRecord(a, e);
        }
    }
}

int *HAND_WAZA_GetBounceHandlers(int *p)
{
    *p = 2;
    return gBounceHandlers;
}
