/*
 * unit:     yes
 * function: HAND_TOKUSEI_Hydration_CureStatusInRain, HAND_TOKUSEI_GetHydrationHandlers
 * address:  0x021D9A68
 * packet:   pkt_ov093_021D9A68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHydrationHandlers     0x021F05A8  data   a4
 */
#include "../include/Obj07809.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
struct Unk021D62A8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gHydrationHandlers[];

void HAND_TOKUSEI_Hydration_CureStatusInRain(int a, void *b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 2) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(b, c))) {
            BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0xb, c);
            ((struct Obj07809 *)p)->f4 = 0x24;
            p[8] = c;
            p[0x14] = 1;
            ((struct Obj07809 *)p)->f0 |= 0x2000000;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
        }
    }
}

int *HAND_TOKUSEI_GetHydrationHandlers(int *p)
{
    *p = 1;
    return gHydrationHandlers;
}
