/*
 * function: HAND_WAZA_UproarOnTurnEnd
 * address:  0x021E24D4
 * packet:   pkt_ov093_021E24D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke  0x021E03D8  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
typedef unsigned short u16;
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
typedef unsigned char u8;
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);

void HAND_WAZA_UproarOnTurnEnd(void *a, void *b, int c, int *d)
{
    void *v;
    char *p;

    if (c == BTL_EVENT_GetVar(2) && d[6] != 0) {
        v = BTL_SERVER_FLOW_GetPokeParam(b, c);
        if (BTL_POKEPARAM_IsFainted(v) == 0) {
            if (BTL_POKEPARAM_HasSick(v, 0x19) == 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
                BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x2CE);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
                BTL_SERVER_FLOW_CommitCmdRecord(b, p);
                HAND_WAZA_RemoveMoveHandlerOfPoke(v, BTL_EVENT_GetFactorKey(a));
            } else {
                p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
                BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x2CB);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
                BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            }
        }
    }
}
