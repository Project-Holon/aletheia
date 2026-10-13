/*
 * function: POKELIST_IsNotItemUseMode
 * address: 0x021B9AA0
 * packet: pkt_ov091_021B9AA0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj20861.h"
typedef unsigned int u32;
int POKELIST_IsNotItemUseMode(u32 p) {
    if (*(u32 *)(((struct Obj20861 *)p)->f280 + 52) != 1) return 1;
    return 0;
}
