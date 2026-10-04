/*
 * function: func_021C0DE4
 * address: 0x021C0DE4
 * packet: pkt_ov110_021C0DE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035D20 0x02035D20 arm
 */
#include "../include/Obj10284.h"
typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
int func_021C0DE4(char *p) {
    unsigned x,y;
    if(!func_0204B3F4(((struct Obj10284 *)p)->f8)) return 0;
    if(!func_02035D20(&x,&y)) return 0;
    if(x>=240 && x<=247 && y<=159 && y>=8) {
        ((struct Obj10284 *)p)->f99=(((struct Obj10284 *)p)->f99&~1)|1;
        return 1;
    }
    return 0;
}
