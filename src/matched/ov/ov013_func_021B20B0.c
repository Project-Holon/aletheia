/*
 * function: func_021B20B0
 * address: 0x021B20B0
 * packet: pkt_ov013_021B20B0
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B2564 0x021B2564 arm ov013
 */

#include "../include/G_Sess.h"

extern struct Sess d_021B60D8;
extern int func_021B2564(int, int);
int func_021B20B0(int a, int b)
{
    if (((int *)&d_021B60D8)[4] == 2) return -3;
    return func_021B2564(a,b);
}
