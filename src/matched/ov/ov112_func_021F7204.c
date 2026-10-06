/*
 * function: func_021F7204
 * address: 0x021F7204
 * packet: pkt_ov112_021F7204
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 * symbols:
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021F5350 0x021F5350 thumb ov112
 *   func_021F5368 0x021F5368 thumb ov112
 *   func_021F535C 0x021F535C thumb ov112
 *   func_021F5424 0x021F5424 thumb ov112
 *   func_020056EC 0x020056EC thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   table 0x020A1B38 data a2
 */
#include "../include/Obj00904.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { int m[9]; } Mtx;
extern s16 table[];
extern u8 *func_021F545C(u8 *);
extern char *func_021F5464(char *);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern void func_0207AF38(Mtx *,int,int);
extern void func_0207B51C(const Vec *,const Mtx *,Vec *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern void func_021F5350(int *p, int *q);
extern void func_021F5368(int *,u16);
extern void func_021F535C(int *p, int *q);
extern void func_021F5424(int,int);
extern u32 func_020056EC(u32);
void func_021F7204(u8 *p,u8 *q)
{
    Vec pos;
    Vec scale;
    Vec delta;
    Mtx matrix;
    Vec *a;
    Vec *b;
    int angle;
    a=(Vec *)func_021F545C(*(u8 * *)&((struct Obj00904 *)q)->f58);
    b=(Vec *)func_021F5464(*(char * *)&((struct Obj00904 *)q)->f58);
    func_0207C9D0((Vec *)(q+24),(Vec *)(q+48),&pos);
    angle=((struct Obj00904 *)q)->f48;
    delta.x=0;
    delta.y=b->y;
    func_0207AF38(&matrix,-table[(angle>>4)*2],table[(angle>>4)*2+1]);
    func_0207B51C(&delta,&matrix,(Vec *)(q+60));
    func_0207CA00(&delta,(Vec *)(q+60),(Vec *)(q+60));
    pos.x=(pos.x-a->x-((struct Obj00904 *)q)->f3C)/16;
    pos.y=(0xc0000-(pos.y-a->y+((struct Obj00904 *)q)->f40))/16;
    func_021F5350(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&pos));
    func_021F5368(*(int * *)&((struct Obj00904 *)q)->f58,((struct Obj00904 *)q)->f48);
    scale.x=((struct Obj00904 *)q)->f24<<4;
    scale.y=((struct Obj00904 *)q)->f28<<4;
    scale.z=((struct Obj00904 *)q)->f2C<<4;
    if(((struct Obj00904 *)q)->f54==1) scale.x*=-1;
    func_021F535C(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&scale));
    ((struct Obj00904 *)q)->f4=0;
    if(((struct Obj00904 *)q)->f4C==1) {
        ((struct Obj00904 *)q)->f50+=(u16)func_020056EC(2);
        if(((struct Obj00904 *)q)->f50>120) func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,1);
        else func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,0);
        if(((struct Obj00904 *)q)->f50>125) ((struct Obj00904 *)q)->f50=func_020056EC(120)/3U;
    }
}
