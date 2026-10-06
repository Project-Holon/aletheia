/*
 * function: func_021FC268
 * address: 0x021FC268
 * packet: pkt_ov132_021FC268
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_02030734 0x02030734 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FC34C 0x021FC34C thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj02194.h"
#include "../include/Obj05404.h"
#include "../include/Obj08170.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
typedef struct { int x,y,z; } Vec;
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
extern void func_021F6F04(void *,char *,Vec *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207CA00(void *,void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FC34C(int,char *);
extern const char d_021FDD00[];
int func_021FC268(int unused,char *p)
{
    char *owner,*q;
    Vec pos;
    int delta[3];
    u32 e,d,c,b,a;
    void *target;
    void *ctx;
    owner=*(char * *)&((struct Obj05404 *)p)->f0;
    a=func_0201134C(((struct Obj05404 *)p)->f4);
    b=func_0201134C(((struct Obj05404 *)p)->f4);
    c=func_0201134C(((struct Obj05404 *)p)->f4);
    d=func_0201134C(((struct Obj05404 *)p)->f4);
    e=func_0201134C(((struct Obj05404 *)p)->f4);
    ctx=func_021F9DD4(((struct Obj08170 *)owner)->f34);
    target=func_021F9DDC(((struct Obj08170 *)owner)->f34,a);
    if (b==0) {
        pos.x=c;pos.y=d;pos.z=e;
        func_021F6EF4(ctx,target,(const u32 *)(&pos));
    } else {
        q=func_02030734(((struct Obj08170 *)owner)->f0,56,0,d_021FDD00,0x704);
        *(char * *)&((struct Obj02194 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02194 *)q)->f0=target;
        ((struct Obj02194 *)q)->f4=((struct Obj08170 *)owner)->f34;
        ((struct Obj02194 *)q)->f2E=0;
        func_021F6F04(ctx,target,(Vec *)(q+8));
        ((struct Obj02194 *)q)->f14=c;((struct Obj02194 *)q)->f18=d;((struct Obj02194 *)q)->f1C=e;
        ((struct Obj02194 *)q)->f2C=b;
        func_0207CA00(q+20,q+8,delta);
        ((struct Obj02194 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02194 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02194 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02194 *)q)->f34=func_021FADA0(owner,(u32)func_021FC34C,(u32)q,10);
    }
    return 0;
}
