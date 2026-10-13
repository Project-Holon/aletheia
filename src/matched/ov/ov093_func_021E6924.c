/*
 * function: HAND_WAZA_MinimizeSetState
 * address:  0x021E6924
 * packet:   pkt_ov093_021E6924
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
 */
#include "../include/Obj13536.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_MinimizeSetState(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x17, c);
        m[8] = c;
        ((struct Obj13536 *)m)->f4 = 8;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}
