/*
 * unit:     yes
 * function: HAND_WAZA_RecycleRestoreItem, HAND_WAZA_GetPsychoShiftHandlers
 * address:  0x021E3F44
 * packet:   pkt_ov093_021E3F44
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
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gPsychoShiftHandlers     0x021F27C4  data   a4
 */
#include "../include/Obj10088.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
struct QI;
struct QK;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);
extern int gPsychoShiftHandlers[];

void HAND_WAZA_RecycleRestoreItem(int u, void *a, int c)
{
    void *q;
    int h;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(a, c);
        if (BTL_POKEPARAM_GetItem(q) == 0) {
            h = BTL_POKEPARAM_GetConsumedItem(q);
            if (h != 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x20, c);
                ((struct Obj10088 *)p)->f4 = h;
                p[6] = c;
                p[7] = 1;
                BTL_SERVER_FLOW_InitMsgRecord(p + 0xc, 2, 0x2dd);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), c);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), h);
                BTL_SERVER_FLOW_CommitCmdRecord(a, p);
            }
        }
    }
}

int *HAND_WAZA_GetPsychoShiftHandlers(int *p)
{
    *p = 1;
    return gPsychoShiftHandlers;
}
