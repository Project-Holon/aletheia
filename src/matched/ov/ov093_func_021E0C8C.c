/*
 * function: HAND_WAZA_RefreshCureMajorStatus
 * address:  0x021E0C8C
 * packet:   pkt_ov093_021E0C8C
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10071.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_RefreshCureMajorStatus(int unused, void *q, int id)
{
    u8 *r;
    int t;

    if (id == BTL_EVENT_GetVar(3)) {
        t = BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(q, id));
        if (t == 5 || t == 1 || t == 4) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(q, 0xb, id);
            ((struct Obj10071 *)r)->f4 = t;
            r[8] = id;
            r[0x14] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        }
    }
}
