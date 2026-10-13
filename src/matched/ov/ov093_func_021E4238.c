/*
 * function: HAND_WAZA_FeintBreakProtect
 * address:  0x021E4238
 * packet:   pkt_ov093_021E4238
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
 */
#include "../include/Obj13518.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);

void HAND_WAZA_FeintBreakProtect(int a0, u8 *s, int k, int *pf)
{
    u8 v;
    u8 *e;
    u8 *e2;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(4);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam((int *)s, v), 7) != 0 || *pf != 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 0x16, k);
            e[8] = v;
            ((struct Obj13518 *)e)->f4 = 7;
            BTL_SERVER_FLOW_CommitCmdRecord(s, e);
            e2 = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 4, k);
            BTL_SERVER_FLOW_InitMsgRecord(e2 + 4, 2, 526);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e2 + 4), v);
            BTL_SERVER_FLOW_CommitCmdRecord(s, e2);
        }
    }
}
