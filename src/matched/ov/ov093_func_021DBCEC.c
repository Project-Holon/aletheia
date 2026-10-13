/*
 * function: HAND_TOKUSEI_Pickpocket_StealOnContact
 * address:  0x021DBCEC
 * packet:   pkt_ov093_021DBCEC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_COMMON_IsMoveTarget  0x021E85F8  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTLV_CORE_CheckEitherSlotPair  0x021E86E8  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13481.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int HAND_COMMON_IsMoveTarget(int id);
extern int BTL_EVENT_GetVar(int key);
extern int BTLV_CORE_CheckEitherSlotPair(void *a, int b, int c);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
struct QI;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_Pickpocket_StealOnContact(int u, void *a, int b)
{
    u8 t;
    void *x;
    void *y;
    u8 *e;
    if (HAND_COMMON_IsMoveTarget(b) != 0) {
        t = BTL_EVENT_GetVar(3);
        if (BTLV_CORE_CheckEitherSlotPair(a, b, t) == 0
            && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) != 0) {
            x = BTL_SERVER_FLOW_GetPokeParam(a, b);
            y = BTL_SERVER_FLOW_GetPokeParam(a, t);
            if (BTL_POKEPARAM_GetItem(x) == 0 && BTL_POKEPARAM_GetItem(y) != 0) {
                e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x24, b);
                ((struct Obj13481 *)e)->f0 |= 2 << 22;
                e[4] = t;
                BTL_SERVER_FLOW_InitMsgRecord(e + 8, 2, 0x1cc);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), t);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), BTL_POKEPARAM_GetItem(y));
                BTL_SERVER_FLOW_CommitCmdRecord(a, e);
            }
        }
    }
}
