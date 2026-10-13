/*
 * function: HAND_WAZA_BideSelectMessage
 * address:  0x021E3D38
 * packet:   pkt_ov093_021E3D38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_BideSelectMessage(int u, int v, int c, int *w)
{
    int p;

    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_EVENT_GetVar(0x3f);
        switch (w[0]) {
        case 1:
            BTL_SERVER_FLOW_InitMsgRecord((void *)p, 2, 0x2e9);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        case 2:
            BTL_SERVER_FLOW_InitMsgRecord((void *)p, 2, 0x2ec);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        }
    }
}
