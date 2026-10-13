/*
 * function: HAND_WAZA_FocusPunchTense
 * address:  0x021E69E8
 * packet:   pkt_ov093_021E69E8
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
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj07834.h"
#include "../include/Obj13538.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_WAZA_FocusPunchTense(int x, void *a, int c)
{
    u8 *p;
    u8 *q;

    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x15, c);
        p[8] = c;
        ((struct Obj13538 *)p)->f4 = 5;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(a, c)) == 0) {
            q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x37, c);
            ((struct Obj07834 *)q)->f4 = 0x272;
            q[6] = BTL_SERVER_FLOW_GetPokeViewPos(a, c);
            q[7] = 6;
            q[0xb] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(a, q);
        }
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x268);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
