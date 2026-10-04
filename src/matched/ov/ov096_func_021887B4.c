/*
 * function: func_021887B4
 * address: 0x021887B4
 * packet: pkt_ov096_021887B4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021887F4 0x021887F4 thumb ov096
 */
#include "../include/Obj21920.h"
extern void func_021887F4(int, int, int);
int func_021887B4(int a, int b)
{
    func_021887F4(a, b, 0);
    return ((struct Obj21920 *)((unsigned int)b))->fC4;
}
