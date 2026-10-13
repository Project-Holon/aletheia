/*
 * function: HAND_WAZA_PowerTrickOnUncategorizedMove
 * address:  0x021E4FF4
 * packet:   pkt_ov093_021E4FF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13523.h"
#include "../include/Obj13524.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct Rec {
    u8 pad[0xe];
    u8 id;
    u8 f0 : 1;
    u8 f1 : 1;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int func_021D58A8(u8 *p, int k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_PowerTrickOnUncategorizedMove(int a, void *b, int c)
{
    void *q;
    u8 *w;
    Rec *r;

    if (c == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(b, c);
        r = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x11, c);
        r->id = c;
        ((struct Obj13523 *)r)->f4 = func_021D58A8(q, 9);
        ((struct Obj13523 *)r)->f6 = func_021D58A8(q, 8);
        r->f0 = 1;
        r->f1 = 1;
        BTL_SERVER_FLOW_InitMsgRecord((u8 *)r + 0x10, 2, 0x305);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)r + 0x10), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        w = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x17, c);
        w[8] = c;
        ((struct Obj13524 *)w)->f4 = 0xa;
        BTL_SERVER_FLOW_CommitCmdRecord(b, w);
    }
}
