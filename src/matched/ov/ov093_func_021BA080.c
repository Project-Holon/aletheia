/*
 * function: func_021BA080
 * address:  0x021BA080
 * packet:   pkt_021BA080
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202E7DC  0x0202E7DC  thumb
 *
 * blocker: target 0x0202E7DC has no `func_`/`sub_` label and no outside
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */
#include "../include/Obj20998.h"

char *func_0202E7DC(char *p);

void func_021BA080(char **p)
{
    func_0202E7DC((char *)(((struct Obj20998 *)(*p))->f70));
}
