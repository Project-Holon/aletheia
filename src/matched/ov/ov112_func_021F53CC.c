/*
 * function: func_021F53CC
 * address: 0x021F53CC
 * packet: pkt_ov112_021F53CC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F62B0 0x021F62B0 thumb ov112
 */
#include "../include/Obj22540.h"
typedef unsigned int u32;
extern void func_021F62B0(char *, u32);
void func_021F53CC(int a, u32 n)
{
    func_021F62B0(*(char * *)&((struct Obj22540 *)a)->f8, n);
}
