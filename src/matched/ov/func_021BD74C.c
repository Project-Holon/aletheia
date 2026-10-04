/*
 * function: func_021BD74C
 * address:  0x021BD74C
 * packet:   pkt_021BD74C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases +0 and clears 0x38 bytes of the object.
 */
#include "../include/Obj18236.h"


struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(char *, int, int);

void func_021BD74C(char *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18236 *)p)->f0));
    func_02082BCC(p, 0, 0x38);
}

