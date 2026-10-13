/*
 * function: BTL_FIELD_QueryStaticSlotB
 * address:  0x021EF90C
 * packet:   pkt_ov093_021EF90C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_RemoveHolderFromSlots  0x021EFB34  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern int BTL_FIELD_RemoveHolderFromSlots(void *mem, int a);

int BTL_FIELD_QueryStaticSlotB(int a)
{
    return BTL_FIELD_RemoveHolderFromSlots(&(*(char *)&gBtlFieldCountdown), a);
}
