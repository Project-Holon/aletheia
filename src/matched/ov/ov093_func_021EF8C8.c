/*
 * function: BTL_FIELD_RegisterStaticSlot
 * address:  0x021EF8C8
 * packet:   pkt_ov093_021EF8C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_FIELD_RegisterSlot  0x021EF9F4  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

typedef unsigned int u32;
typedef struct { u32 v; } Slot;

extern struct Countdown gBtlFieldCountdown;
extern int BTL_FIELD_RegisterSlot(void *mem, u32 b, Slot c, int d);

int BTL_FIELD_RegisterStaticSlot(u32 a, Slot c)
{
    return BTL_FIELD_RegisterSlot(&(*(char *)&gBtlFieldCountdown), a, c, 1);
}
