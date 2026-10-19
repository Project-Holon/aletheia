/*
 * function: HAND_WAZA_TrickRoomAddFieldEffect
 * address:  0x021E05B0
 * packet:   pkt_ov093_021E05B0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_IsStaticSlotInUse  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_IsStaticSlotInUse(int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef unsigned int   u32;
extern int BTL_SICKCONT_MakeKind2Index(u32 a);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_TrickRoomAddFieldEffect(int a, void *b, int c)
{
    int *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_FIELD_IsStaticSlotInUse(1) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1b, c);
            p[1] = 1;
            p[2] = BTL_SICKCONT_MakeKind2Index(5);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x359);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        } else {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1c, c);
            p[1] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}
