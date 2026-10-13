/*
 * function: HAND_WAZA_TeleportShowFailMessage
 * address:  0x021E5C88
 * packet:   pkt_ov093_021E5C88
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_TeleportShowFailMessage(u8 *p, void *a, int b)
{
    u8 *r;
    if (BTL_EVENT_OverwriteVar(0x51, 1) != 0) {
        r = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x2ff);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), b);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
