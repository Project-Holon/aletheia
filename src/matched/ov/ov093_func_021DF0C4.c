/*
 * function: HAND_ITEM_DestinyKnot_Infatuate
 * address:  0x021DF0C4
 * packet:   pkt_ov093_021DF0C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * 2026-10-03 (wave B3 lane 10): EXACT*. BTLV_CORE_MakeSlotKind3 returns a one-word struct (Word), as in the other matched callers; its return temporary is the second frame word (see docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 * symbols:
 *   HAND_ITEM_DestinyKnot_Infatuate  0x021DF0C4  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10069.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef struct Word { u32 v; } Word;
extern Word BTLV_CORE_MakeSlotKind3(int a);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_DestinyKnot_Infatuate(void *a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x1d) != 7)
        return;
    k = (u8)BTL_EVENT_GetVar(3);
    if (k == 0x1f)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xc, c);
    ((struct Obj10069 *)p)->fF = k;
    ((struct Obj10069 *)p)->f4 = 7;
    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind3(c);
    ((struct Obj10069 *)p)->fD = 1;
    BTL_SERVER_FLOW_InitMsgRecord(p + 0x14, 2, 0x14a);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0x14), k);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0x14), BTL_EVENT_GetFactorKey(a));
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
