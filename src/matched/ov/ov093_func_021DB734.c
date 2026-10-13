/*
 * function: HAND_TOKUSEI_Klutz_BlockNaturalGift
 * address:  0x021DB734
 * packet:   pkt_ov093_021DB734
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
#include "../include/Obj13478.h"

extern int BTL_EVENT_GetVar(int);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_Klutz_BlockNaturalGift(int a, int b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(2)) {
        unsigned short t = (unsigned short)BTL_EVENT_GetVar(0x12);
        ((struct Obj13478 *)d)->f8 = 0;
        if (t == 0x16b && c == BTL_EVENT_GetVar(2))
            ((struct Obj13478 *)d)->f8 = BTL_EVENT_OverwriteVar(0x22, 0x13);
    }
}
