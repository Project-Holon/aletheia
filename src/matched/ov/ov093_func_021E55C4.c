/*
 * unit:     yes
 * function: HAND_WAZA_TransformOnUncategorizedMove, HAND_WAZA_AddLunarDance
 * address:  0x021E55C4
 * packet:   pkt_ov093_021E55C4
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
 *   gLunarDanceHandlers     0x021F252C  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gLunarDanceHandlers[];

void HAND_WAZA_TransformOnUncategorizedMove(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x33, c);
        m[4] = BTL_EVENT_GetVar(6);
        BTL_SERVER_FLOW_InitMsgRecord(m + 8, 2, 0x284);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), m[4]);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_AddLunarDance(int *p)
{
    *p = 1;
    return gLunarDanceHandlers;
}
