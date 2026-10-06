/*
 * function: func_021DB698
 * address: 0x021DB698
 * packet: pkt_ov183_021DB698
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 * symbols:
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021F9CB8 0x021F9CB8 thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 */
#include "../include/Obj01072.h"
#include "../include/Obj02517.h"
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *,int,int);
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void func_021FC1F8(int *,int);
typedef unsigned int   u32;
struct Obj;
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u32 heap);
extern void func_021FE840(int,int,int);
int func_021DB698(int *task,int b,char *p)
{
    char *s;
    s=func_0203159C((struct Obj0203159C *)task,24,func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C)));
    func_02082BCC(s,0,24);
    *(char * *)&((struct Obj02517 *)s)->fC=p;
    ((struct Obj02517 *)s)->f14=func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C));
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,0);
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,1);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),0,((struct Obj02517 *)s)->f14);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->f0<5) func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,3,((struct Obj02517 *)s)->f14);
    else func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,4,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f4=(int)func_021FD760(((struct Obj01072 *)p)->f14,(char *)(*(int *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f0=(int)func_021F9CB8(((struct Obj01072 *)p)->f0,((struct Obj01072 *)p)->f14,*(int *)&((struct Obj01072 *)p)->f18,((struct Obj01072 *)p)->f20,((struct Obj01072 *)p)->f24,((struct Obj02517 *)s)->f4,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->fC==4) func_021FE840(((struct Obj01072 *)p)->f10,2,0);
    else func_021FE840(((struct Obj01072 *)p)->f10,3,0);
    return 1;
}
