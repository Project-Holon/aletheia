/*
 * function: func_021D8C5C
 * address:  0x021D8C5C
 * packet:   pkt_021D8C5C
 * region:   ov125
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * If the object's 0x800 field is set, hand it to func_021D7C90 and clear it.
 *
 * symbols:
 *   func_021D7C90  0x021D7C90  arm  ov125
 */
#include "../include/Obj14014.h"

void func_021D7C90(int x);

void func_021D8C5C(void *p)
{
    int v;

    v = ((struct Obj14014 *)p)->f800;
    if (v == 0)
        return;
    func_021D7C90(v);
    ((struct Obj14014 *)p)->f800 = 0;
}
