/*
 * function: HAND_TOKUSEI_HealInWeather
 * address:  0x021D9880
 * packet:   pkt_ov093_021D9880
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 */
#include "../include/Obj10057.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);

void HAND_TOKUSEI_HealInWeather(void *a, int b, int c)
{
    void *q;
    u8 *p;

    if (c == BTL_EVENT_GetVar(0x39) && b == BTL_EVENT_GetVar(2)) {
        q = BTL_SERVER_FLOW_GetPokeParam(a, b);
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 5, b);
        ((struct Obj10057 *)p)->f0 |= 0x800000;
        p[6] = b;
        ((struct Obj10057 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(q, 0x10);
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        BTL_EVENT_OverwriteVar(0x41, 1);
    }
}
