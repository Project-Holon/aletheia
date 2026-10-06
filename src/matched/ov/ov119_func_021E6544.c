/*
 * function: func_021E6544
 * address: 0x021E6544
 * packet: pkt_ov119_021E6544
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: 0204B454 writes both signed coordinates; all four vector arguments are fully assigned before 021E7248 reads each three-word object.
 * arithmetic: coordinate products fit signed32 for every signed-short input; fixed-point scalar sums use modulo32 ADD. Signed32 products plus 0x800 fit signed64 for every possible input.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0207C7B4 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021E7248 0x021E7248 thumb ov119
 */
#include "../include/Obj05336.h"
typedef signed long long s64;
typedef unsigned int u32;
typedef struct { short x,y; } Pt;
typedef struct { int x,y,z; } T;
typedef struct { T a,b,c,d,e; int i,n; } S;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_0207C7B4(int);
extern void func_021E7248(S *,T *,T *,T *,T *,int);
static inline int mul(int a,int b) { return (int)(((s64)a*b+0x800LL)>>12); }
void func_021E6544(char *p)
{
    T end,third,second,first;
    Pt pos;
    int x,y,dx,dy,speed;
    func_0204B454((struct Actor *)((struct Obj05336 *)p)->fF20,(struct PtS *)&pos,1);
    dx=(pos.x-((struct Obj05336 *)p)->fF6C)*4096;
    dy=(pos.y-((struct Obj05336 *)p)->fF6E)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-((struct Obj05336 *)p)->fF6C)*4096;
    second.y=(pos.y*2-((struct Obj05336 *)p)->fF6E)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=func_0207C7B4((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    func_021E7248((S *)(p+0x1190),&first,&second,&third,&end,19);
    ((struct Obj05336 *)p)->f11DC=21;
}
