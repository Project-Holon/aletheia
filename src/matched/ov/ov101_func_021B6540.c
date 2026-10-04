/*
 * function: func_021B6540
 * address: 0x021B6540
 * packet: pkt_ov101_021B6540
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B67C4 0x021B67C4 thumb ov101
 */
#include "../include/Obj22097.h"
typedef unsigned int u32;
extern int func_021B67C4(int *p);
int func_021B6540(u32 p) {
    if(((struct Obj22097 *)p)->f78!=0) return 1;
    return func_021B67C4((int *)(p+4));
}
