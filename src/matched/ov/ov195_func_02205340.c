/*
 * function: func_02205340
 * address:  0x02205340
 * packet:   pkt_02205340
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 */
#include "../include/Obj06642.h"

struct Ctx;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

void func_02205340(int a, char *b)
{
    TCBL_Main((struct Tcbl *)(((struct Obj06642 *)b)->f68));
    if (((struct Obj06642 *)b)->f64 != 0)
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj06642 *)b)->f84), (void *)(((struct Obj06642 *)b)->f64), (void *)(((struct Obj06642 *)b)->f6C));
}
