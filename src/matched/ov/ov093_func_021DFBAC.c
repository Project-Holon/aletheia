/*
 * function: HAND_ITEM_AirBalloonPop
 * address:  0x021DFBAC
 * packet:   pkt_ov093_021DFBAC
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
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj13501.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_ITEM_AirBalloonPop(void *self, void *q, int id)
{
    u8 *r;

    if (id != BTL_EVENT_GetVar(4))
        return;
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0x20, id);
    r[6] = id;
    ((struct Obj13501 *)r)->f4 = 0;
    BTL_SERVER_FLOW_InitMsgRecord(r + 0xc, 2, 0x19b);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0xc), id);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
