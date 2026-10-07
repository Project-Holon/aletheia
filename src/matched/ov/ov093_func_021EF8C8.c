/*
 * function: func_021EF8C8
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
 *   func_021EF9F4  0x021EF9F4  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

typedef unsigned int u32;
typedef struct { u32 v; } Slot;

extern struct Countdown d_021F63F4;
extern int func_021EF9F4(void *mem, u32 b, Slot c, int d);

int func_021EF8C8(u32 a, Slot c)
{
    return func_021EF9F4(&(*(char *)&d_021F63F4), a, c, 1);
}
