/*
 * function: HAND_ITEM_WhiteHerbRestoreStats
 * address:  0x021DE2A0
 * packet:   pkt_ov093_021DE2A0
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
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
struct QQ;
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_ITEM_WhiteHerbRestoreStats(void *a, void *b, int c, u8 *a3)
{
    u8 *m;
    u8 *n;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x12, c);
        m[4] = c;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        n = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(n + 4, 2, 0x3f2);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(n + 4), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(n + 4), BTL_EVENT_GetFactorKey(a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, n);
    }
}
