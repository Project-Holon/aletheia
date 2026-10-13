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
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`a=t;` before `a=t+16;`). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT* in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorPosAxis 0x0204B560 arm
 *   CLACT_SetActorPosAxis 0x0204B550 arm
 */
#include "../include/Obj05300.h"
typedef signed short   s16;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern s16 CLACT_GetActorPosAxis(const struct Actor *actor, u32 axis);
extern void CLACT_SetActorPosAxis(struct Actor *actor, signed short value, u32 axis);
void func_021C0D34(char *p,int force) {
    int n,index,y,a,b,t;
    short pos;
    if(!CLACT_GetActorDrawEnable(((struct Obj05300 *)p)->f8)) return;
    n=((struct Obj05300 *)p)->f98-2;
    index=((struct Obj05300 *)p)->f96;
    if(!force) {
        y=CLACT_GetActorPosAxis(((struct Obj05300 *)p)->f8,1);
        t=137*index/n;
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
    CLACT_SetActorPosAxis(((struct Obj05300 *)p)->f8,pos,1);
}
