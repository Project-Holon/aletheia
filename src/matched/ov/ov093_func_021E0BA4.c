/*
 * function: HAND_WAZA_FollowMeShowMessage
 * address:  0x021E0BA4
 * packet:   pkt_ov093_021E0BA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);

void HAND_WAZA_FollowMeShowMessage(int unused, void *q, int id, int *f)
{
    u8 *m;

    if (id == BTL_EVENT_GetVar(3)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(m + 4, 2, 0x29e);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), id);
        BTL_SERVER_FLOW_CommitCmdRecord(q, m);
        f[6] = 1;
    }
}
