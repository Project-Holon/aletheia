/*
 * function: HAND_TOKUSEI_BlockIndirectDamage
 * address:  0x021D928C
 * packet:   pkt_ov093_021D928C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
#include "../include/Obj21283.h"

extern int BTL_EVENT_GetVar(int);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_BlockIndirectDamage(int a, int b, int c, int d)
{
    if (b == BTL_EVENT_GetVar(2) && b != BTL_EVENT_GetVar(3)) {
        if (d == 8 || d == BTL_EVENT_GetVar(0x1f)) {
            if (BTL_EVENT_GetVar(0x20) < 0)
                ((struct Obj21283 *)c)->f0 = BTL_EVENT_OverwriteVar(0x41, 1);
        }
    }
}
