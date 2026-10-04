/*
 * function: func_021887D4
 * address: 0x021887D4
 * packet: pkt_ov096_021887D4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021887F4 0x021887F4 thumb ov096
 */
#include "../include/Obj21922.h"
extern void func_021887F4(int, int, int);
int func_021887D4(int a, int b)
{
    func_021887F4(a, b, 2);
    return ((struct Obj21922 *)((unsigned int)b))->fC4;
}
