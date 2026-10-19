/*
 * function: HAND_ITEM_AirBalloonEnterField
 * address:  0x021DFB4C
 * packet:   pkt_ov093_021DFB4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_IsStaticSlotInUse  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_IsStaticSlotInUse(int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_ITEM_AirBalloonEnterField(void *self, void *q, int id)
{
    u8 *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    if (BTL_FIELD_IsStaticSlotInUse(2) != 0)
        return;
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
    BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x198);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
