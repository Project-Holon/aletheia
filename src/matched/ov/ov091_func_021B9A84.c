/*
 * function: func_021B9A84
 * address: 0x021B9A84
 * packet: pkt_ov091_021B9A84
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj20860.h"
typedef unsigned int u32;
int func_021B9A84(u32 p) {
    u32 v = *(u32 *)(((struct Obj20860 *)p)->f280 + 52);
    if (v == 1 || v == 22 || v == 23) return 1;
    return 0;
}
