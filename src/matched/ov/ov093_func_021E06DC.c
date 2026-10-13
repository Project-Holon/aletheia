/*
 * function: HAND_WAZA_MudSportAddFieldEffect
 * address:  0x021E06DC
 * packet:   pkt_ov093_021E06DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef struct { unsigned v; } Word;
extern Word BTLV_CORE_MakeSlotKind3(int a);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_MudSportAddFieldEffect(int a, void *b, int c)
{
    int *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1b, c);
        p[1] = 5;
        *(Word *)(p + 2) = BTLV_CORE_MakeSlotKind3(c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 1, 0x73);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
