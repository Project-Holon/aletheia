/*
 * function: func_021EF948
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
 *   d_021F63F4  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

extern struct Countdown d_021F63F4;
extern void *func_021EFCE4(char *arg0, int arg1);

int func_021EF948(int a)
{
    return (int)func_021EFCE4(&(*(char *)&d_021F63F4), a);
}
