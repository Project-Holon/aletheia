/*
 * function: BTL_FIELD_GetCountdownCount
 * address:  0x021EF894
 * packet:   pkt_ov093_021EF894
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_GetCountdownCountIfSet  0x021EF9B0  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
typedef unsigned int   u32;
extern int BTL_FIELD_GetCountdownCountIfSet(u32 *p);

int BTL_FIELD_GetCountdownCount(void)
{
    return BTL_FIELD_GetCountdownCountIfSet((u32 *)(&(*(char *)&gBtlFieldCountdown)));
}
