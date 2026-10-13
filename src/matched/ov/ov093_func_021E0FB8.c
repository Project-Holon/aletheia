/*
 * function: HAND_WAZA_WorrySeedChangeAbility
 * address:  0x021E0FB8
 * packet:   pkt_ov093_021E0FB8
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
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07826.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_WAZA_WorrySeedChangeAbility(int unused, void *q, int id)
{
    u8 *r;
    int t;

    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(6);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0x1f, id);
        r[6] = t;
        ((struct Obj07826 *)r)->f4 = 0xf;
        BTL_SERVER_FLOW_InitMsgRecord(r + 0xc, 2, 0x195);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0xc), r[6]);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0xc), ((struct Obj07826 *)r)->f4);
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
}
