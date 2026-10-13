/*
 * function: HAND_ITEM_GemMoveUsed
 * address:  0x021E01D4
 * packet:   pkt_ov093_021E01D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   func_021E0274  0x021E0274  thumb  ov093
 *   BTL_EVENT_IsFactorDead  0x021D7098  thumb  ov093
 *   BTL_SERVER_FLOW_IsActionCounterSet  0x021C7EC4  thumb  ov093
 *   BTL_EVENT_MarkFactorDead  0x021D7090  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int key);
extern int WAZA_TOOL_IsDamaging(u16 id);
extern int func_021E0274(u16 id);
typedef unsigned int   u32;
struct QQ;
extern int BTL_EVENT_IsFactorDead(u8 *p);
extern u32 BTL_SERVER_FLOW_IsActionCounterSet(u8 *p);
extern void BTL_EVENT_MarkFactorDead(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_GemMoveUsed(void *a, void *b, int c, int *d, u8 e)
{
    u16 t;
    char *p;

    if (c == BTL_EVENT_GetVar(3) && e == BTL_EVENT_GetVar(0x16)) {
        t = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_IsDamaging(t) != 0 && func_021E0274(t) == 0 && BTL_EVENT_IsFactorDead(a) == 0
            && BTL_SERVER_FLOW_IsActionCounterSet(b) == 0) {
            BTL_EVENT_MarkFactorDead(a);
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x23, c);
            BTL_SERVER_FLOW_InitMsgRecord(p + 8, 1, 0xb6);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetFactorKey(a));
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetVar(0x12));
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            *d = 1;
        }
    }
}
