/*
 * function: HAND_ITEM_CustapBerryShowMessage
 * address:  0x021DDF38
 * packet:   pkt_ov093_021DDF38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
struct QQ;
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_CustapBerryShowMessage(void *a, void *b, int c, int *d)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(m + 4, 2, 0x401);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), BTL_EVENT_GetFactorKey(a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        *d = 0;
    }
}
