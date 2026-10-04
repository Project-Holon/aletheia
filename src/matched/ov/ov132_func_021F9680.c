/*
 * function: func_021F9680
 * address:  0x021F9680
 * packet:   pkt_021F9680
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020064F4  0x020064F4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23185.h"

typedef unsigned int   u32;
extern void func_020064F4(u32 a);

void func_021F9680(char *p, int a)
{
    ((struct Obj23185 *)p)->f28 = 1;
    func_020064F4(a);
}
