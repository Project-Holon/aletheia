/*
 * function: HAND_WAZA_FlingShowMessage
 * address:  0x021E5D54
 * packet:   pkt_ov093_021E5D54
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_FlingShowMessage(u8 *p, void *a, int b)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != BTL_EVENT_GetVar(3))
        return;
    r = BTL_SERVER_FLOW_GetPokeParam(a, b);
    v = (u32)BTL_POKEPARAM_GetItem(r);
    if (v == 0)
        return;
    q = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
    BTL_SERVER_FLOW_InitMsgRecord(q + 4, 2, 0x30b);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 4), b);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 4), v);
    BTL_SERVER_FLOW_CommitCmdRecord(a, q);
}
