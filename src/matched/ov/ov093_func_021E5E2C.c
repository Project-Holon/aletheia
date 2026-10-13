/*
 * function: HAND_WAZA_FlingRemoveItemAfterMove
 * address:  0x021E5E2C
 * packet:   pkt_ov093_021E5E2C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21516.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_FlingRemoveItemAfterMove(u8 *p, void *a, int b, int *c)
{
    void *r;
    u8 *q;
    if (b != BTL_EVENT_GetVar(2))
        return;
    if (*c != 0)
        return;
    r = BTL_SERVER_FLOW_GetPokeParam(a, b);
    if ((u16)(u32)BTL_POKEPARAM_GetItem(r) != 0) {
        q = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x23, b);
        ((struct Obj21516 *)q)->f4 = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(a, q);
    }
}
