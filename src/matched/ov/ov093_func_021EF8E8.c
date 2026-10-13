/*
 * function: BTL_FIELD_QueryStaticSlotA
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
 *   func_021EFA94  0x021EFA94  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern int func_021EFA94(void *mem, int a);

int BTL_FIELD_QueryStaticSlotA(int a)
{
    return func_021EFA94(&(*(char *)&gBtlFieldCountdown), a);
}
