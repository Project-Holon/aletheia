/*
 * function: func_0202B68C
 * address:  0x0202B68C
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
extern void func_0202B3EC(u8 *p);
void func_0202B68C(int a0)
{
    func_0202B3EC((u8 *)(((struct Obj02011 *)a0)->f18));
    ((struct Obj02011 *)a0)->f18 = 0;
}
