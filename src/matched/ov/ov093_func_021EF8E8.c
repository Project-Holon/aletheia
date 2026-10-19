/*
 * function: BTL_FIELD_RemoveStaticSlot
 * address:  0x021EF8E8
 * packet:   pkt_ov093_021EF8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_RemoveSlot  0x021EFA94  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern int BTL_FIELD_RemoveSlot(void *mem, int a);

int BTL_FIELD_RemoveStaticSlot(int a)
{
    return BTL_FIELD_RemoveSlot(&(*(char *)&gBtlFieldCountdown), a);
}
