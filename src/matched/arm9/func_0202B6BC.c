/*
 * function: func_0202B6BC
 * address:  0x0202B6BC
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj02011.h"

struct Obj;
extern void func_0202B8E4(struct Obj *o);
void func_0202B6BC(int a0)
{
    func_0202B8E4((struct Obj *)(((struct Obj02011 *)a0)->f24));
    ((struct Obj02011 *)a0)->f24 = 0;
}
