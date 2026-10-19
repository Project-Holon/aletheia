/*
 * function: HAND_WAZA_MagnetRiseAddFloating
 * address:  0x021E5EB8
 * packet:   pkt_ov093_021E5EB8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13529.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef struct Word { u32 v; } Word;
extern Word BTL_SICKCONT_MakeKind2Index(u8 v);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_MagnetRiseAddFloating(u8 *p, void *a, int b)
{
    u8 *q;
    if (b != BTL_EVENT_GetVar(3))
        return;
    q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xc, b);
    q[0xf] = b;
    ((struct Obj13529 *)q)->f4 = 0x1e;
    *(Word *)(q + 8) = BTL_SICKCONT_MakeKind2Index(5);
    BTL_SERVER_FLOW_InitMsgRecord(q + 0x14, 2, 0x292);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(q + 0x14), b);
    BTL_SERVER_FLOW_CommitCmdRecord(a, q);
}
