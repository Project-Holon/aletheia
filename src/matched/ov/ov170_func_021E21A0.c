/*
 * function: func_021E21A0
 * address: 0x021E21A0
 * packet: pkt_ov170_021E21A0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA784 0x021EA784 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23887.h"
#include "../include/Obj23888.h"
typedef unsigned char u8;
extern void func_020061E4(unsigned);
extern void func_021EA784(int p);
extern void func_021ED888(char *,int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF670(char *);
typedef unsigned int   u32;
extern u32 func_0201AA18(void *p);
extern void func_021EE364(char **,int,int);
extern void func_021EF68C(char *);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021E22B8(int p);
#define W(p) (*(char **)((p)+0x2C))
#define NEXT(p) (*(int *)(W(p)+0xA198))
int func_021E21A0(u8 *p)
{
    func_020061E4(0x55C);
    switch(((struct Obj23887 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        func_021EA784((int)p);
        func_021ED888(W(p),0);
        func_021ECB20((char *)p,1,1);
        func_021DEFEC((char *)p,30);
        NEXT(p)=0x31;
        break;
    case 1:
        func_021DEFEC((char *)p,0);
        NEXT(p)=0x2C;
        break;
    case 2:
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x11;
        break;
    case 3:
        func_021ECB20((char *)p,0x81,1);
        func_021DEFEC((char *)p,0);
        func_021EF670(W(p));
        NEXT(p)=0x39;
        break;
    case 4:
        if(func_0201AA18(((struct Obj23888 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8)==0) {
            func_021EF670(W(p));
            func_021DEFEC((char *)p,0);
            func_021EE364((char **)p,13,0);
            NEXT(p)=0x23;
        } else {
            func_021EA784((int)p);
            func_021ED888(W(p),0);
            func_021ECB20((char *)p,1,1);
            func_021EF68C(W(p));
            func_021DEFEC((char *)p,30);
            func_021EE364((char **)p,14,0);
            NEXT(p)=0x27;
        }
        break;
    case 5:
        func_021DEFEC((char *)p,0);
        func_021ECB20((char *)p,0x81,1);
        func_021EE038((char *)p,0,1,1);
        NEXT(p)=0x4B;
        break;
    }
    return func_021E22B8((int)p);
}
