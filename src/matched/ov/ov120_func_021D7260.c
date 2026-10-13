/*
 * function: func_021D7260
 * address: 0x021D7260
 * packet: pkt_ov120_021D7260
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_021D71B8 0x021D71B8 thumb ov120
 */
#include "../include/Obj10398.h"
typedef unsigned char u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_021D71B8(u8 *, void *, int);
void func_021D7260(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct Obj10398 *)p)->f160) CLACT_DeleteActor(((struct Obj10398 *)p)->f160);
        for (i = 5; i > 0; i--) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x148 + i * 4);
        ((struct Obj10398 *)p)->f14C = 0;
        func_021D71B8(p, q, 0);
    }
}
