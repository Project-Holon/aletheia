/*
 * function: HAND_ITEM_RaiseStat
 * address:  0x021DD9E8
 * packet:   pkt_ov093_021DD9E8
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
#include "../include/Obj07818.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_RaiseStat(void *a, int b, int c, int d)
{
    u8 *p;
    if (b == BTL_EVENT_GetVar(2)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xe, b);
        ((struct Obj07818 *)p)->f4 = c;
        p[0xc] = d;
        p[0xf] = 1;
        p[0x10] = b;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
