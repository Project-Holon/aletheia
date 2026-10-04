/*
 * function: func_021BD848
 * address:  0x021BD848
 * packet:   pkt_021BD848
 * region:   ov208
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj05536.h"

typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021BD848(char *p, int which)
{
    if (which != 0)
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f28;
    }
    else
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f24;
    }
    func_0204B878(((struct Obj05536 *)p)->f0, (unsigned short)((struct Obj05536 *)p)->f8);
}
