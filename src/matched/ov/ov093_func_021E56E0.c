/*
 * unit:     yes
 * function: HAND_WAZA_WishSetPosEffect, HAND_WAZA_GetFutureSightHandlers
 * address:  0x021E56E0
 * packet:   pkt_ov093_021E56E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gFutureSightHandlers     0x021F29D8  data   ov093  a4
 */
#include "../include/Obj13527.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gFutureSightHandlers[];

void HAND_WAZA_WishSetPosEffect(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1e, c);
        ((struct Obj13527 *)m)->f4 = 0;
        m[8] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_GetFutureSightHandlers(int *p)
{
    *p = 2;
    return gFutureSightHandlers;
}
