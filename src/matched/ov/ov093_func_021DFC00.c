/*
 * function: HAND_ITEM_RedCardForceSwitch
 * address:  0x021DFC00
 * packet:   pkt_ov093_021DFC00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj07822.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern int func_021E85F8(int id);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_ITEM_RedCardForceSwitch(int self, void *q, int id)
{
    u8 t;
    u8 *r;

    if (func_021E85F8(id) == 0)
        return;
    t = BTL_EVENT_GetVar(3);
    if (BTL_SERVER_FLOW_GetFrontPosOfPoke(q, t) == 6)
        return;
    if (BTL_EVENT_GetVar(0x4d) != 0)
        return;
    if (BTL_SERVER_FLOW_CheckClientHasBackupPoke(q, t) == 0)
        return;
    if (BTL_SERVER_FLOW_CheckShowdownThunk(q) != 0)
        return;
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0x23, id);
    BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 0x1a1);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), id);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), t);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0x2e, id);
    r[6] = BTL_EVENT_GetVar(3);
    r[7] = (r[7] & ~0xf0) | 0x10;
    ((struct Obj07822 *)r)->f4 = 0x28c;
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
