/*
 * function: func_021B25FC
 * address: 0x021B25FC
 * packet: pkt_ov013_021B25FC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B4BD0 0x021B4BD0 data a4
 */
#include "../../../matched/include/Obj00947.h"
#include "../../../matched/include/G_Stats.h"
typedef unsigned char u8;
extern struct Stats d_021B4BD0;
void func_021B25FC(u8 *a,u8 *b)
{
    if(b[10] == 1) {
        b[11]=a[4];
        ((struct Obj00947 *)b)->fC=((int *)&d_021B4BD0)[1];
    }
}
