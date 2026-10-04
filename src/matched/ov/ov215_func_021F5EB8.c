/*
 * function: func_021F5EB8
 * address:  0x021F5EB8
 * packet:   pkt_021F5EB8
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E30 0x02005E30 thumb
 */
#include "../include/Obj25739.h"

typedef unsigned int   u32;
extern void func_02005E30(u32 a);

int func_021F5EB8(int a, char *b)
{
    func_02005E30(0x1e);
    ((struct Obj25739 *)b)->f18 = 1;
    return 1;
}