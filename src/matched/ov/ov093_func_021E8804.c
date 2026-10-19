/*
 * function: HAND_COMMON_EventQueueMoveNotice
 * address:  0x021E8804
 * packet:   pkt_ov093_021E8804
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_COMMON_EventQueueMoveNotice(int u, void *a, int b, int d)
{
    u8 *p;
    int z;

    z = 2;
    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(a, b)) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, z, 0x2fc);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), b);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), BTL_EVENT_GetVar(0x12));
            BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        }
    }
}
