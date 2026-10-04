/*
 * function: func_021EE200
 * address:  0x021EE200
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
 * Walk 9 8-byte records releasing both words of each, then the
 *   head.
 */
#include "../include/Obj18525.h"


struct Grid;
struct Obj020437AC;
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *p);
void func_021EE200(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        func_0202570C((struct Grid *)(*(int *)(p + i * 8 + 4)));
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 8 + 8)));
    }
    func_02025588((void *)(((struct Obj18525 *)p)->f0));
}
