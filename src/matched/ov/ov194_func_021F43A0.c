/*
 * function: func_021F43A0
 * address: 0x021F43A0
 * packet: pkt_ov194_021F43A0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   d_020A1B38 0x020A1B38 data a4
 */
#include "../include/Obj01576.h"
typedef struct {short x,y;} Vec2;
extern short d_020A1B38[];
struct Actor; struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
int func_021F43A0(char *p) {
    Vec2 pos;
    int tick;
    if (((struct Obj01576 *)p)->f1C) {
        tick=((struct Obj01576 *)p)->f20;
        ((struct Obj01576 *)p)->f20=tick+1;
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        pos.y=20-((12*d_020A1B38[((unsigned short)(32767*tick/8)>>4)*2])>>12);
        func_0204B404((struct Obj *)(((struct Obj01576 *)p)->f0),(const struct Vec2 *)(&pos),0);
        if (((struct Obj01576 *)p)->f20>8) ((struct Obj01576 *)p)->f1C=0;
        return 0;
    }
    return 1;
}
