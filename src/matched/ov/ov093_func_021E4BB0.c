/*
 * function: HAND_WAZA_PsychUpOnUncategorizedMove
 * address:  0x021E4BB0
 * packet:   pkt_ov093_021E4BB0
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
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_PsychUpOnUncategorizedMove(int a, void *b, int c)
{
    void *q;
    u8 *w;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        q = BTL_SERVER_FLOW_GetPokeParam(b, k);
        w = BTL_SERVER_FLOW_AllocCmdRecord(b, 0xf, c);
        w[4] = c;
        w[5] = func_021D59B4(q, 1);
        w[6] = func_021D59B4(q, 2);
        w[7] = func_021D59B4(q, 3);
        w[8] = func_021D59B4(q, 4);
        w[9] = func_021D59B4(q, 5);
        w[10] = func_021D59B4(q, 6);
        w[11] = func_021D59B4(q, 7);
        BTL_SERVER_FLOW_CommitCmdRecord(b, w);
        w = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(w + 4, 2, 0x417);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 4), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 4), k);
        BTL_SERVER_FLOW_CommitCmdRecord(b, w);
    }
}
