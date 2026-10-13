/*
 * function: HAND_TOKUSEI_ShowIndirectGuardMessage
 * address:  0x021D92CC
 * packet:   pkt_ov093_021D92CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_ShowIndirectGuardMessage(void *a, int b, int *c, int d)
{
    int t;
    u8 *p;

    if (b == BTL_EVENT_GetVar(2) && c[0] != 0) {
        t = BTL_EVENT_GetVar(0x19);
        if (t == 0 || c[1] != t) {
            BTL_SERVER_FLOW_PushCmdRecord(a, 2, b);
            p = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, d);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), b);
            BTL_SERVER_FLOW_CommitCmdRecord(a, p);
            BTL_SERVER_FLOW_PushCmdRecord(a, 3, b);
            c[1] = t;
        }
        c[0] = 0;
    }
}
