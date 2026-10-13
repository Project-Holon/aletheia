/*
 * function: BTL_FIELD_ResetStatic
 * address:  0x021EF874
 * packet:   pkt_ov093_021EF874
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_Init  0x021EF988  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
extern int BTL_FIELD_Init(void *mem, int a);

int BTL_FIELD_ResetStatic(int a)
{
    return BTL_FIELD_Init(&(*(char *)&gBtlFieldCountdown), a);
}
