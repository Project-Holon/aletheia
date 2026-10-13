/*
 * function: HAND_ITEM_LifeOrb_RecoilDamage
 * address:  0x021DEBEC
 * packet:   pkt_ov093_021DEBEC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 */
#include "../include/Obj13494.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);

void HAND_ITEM_LifeOrb_RecoilDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam(b, c);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
        r[6] = c;
        ((struct Obj13494 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 10);
        BTL_SERVER_FLOW_InitMsgRecord(r + 12, 2, 0x3f5);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, r);
    }
}
