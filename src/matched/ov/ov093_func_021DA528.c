/*
 * function: HAND_TOKUSEI_AnticipationOnMemberIn
 * address:  0x021DA528
 * packet:   pkt_ov093_021DA528
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds   0x021C7D54  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   HAND_TOKUSEI_AnticipationFoeIsThreat   0x021DA5BC  thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord   0x021C88B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(u8 *p, u8 *k, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int HAND_TOKUSEI_AnticipationFoeIsThreat(void *a, void *b);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_AnticipationOnMemberIn(int a, int b, int c)
{
    u8 buf[4];
    u8 n;
    u8 i;
    void *q;
    u8 *p;

    if (c != BTL_EVENT_GetVar(2))
        return;
    n = BTL_SERVER_FLOW_CollectOpponentPokeIds((u8 *)b, (u8 *)c, buf);
    q = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
    for (i = 0; i < n; i++) {
        if (HAND_TOKUSEI_AnticipationFoeIsThreat(q, BTL_SERVER_FLOW_GetPokeParam((int *)b, buf[i])) != 0)
            break;
    }
    if (i == n)
        return;
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 2, c);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x1b4);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 3, c);
}
