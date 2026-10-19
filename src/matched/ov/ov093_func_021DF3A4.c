/*
 * function: HAND_ITEM_SmokeBallShowEscapeMessage
 * address:  0x021DF3A4
 * packet:   pkt_ov093_021DF3A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_COMMON_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_SetMsgRecordSe  0x021C888C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int HAND_COMMON_EventTrySetFlagIfAttacker(int a, int b, int c);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
struct QQ;
extern void BTL_SERVER_FLOW_SetMsgRecordSe(u8 *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_ITEM_SmokeBallShowEscapeMessage(int a, void *b, int c)
{
    u8 *r;

    if (HAND_COMMON_EventTrySetFlagIfAttacker(a, (int)b, c) != 0) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x3ec);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), BTL_EVENT_GetFactorKey((void *)a));
        BTL_SERVER_FLOW_SetMsgRecordSe(r + 4, 0x56a);
        BTL_SERVER_FLOW_CommitCmdRecord(b, r);
    }
}
