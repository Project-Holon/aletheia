/*
 * function: func_021C2BF4
 * address:  0x021C2BF4
 * packet:   pkt_021C2BF4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Leaves state 2 and moves the object at +0xB8 to state 3.
 */
#include "../include/Obj00146.h"


extern void func_02005E9C(int);
typedef unsigned int   u32;
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);

void func_021C2BF4(int unused, char *p)
{
    if (((struct Obj00146 *)p)->fB8 == 2) {
        func_02005E9C(((struct Obj00146 *)p)->fB8);
        func_02005DE4(0);
    }
    func_02005DF8(0x3c);
    ((struct Obj00146 *)p)->fB8 = 3;
}
