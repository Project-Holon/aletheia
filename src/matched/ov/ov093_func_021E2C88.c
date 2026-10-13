/*
 * function: HAND_WAZA_PresentOnHealEffect
 * address:  0x021E2C88
 * packet:   pkt_ov093_021E2C88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13512.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_PresentOnHealEffect(int u, void *p, int k, int *out)
{
    u8 b;
    u8 *m;
    void *q;
    if (k == BTL_EVENT_GetVar(3) && *out != 0) {
        b = BTL_EVENT_GetVar(4);
        q = BTL_SERVER_FLOW_GetPokeParam(p, b);
        if (BTL_POKEPARAM_IsHpFull(q) == 0) {
            m = BTL_SERVER_FLOW_AllocCmdRecord(p, 5, k);
            m[6] = b;
            ((struct Obj13512 *)m)->f4 = BTL_CALC_DivideMaxHpMin1(q, 4);
            BTL_SERVER_FLOW_InitMsgRecord(m + 8, 2, 0x183);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), b);
            BTL_SERVER_FLOW_CommitCmdRecord(p, m);
        } else {
            m = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, k);
            BTL_SERVER_FLOW_InitMsgRecord(m + 4, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), b);
            BTL_SERVER_FLOW_CommitCmdRecord(p, m);
        }
    }
}
