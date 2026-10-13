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
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_SwapMembers  0x0201AB8C  thumb  arm9
 *
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
#include "../include/Obj18447.h"


extern unsigned int POKEPARTY_GetCount(void *);
typedef unsigned int   u32;
struct Party;
extern u32 POKEPARTY_SwapMembers(struct Party *p, u32 i, u32 j, u32 heap);
void func_021DD42C(int *p, unsigned char *a)
{
    unsigned i = ((struct Obj18447 *)a)->f4 - 0x1e;
    while (i < POKEPARTY_GetCount(*(void **)(*p + 8)) - 1) {
        POKEPARTY_SwapMembers((struct Party *)(*(int *)(*p + 8)), i, i + 1, 0x4c);
        i++;
    }
}
