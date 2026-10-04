/*
 * function: func_021BFCA4
 * address: 0x021BFCA4
 * packet: pkt_ov110_021BFCA4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding follow the return.
 * symbols:
 *   func_021BFED0 0x021BFED0 thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 *   func_021BFF7C 0x021BFF7C thumb ov110
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_021BC78C 0x021BC78C thumb ov110
 */
#include "../include/Obj03756.h"
typedef unsigned char u8;
extern void func_021BFED0(u8 *,int);
extern unsigned func_021BF734(u8 *);
extern void func_021BFF7C(u8 *,unsigned,unsigned);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern void func_021BC78C(u8 *,int,int,int,int);
void func_021BFCA4(u8 *p,int amount) {
    int count,i;
    u8 newy;
    int newstart,start,step;
    u8 y;
    func_021BFED0(p,amount);
    count=amount*2;
    start=((struct Obj03756 *)p)->f98;
    newstart=start+count;
    step=24*amount;
    newy=(u8)(((struct Obj03756 *)p)->f94+step);
    if(amount<0) {
        start=newstart;
        y=newy;
        count=-count;
        amount=-amount;
    } else {
        y=(u8)(((struct Obj03756 *)p)->f94+192);
        start+=16;
        if(count+start>func_021BF734(*(u8 * *)&((struct Obj03756 *)p)->f4)) count--;
    }
    for(i=0;i<count;i++) {
        func_021BFF7C(p,start+i,y);
        if(i&1) y+=24;
    }
    ((struct Obj03756 *)p)->f94=newy;
    ((struct Obj03756 *)p)->f98=newstart;
    func_02045334((struct Descriptor *)((struct Obj03756 *)p)->fC);
    func_02045374((struct Cfg *)(((struct Obj03756 *)p)->fC));
    func_021BC78C(p+0x6c,2,1,step,amount);
}
