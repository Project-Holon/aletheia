/*
 * unit:     yes
 * function: HAND_WAZA_ProtectIncrementStreak, HAND_WAZA_GetBideHandlers
 * address:  0x021E3C5C
 * packet:   pkt_ov093_021E3C5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gBideHandlers     0x021F2FF8  data   a4
 */
#include "../include/Obj06270.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);
extern int gBideHandlers[];

void HAND_WAZA_ProtectIncrementStreak(void *a, int b, int c)
{
    void *q;
    u8 *p;

    q = BTL_SERVER_FLOW_GetPokeParam(a, b);
    p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x26, b);
    p[6] = BTL_POKEPARAM_GetCounter(q, 3) + 1;
    p[4] = b;
    p[5] = 3;
    ((struct Obj06270 *)p)->f0 = (((struct Obj06270 *)p)->f0 & 0xfeffffff) | ((c & 1) << 24);
    BTL_SERVER_FLOW_CommitCmdRecord(a, p);
}

int *HAND_WAZA_GetBideHandlers(int *p)
{
    *p = 7;
    return gBideHandlers;
}
