/*
 * function: HAND_WAZA_SplashShowMessage
 * address:  0x021E0DC4
 * packet:   pkt_ov093_021E0DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_SplashShowMessage(int a, void *q, int id)
{
    unsigned char *r;

    if (id != BTL_EVENT_GetVar(3))
        return;
    r = (unsigned char *)BTL_SERVER_FLOW_AllocCmdRecord(q, 4, id);
    BTL_SERVER_FLOW_InitMsgRecord(r + 4, 1, 102);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
