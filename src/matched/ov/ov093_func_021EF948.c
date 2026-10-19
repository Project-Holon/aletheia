/*
 * function: BTL_FIELD_IsStaticSlotInUse
 * address:  0x021EF948
 * packet:   pkt_ov093_021EF948
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_IsSlotInUse  0x021EFCE4  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern void *BTL_FIELD_IsSlotInUse(char *arg0, int arg1);

int BTL_FIELD_IsStaticSlotInUse(int a)
{
    return (int)BTL_FIELD_IsSlotInUse(&(*(char *)&gBtlFieldCountdown), a);
}
