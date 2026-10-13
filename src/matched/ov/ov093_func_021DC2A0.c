/*
 * function: HAND_TOKUSEI_Telepathy_AvoidAllyAttack
 * address:  0x021DC2A0
 * packet:   pkt_ov093_021DC2A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21343.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern u32 WAZA_TOOL_IsDamaging(u16 id);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_Telepathy_AvoidAllyAttack(int u, void *a, u32 b)
{
    u8 *e;
    u8 c;
    if (b == BTL_EVENT_GetVar(4)) {
        c = BTL_EVENT_GetVar(3);
        if (BTL_MAIN_IsPokeSamePair(b, c) != 0
            && b != c
            && WAZA_TOOL_IsDamaging(BTL_EVENT_GetVar(0x12)) != 0
            && BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
            e = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, b);
            ((struct Obj21343 *)e)->f0 |= 1 << 23;
            BTL_SERVER_FLOW_InitMsgRecord(e + 4, 2, 0x1d5);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 4), b);
            BTL_SERVER_FLOW_CommitCmdRecord(a, e);
        }
    }
}
