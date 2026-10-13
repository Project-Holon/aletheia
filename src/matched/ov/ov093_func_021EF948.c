/*
 * function: BTL_FIELD_GetStaticSlotObject
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
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern void *func_021EFCE4(char *arg0, int arg1);

int BTL_FIELD_GetStaticSlotObject(int a)
{
    return (int)func_021EFCE4(&(*(char *)&gBtlFieldCountdown), a);
}
