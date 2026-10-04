/*
 * function: func_02205340
 * address:  0x02205340
 * packet:   pkt_02205340
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 */
#include "../include/Obj06642.h"

struct Ctx;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);

void func_02205340(int a, char *b)
{
    func_020310C4((struct Tcbl *)(((struct Obj06642 *)b)->f68));
    if (((struct Obj06642 *)b)->f64 != 0)
        func_020286C4((struct Ctx *)(((struct Obj06642 *)b)->f84), (void *)(((struct Obj06642 *)b)->f64), (void *)(((struct Obj06642 *)b)->f6C));
}
