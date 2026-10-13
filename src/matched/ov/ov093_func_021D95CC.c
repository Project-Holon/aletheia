/*
 * unit:     yes
 * function: HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage, HAND_TOKUSEI_GetInfatuationGuardHandlers
 * address:  0x021D95CC
 * packet:   pkt_ov093_021D95CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gInfatuationGuardHandlers     0x021F0CC4  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gInfatuationGuardHandlers[];

void HAND_TOKUSEI_InfatuationGuard_ShowBlockedMoveMessage(int a, void *b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(4) && (u16)BTL_EVENT_GetVar(0x12) == 0x1bd) {
        if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
        }
    }
}

int *HAND_TOKUSEI_GetInfatuationGuardHandlers(int *p)
{
    *p = 5;
    return gInfatuationGuardHandlers;
}
