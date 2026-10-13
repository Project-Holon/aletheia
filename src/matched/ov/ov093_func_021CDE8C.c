/*
 * function: BTL_CLIENT_PollWindowStep
 * address:  0x021CDE8C
 * packet:   pkt_ov093_021CDE8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_StepOpenBattleWindow  0x021CDDDC  thumb  ov093
 *   BTL_REC_ReadSkipFlag  0x021EE688  thumb  ov093
 *   BTL_CLIENT_RequestCounterAdvance  0x021D3F54  thumb  ov093
 */
#include "../include/Obj06232.h"

typedef unsigned char  u8;
extern int BTL_CLIENT_StepOpenBattleWindow(u8 *p, int *st);
extern int BTL_REC_ReadSkipFlag(int, int);
extern void BTL_CLIENT_RequestCounterAdvance(u8 *p);

int BTL_CLIENT_PollWindowStep(int a, int b)
{
    int r4;
    if (((struct Obj06232 *)a)->f54 != 0) {
        r4 = BTL_CLIENT_StepOpenBattleWindow((u8 *)a, (int *)b);
        if (r4 != 0) {
            if (BTL_REC_ReadSkipFlag(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6) != 0)
                BTL_CLIENT_RequestCounterAdvance((u8 *)(a + 0x18));
        }
        return r4;
    }
    BTL_REC_ReadSkipFlag(((struct Obj06232 *)a)->f14, ((struct Obj06232 *)a)->f1A6);
    return 1;
}
