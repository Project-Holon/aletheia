/*
 * function: func_021B2180
 * address: 0x021B2180
 * packet: pkt_ov013_021B2180
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B25B0 0x021B25B0 arm ov013
 */

#include "../../../matched/include/G_Sess.h"

extern struct Sess d_021B60D8;
extern int func_021B25B0(int, int);
int func_021B2180(int a, int b)
{
    if (((int *)&d_021B60D8)[4] == 2) return -3;
    return func_021B25B0(a,b);
}
