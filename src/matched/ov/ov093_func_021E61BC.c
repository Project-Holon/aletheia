/*
 * function: HAND_WAZA_FlyBeginFlight
 * address:  0x021E61BC
 * packet:   pkt_ov093_021E61BC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13530.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_FlyBeginFlight(u8 *p, void *a, int b)
{
    u8 *q;
    u8 *r;
    if (b != BTL_EVENT_GetVar(3))
        return;
    q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x17, b);
    q[8] = b;
    ((struct Obj13530 *)q)->f4 = 3;
    BTL_SERVER_FLOW_CommitCmdRecord(a, q);
    r = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
    BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x211);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), b);
    BTL_SERVER_FLOW_CommitCmdRecord(a, r);
}
