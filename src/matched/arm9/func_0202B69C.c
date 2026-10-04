/*
 * function: func_0202B69C
 * address:  0x0202B69C
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj02011.h"

typedef unsigned char  u8;
extern void func_0202BEA4(u8 *p);
void func_0202B69C(int a0)
{
    func_0202BEA4((u8 *)(((struct Obj02011 *)a0)->f1C));
    ((struct Obj02011 *)a0)->f1C = 0;
}
