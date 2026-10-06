/*
 * function: func_021F42E8
 * address: 0x021F42E8
 * packet: pkt_ov194_021F42E8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_02035D20 0x02035D20 arm
 *   func_021F4450 0x021F4450 thumb ov194
 *   func_021F4394 0x021F4394 thumb ov194
 *   func_021F43A0 0x021F43A0 thumb ov194
 */
#include "../include/Obj01576.h"
typedef struct {short x,y;} Vec2;
struct Actor; struct PtS;
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F4450(int *,int *);
extern void func_021F4394(unsigned char *p);
extern int func_021F43A0(char *);
void func_021F42E8(char *p) {
    int rect[4];
    unsigned x,y;
    Vec2 pos;
    int point[2];
    switch (((struct Obj01576 *)p)->f18) {
    case 0:
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        ((struct Obj01576 *)p)->f14=0;
        if (func_02035D20(&x,&y)) {
            rect[0]=pos.x-16; rect[1]=pos.y-16;
            rect[2]=pos.x+16; rect[3]=pos.y+16;
            point[0]=x; point[1]=y;
            if (func_021F4450(rect,point)) {
                func_021F4394((unsigned char *)p);
                ((struct Obj01576 *)p)->f18=1;
            }
        }
        break;
    case 1:
        if (func_021F43A0(p)) {((struct Obj01576 *)p)->f14=1; ((struct Obj01576 *)p)->f18=0;}
        break;
    }
}
