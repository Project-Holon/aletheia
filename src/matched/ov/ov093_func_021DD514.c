/*
 * function: HAND_ITEM_RecoverFixedHpOnEaten
 * address:  0x021DD514
 * packet:   pkt_ov093_021DD514
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
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13484.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int HAND_ITEM_GetParam(int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_RecoverFixedHpOnEaten(int a, u8 *b, int c)
{
    u8 *p;
    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13484 *)p)->f4 = HAND_ITEM_GetParam(a, 2);
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 908);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetFactorKey((void *)a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
