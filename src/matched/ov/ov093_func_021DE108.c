/*
 * function: HAND_ITEM_RememberAttackerOfCategory
 * address:  0x021DE108
 * packet:   pkt_ov093_021DE108
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021DE170  0x021DE170  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21383.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021DE170(u16 a);
extern void BTL_EVENT_KeepFactorRunning(void *a);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_RememberAttackerOfCategory(void *a, void *b, int c, int *d, int e)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0
        && func_021DE170(BTL_EVENT_GetVar(0x12)) == 0 && e == BTL_EVENT_GetVar(0x1a)) {
        BTL_EVENT_KeepFactorRunning(a);
        *d = BTL_EVENT_GetVar(3) + 1;
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0, c);
        ((struct Obj21383 *)m)->f4 |= 2;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}
