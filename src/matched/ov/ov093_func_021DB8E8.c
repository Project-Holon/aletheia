/*
 * function: HAND_TOKUSEI_Pressure_ShowAbilityMessage
 * address:  0x021DB8E8
 * packet:   pkt_ov093_021DB8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_Pressure_ShowAbilityMessage(void *a, void *p, int id)
{
    u8 *r;

    if (id == BTL_EVENT_GetVar(2)) {
        BTL_SERVER_FLOW_PushCmdRecord(p, 2, id);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(p, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x1e7);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
        BTL_SERVER_FLOW_CommitCmdRecord(p, r);
        BTL_SERVER_FLOW_PushCmdRecord(p, 3, id);
    }
}
