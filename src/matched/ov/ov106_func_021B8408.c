/*
 * function: func_021B8408
 * address: 0x021B8408
 * packet: pkt_ov106_021B8408
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8A6C 0x021B8A6C thumb ov106
 */
#include "../include/Obj01710.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
extern void func_021B8A6C(u8 *,int);
void func_021B8408(u8 *p,s16 delta) {
    int old,next;
    int i;
    old=((struct Obj01710 *)p)->f556;
    next=old+delta;
    if(((struct Obj01710 *)p)->f558>next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f558;
        ((struct Obj01710 *)p)->f55E=0;
    } else if(((struct Obj01710 *)p)->f55A<next) {
        ((struct Obj01710 *)p)->f556=((struct Obj01710 *)p)->f55A;
        ((struct Obj01710 *)p)->f55E=0;
    } else {
        if(old/24!=next/24 && old%24!=0) {
            if(delta>=0)delta=delta-next%24;
            else delta=delta+(24-next%24);
        }
        ((struct Obj01710 *)p)->f556+=delta;
        ((struct Obj01710 *)p)->f55E=delta;
    }
    for(i=0;i<((struct Obj01710 *)p)->f554;i++)func_021B8A6C(p+0x188+i*32,((struct Obj01710 *)p)->f556);
    ((struct Obj01710 *)p)->f594=1;
}
