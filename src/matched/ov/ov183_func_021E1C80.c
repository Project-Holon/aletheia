/*
 * function: func_021E1C80
 * address: 0x021E1C80
 * packet: pkt_ov183_021E1C80
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021E1DA8 0x021E1DA8 thumb ov183
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   d_021E38E0 0x021E38E0 data a4
 */
#include "../include/Obj02232.h"
#include "../include/Obj05482.h"
typedef unsigned short u16;
typedef struct {int a,b;} Pair;
extern const Pair d_021E38E0;
typedef unsigned int   u32;
extern unsigned func_021F9B9C(char *p);
extern char *func_0203159C(int,int,int);
extern void func_02082BCC(void *,int,int);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021E1DA8(int,int *,char *);
extern u32 func_0201C440(void *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD860(int,int,Pair *);
int func_021E1C80(int obj,int unused,char *arg)
{
    char *p;
    int i;
    Pair pair;
    p=func_0203159C(obj,32,func_021F9B9C((char *)(((struct Obj05482 *)arg)->fC)));
    func_02082BCC(p,0,32);
    *(char * *)&((struct Obj02232 *)p)->f18=arg;
    ((struct Obj02232 *)p)->f8=func_021F9B9C((char *)(((struct Obj05482 *)arg)->fC));
    ((struct Obj02232 *)p)->f4=(int)func_021FD6D8((int)p,(int)func_021E1DA8,((struct Obj02232 *)p)->f8);
    ((struct Obj02232 *)p)->f0=func_0201C440((void *)(((struct Obj02232 *)p)->f8));
    ((struct Obj02232 *)p)->fC=(int)func_021FD12C(((struct Obj05482 *)arg)->f8,(void *)(((struct Obj02232 *)p)->f0),((struct Obj02232 *)p)->f8);
    func_021FD170((char *)(((struct Obj02232 *)p)->fC),(char *)(((struct Obj05482 *)arg)->f8),(void *)111);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x10)=(int)func_021FD760(((struct Obj05482 *)arg)->f4,(char *)(((struct Obj05482 *)arg)->f8),i,((struct Obj02232 *)p)->f8);
    pair=d_021E38E0;
    func_021FD860(((struct Obj02232 *)p)->f10,4,&pair);
    return 1;
}
