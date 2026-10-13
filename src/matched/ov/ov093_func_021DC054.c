/*
 * function: HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop
 * address:  0x021DC054
 * packet:   pkt_ov093_021DC054
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj05217.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop(int u, void *a, u32 b)
{
    u8 *e;
    u8 v;
    if (b == BTL_EVENT_GetVar(2)
        && (v = BTL_EVENT_GetVar(3), BTL_MAIN_IsPokeSamePair(b, v)) == 0
        && BTL_EVENT_GetVar(0x20) < 0) {
        e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xe, b);
        ((struct Obj05217 *)e)->f0 |= 0x20 << 18;
        ((struct Obj05217 *)e)->f4 = 1;
        e[0xc] = 2;
        e[0xe] = 1;
        e[0xf] = 1;
        e[0x10] = b;
        BTL_SERVER_FLOW_CommitCmdRecord(a, e);
    }
}
