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
 *   func_021EFB34  0x021EFB34  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern int func_021EFB34(void *mem, int a);

int BTL_FIELD_QueryStaticSlotB(int a)
{
    return func_021EFB34(&(*(char *)&gBtlFieldCountdown), a);
}
