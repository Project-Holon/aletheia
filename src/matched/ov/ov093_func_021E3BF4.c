/*
 * function: HAND_WAZA_ProtectActivate
 * address:  0x021E3BF4
 * packet:   pkt_ov093_021E3BF4
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
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   HAND_WAZA_ProtectIncrementStreak  0x021E3C5C  thumb  ov093
 */
#include "../include/Obj13514.h"

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);
extern void HAND_WAZA_ProtectIncrementStreak(void *a, int c, int d);

void HAND_WAZA_ProtectActivate(int u, void *a, int c)
{
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        BTL_SERVER_FLOW_GetPokeParam(a, c);
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x15, c);
        p[8] = c;
        ((struct Obj13514 *)p)->f4 = 7;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        HAND_WAZA_ProtectIncrementStreak(a, c, 0);
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x205);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
