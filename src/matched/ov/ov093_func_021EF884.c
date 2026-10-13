/*
 * function: BTL_FIELD_GetCountdownValue
 * address:  0x021EF884
 * packet:   pkt_ov093_021EF884
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_GetCountdownByte  0x021EF9A8  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown gBtlFieldCountdown;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 BTL_FIELD_GetCountdownByte(u32 *p);

int BTL_FIELD_GetCountdownValue(void)
{
    return BTL_FIELD_GetCountdownByte((u32 *)(&(*(char *)&gBtlFieldCountdown)));
}
