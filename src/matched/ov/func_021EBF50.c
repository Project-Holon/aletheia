/*
 * function: func_021EBF50
 * address:  0x021EBF50
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBF34  0x021EBF34  thumb  ov170
 *
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
#include "../include/Obj07238.h"


struct S;
extern void func_021EBF34(struct S *p, int i);
struct Bank;
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);
void func_021EBF50(char *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        func_021EBF34((struct S *)p, i);
    func_0204B1CC((struct Bank *)(((struct Obj07238 *)p)->f9E70));
}
