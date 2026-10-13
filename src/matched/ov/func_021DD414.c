/*
 * function: func_021DD414
 * address:  0x021DD414
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_SwapMembers  0x0201AB8C  thumb  arm9
 *
 * Forward two biased halfword coordinates.
 */
#include "../include/Obj12149.h"
#include "../include/Obj18446.h"

typedef unsigned int   u32;
struct Party;
extern u32 POKEPARTY_SwapMembers(struct Party *p, u32 i, u32 j, u32 heap);

void func_021DD414(char **p, char *q)
{
    POKEPARTY_SwapMembers((struct Party *)(((struct Obj18446 *)(*p))->f8), ((struct Obj12149 *)q)->f4 - 0x1e,
                  ((struct Obj12149 *)q)->f2 - 0x1e, 0x4c);
}

