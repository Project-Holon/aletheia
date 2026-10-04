/*
 * function: func_021DB2E0
 * address: 0x021DB2E0
 * packet: pkt_ov183_021DB2E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021DB3C4 0x021DB3C4 thumb ov183
 *   func_021DB594 0x021DB594 thumb ov183
 *   func_021DB61C 0x021DB61C thumb ov183
 */
#include "../include/Obj02228.h"
#include "../include/Obj03879.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern unsigned func_021F9B9C(char *p);
extern char *func_0203159C(int *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD940(u8 *p, u32 value);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021DB3C4(int *task, int *state, char *p);
extern void func_021DB594(int *task, int *state, char *p);
extern void func_021DB61C(int *task, int *state, char *p);
int func_021DB2E0(int *task, int unused, char *p)
{
    char *s;
    void *callback;
    s=func_0203159C(task,0x20,func_021F9B9C(((struct Obj03879 *)p)->f10));
    func_02082BCC(s,0,0x20);
    *(char * *)&((struct Obj02228 *)s)->f1C=p;
    ((struct Obj02228 *)s)->f4=func_021F9B9C(((struct Obj03879 *)p)->f10);
    ((struct Obj02228 *)s)->fC=(void *)func_0201C440((void *)(((struct Obj02228 *)s)->f4));
    ((struct Obj02228 *)s)->f14=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),0,((struct Obj02228 *)s)->f4);
    ((struct Obj02228 *)s)->f18=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),1,((struct Obj02228 *)s)->f4);
    func_021FD940(((struct Obj02228 *)s)->f14,1);
    func_021FD940(((struct Obj02228 *)s)->f18,1);
    if(((struct Obj03879 *)p)->f0==0) callback=func_021DB3C4;
    else if(((struct Obj03879 *)p)->f0==1) callback=func_021DB594;
    else callback=func_021DB61C;
    ((struct Obj02228 *)s)->f0=func_021FD6D8((int)s,(int)callback,((struct Obj02228 *)s)->f4);
    return 1;
}
