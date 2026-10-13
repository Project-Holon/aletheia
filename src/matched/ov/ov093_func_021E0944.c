/*
 * function: HAND_WAZA_JumpKickDealCrashDamage
 * address:  0x021E0944
 * packet:   pkt_ov093_021E0944
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13505.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_WAZA_JumpKickDealCrashDamage(int unused, void *q, int id, int unused2)
{
    u8 *r;
    int n;

    n = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(q, id), 2);
    r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 7, id);
    r[6] = id;
    ((struct Obj13505 *)r)->f4 = n;
    BTL_SERVER_FLOW_InitMsgRecord(r + 0xc, 2, 0x386);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0xc), id);
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
