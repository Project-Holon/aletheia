/*
 * function: HAND_TOKUSEI_SolarPower_DamageInSun
 * address:  0x021D98DC
 * packet:   pkt_ov093_021D98DC
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
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 */
#include "../include/Obj13463.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);

void HAND_TOKUSEI_SolarPower_DamageInSun(int a, void *b, int c)
{
    int h;
    u8 *p;

    if (c == BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(0x39) == 1) {
        h = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(b, c), 8);
        BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
        p[6] = c;
        ((struct Obj13463 *)p)->f4 = h;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
    }
}
