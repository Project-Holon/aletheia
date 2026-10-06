/*
 * function: func_021F7BA8
 * address: 0x021F7BA8
 * packet: pkt_ov112_021F7BA8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_021F9FD0 0x021F9FD0 thumb ov132
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9FB4 0x021F9FB4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   func_020061F8 0x020061F8 thumb
 */
#include "../include/Obj06409.h"
#include "../include/Obj08028.h"
#include "../include/Obj22562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { u16 count,pad; int index,a,b; } Tail;
extern u8 *func_021F5450(u8 *,int);
extern char *func_021F5464(char *);
typedef unsigned int   u32;
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern void func_021F9FD0(char *,int,int);
extern void *func_021F9DC0(void *p);
extern void func_021F9FB4(char *,int);
extern void func_021F9F58(u8 *unused, u8 *p);
extern void func_020061F8(int);
void func_021F7BA8(u8 *p,u8 *q)
{
    Tail *t=(Tail *)(q+240);
    u8 *r=func_021F5450(*(u8 * *)&((struct Obj06409 *)q)->f58,((struct Obj06409 *)q)->fF4);
    Vec v;
    int a;
    if(((struct Obj06409 *)q)->f8==1 && ((struct Obj22562 *)r)->f0==1) {
        func_021F4EA4(((struct Obj08028 *)p)->f10,*(int *)(q+132+t->index*4),(u32)(&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        func_0207C9D0((Vec *)(q+24),(Vec *)func_021F5464(*(char * *)&((struct Obj06409 *)q)->f58),&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    func_021F9FD0((char *)t->a,0,(int)&v);
    t->count++;
    if(t->count>=180) {
        a=(int)func_021F9DC0((void *)(((struct Obj08028 *)p)->f4));
        func_021F9FB4((char *)t->a,0);
        func_021F9F58((void *)a,(void *)t->a);
        ((struct Obj06409 *)q)->f104=0;
        ((struct Obj08028 *)p)->f43C-=1;
        if(((struct Obj08028 *)p)->f43C==0) func_020061F8(2);
    }
}
