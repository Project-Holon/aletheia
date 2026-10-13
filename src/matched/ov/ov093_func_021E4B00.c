/*
 * function: HAND_WAZA_SpiteOnUncategorizedMove
 * address:  0x021E4B00
 * packet:   pkt_ov093_021E4B00
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
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_FindMoveSlot  0x021D5778  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *q);
extern int BTL_POKEPARAM_FindMoveSlot(u8 *q, int w);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_SpiteOnUncategorizedMove(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    int w;
    int t;
    u8 n;
    u8 *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        q = BTL_SERVER_FLOW_GetPokeParam((int *)s, v);
        w = BTL_POKEPARAM_GetLastSelectedMoveId(q);
        t = BTL_POKEPARAM_FindMoveSlot(q, w);
        if (t != 4) {
            n = (int)BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)q, (int)t);
            if (n > 4)
                n = 4;
            if (n != 0) {
                e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 10, k);
                e[5] = v;
                e[4] = n;
                e[6] = t;
                BTL_SERVER_FLOW_InitMsgRecord(e + 8, 2, 641);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), v);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), w);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), n);
                BTL_SERVER_FLOW_CommitCmdRecord(s, e);
            }
        }
    }
}
