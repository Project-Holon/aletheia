/*
 * function: HAND_ITEM_ShowResistBerryMessage
 * address:  0x021DDD38
 * packet:   pkt_ov093_021DDD38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_COMMON_IsMoveTarget  0x021E85F8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int HAND_COMMON_IsMoveTarget(int id);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_ShowResistBerryMessage(void *a, u8 *b, int c, int *d)
{
    u8 *p;
    if (*d != 0 && HAND_COMMON_IsMoveTarget(c) != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x23, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 219);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetFactorKey(a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
