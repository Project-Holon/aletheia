/*
 * function: func_021BE680
 * address:  0x021BE680
 * packet:   pkt_021BE4DC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD208 0x021BD208  thumb  ov208

 * Frees the three allocations at +0x5C..+0x64 and clears +0x30.
 */
#include "../include/Obj01081.h"


struct Ov208Mgr;
extern void func_021BD208(struct Ov208Mgr *m);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);

void func_021BE680(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        func_021BD208((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        func_0204ADA4(((struct Obj01081 *)p)->f5C);
        func_0204A8D4(((struct Obj01081 *)p)->f60);
        func_0204AFD8(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}

