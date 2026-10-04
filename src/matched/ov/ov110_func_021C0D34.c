/*
 * function: func_021C0D34
 * address: 0x021C0D34
 * packet: pkt_ov110_021C0D34
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two zero padding bytes follow at 0x021C0DE2.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B560 0x0204B560 arm
 *   func_0204B550 0x0204B550 arm
 */
#include "../include/Obj05300.h"
typedef signed short   s16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);
extern s16 func_0204B560(const struct Actor *actor, u32 axis);
extern void func_0204B550(void *,short,int);
void func_021C0D34(char *p,int force) {
    int n,index,y,a,b,t;
    short pos;
    if(!func_0204B3F4(((struct Obj05300 *)p)->f8)) return;
    n=((struct Obj05300 *)p)->f98-2;
    index=((struct Obj05300 *)p)->f96;
    if(!force) {
        y=func_0204B560(((struct Obj05300 *)p)->f8,1);
        t=137*index/n;
        a=t;
        a=t+16;
        b=137*(index+1)/n+16;
        if(index==0) { if(y<b) return; }
        else if(index==n-1) { if(y>=a) return; }
        else { if(a<=y && y<b) return; }
    }
    if(index==0) pos=16;
    else if(index==n-1) pos=152;
    else {
        t=137*(((struct Obj05300 *)p)->f96)/n;
        pos=t+16+137/(n*2);
        if(pos>152) pos=152;
    }
    func_0204B550(((struct Obj05300 *)p)->f8,pos,1);
}
