/*
 * function: HAND_WAZA_LockOnOnUncategorizedMove
 * address:  0x021E5264
 * packet:   pkt_ov093_021E5264
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
 *   BTL_SICKCONT_MakeKind4  0x021E8A28  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10093.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_SICKCONT_MakeKind4(u32 a, u32 b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_LockOnOnUncategorizedMove(int a, void *b, int c)
{
    u8 *w;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        w = BTL_SERVER_FLOW_AllocCmdRecord(b, 12, c);
        w[0xf] = c;
        ((struct Obj10093 *)w)->f4 = 0x1d;
        ((struct Obj10093 *)w)->f8 = BTL_SICKCONT_MakeKind4(k, 2);
        BTL_SERVER_FLOW_InitMsgRecord(w + 0x14, 2, 0x28b);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 0x14), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 0x14), k);
        BTL_SERVER_FLOW_CommitCmdRecord(b, w);
    }
}
