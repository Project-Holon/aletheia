/*
 * function: func_021C0EB0
 * address: 0x021C0EB0
 * packet: pkt_ov110_021C0EB0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   CLACT_SetActorPosAxis 0x0204B550 arm
 *   func_021C0E3C 0x021C0E3C thumb ov110
 */
#include "../include/Obj05301.h"
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
struct Actor;
extern void CLACT_SetActorPosAxis(struct Actor *actor, signed short value, u32 axis);
extern void func_021C0E3C(unsigned y, int count, short *out, short *pos);
int func_021C0EB0(char *p) {
    unsigned x,y;
    unsigned short index;
    short pos;
    if(!TOUCHPANEL_GetPointCont(&x,&y)) {
        ((struct Obj05301 *)p)->f99=(((struct Obj05301 *)p)->f99&~1);
        return 0;
    }
    func_021C0E3C(y,((struct Obj05301 *)p)->f98,(short int *)(&index),&pos);
    CLACT_SetActorPosAxis(((struct Obj05301 *)p)->f8,pos,1);
    if((unsigned short)index!=((struct Obj05301 *)p)->f96) {
        ((struct Obj05301 *)p)->f96=index;
        return 1;
    }
    return 0;
}
