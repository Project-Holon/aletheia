/*
 * function: func_02208B54
 * address:  0x02208B54
 * packet:   pkt_02208B54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_02208714 0x02208714 thumb
 */
#include "../include/Obj05518.h"

typedef unsigned int   u32;
struct Ctx;
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02208714(void *p);

void func_02208B54(char *a)
{
    func_020480E4((struct Ctx *)(*(int *)&((struct Obj05518 *)a)->f14), ((struct Obj05518 *)a)->f18);
    func_02208714((void *)(((struct Obj05518 *)a)->f20));
    ((struct Obj05518 *)a)->f1C = 0;
}