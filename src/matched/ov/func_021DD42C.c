/*
 * function: func_021DD42C
 * address:  0x021DD42C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
#include "../include/Obj18447.h"


extern unsigned int func_0201AA18(void *);
typedef unsigned int   u32;
struct Party;
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
void func_021DD42C(int *p, unsigned char *a)
{
    unsigned i = ((struct Obj18447 *)a)->f4 - 0x1e;
    while (i < func_0201AA18(*(void **)(*p + 8)) - 1) {
        func_0201AB8C((struct Party *)(*(int *)(*p + 8)), i, i + 1, 0x4c);
        i++;
    }
}
