/*
 * function: HAND_WAZA_UproarPreventSleep
 * address:  0x021E2574
 * packet:   pkt_ov093_021E2574
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, unsigned v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_UproarPreventSleep(int a, void *b, int c, int *d)
{
    char *p;
    u8 u;

    if (d[6] != 0 && BTL_EVENT_GetVar(0x1D) == 2 && BTL_EVENT_OverwriteVar(0x41, 1) != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        u = BTL_EVENT_GetVar(4);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, (u16)(u == c ? 0x2C8 : 0x2C5));
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), u);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
