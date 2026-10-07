/*
 * function: func_021B0CD8
 * address: 0x021B0CD8
 * packet: pkt_ov013_021B0CD8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B3C24 0x021B3C24 data a4
 *   d_021B3C84 0x021B3C84 data a4
 *   func_021B3018 0x021B3018 arm ov013
 */

#include "../include/G_021B3C84.h"

extern int d_021B3C24;
extern struct G_021B3C84 d_021B3C84;
extern void func_021B3018(void);
void func_021B0CD8(int a)
{
    d_021B3C24 = a;
    func_021B3018();
    if (a == 0) ((int *)&d_021B3C84)[2] = 1;
}
