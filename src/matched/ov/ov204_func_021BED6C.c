/*
 * function: func_021BED6C
 * address: 0x021BED6C
 * packet: pkt_ov204_021BED6C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj08383.h"
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
int func_021BED6C(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        func_0204A8D4(((struct Obj08383 *)q)->f10B4);
        func_0204ADA4(((struct Obj08383 *)q)->f10C0);
        func_0204AFD8(((struct Obj08383 *)q)->f10CC);
        func_0204B3B4(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}
