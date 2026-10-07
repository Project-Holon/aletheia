/*
 * file:     unit_021F8480_p03.c
 * unit:     yes
 * function: func_021F8790, func_021F88B0
 * address:  0x021F8790
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF660 0x021FF660 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F8A0C 0x021F8A0C thumb ov185
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021F8D18 0x021F8D18 thumb ov185
 *   func_021F8D98 0x021F8D98 thumb ov185
 *   func_021F86E4 0x021F86E4 thumb ov185
 */
#include "../../matched/include/Obj01276.h"
#include "../../matched/include/Obj24723.h"
#include "../../matched/include/Obj24724.h"
#include "../../matched/include/Obj24725.h"
#include "../../matched/include/Obj24726.h"
#include "../../matched/include/Obj24727.h"
#include "../../matched/include/Obj24728.h"
#include "../../matched/include/Obj03886.h"

typedef unsigned short u16;

typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;

typedef struct Pair {int x,y;} Pair;

typedef unsigned int   u32;

extern void func_02082BCC(void *,int,unsigned);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *),func_021FF72C(char *,int *),func_021FF660(char *,int,int,int *);
extern void func_021FD860(int,int,Pair *);
extern int *func_021FD73C(int *p, int v);
extern void func_021FD170(char *p, char *q, void *text);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern void func_021F8A0C(int *sys, int *state, char *p);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern void func_021F8FB0(char *,char *);
extern void func_021F8D18(char *,int *);
extern void func_021F8D98(char *,char *);
extern void func_021F86E4(int,int,char *);
void func_021F8790(int *task,unsigned *state,char *p);
void func_021F88B0(int a,int *state,char *p);

void func_021F8790(int *task,unsigned *state,char *p)
{
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:
        func_02082BCC(&cfg,0,8);
        cfg.heap=((struct Obj01276 *)p)->f8;
        ((struct Obj01276 *)p)->fA=0;
        func_021FF54C(*(char * *)&((struct Obj24723 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,1,(const int *)(&cfg));
        *state=1; break;
    case 1:
        ((struct Obj01276 *)p)->fA=((struct Obj01276 *)p)->fA+1;
        if(func_021FF648(*(char * *)&((struct Obj24724 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14) && ((struct Obj01276 *)p)->fA>0x60) {
            func_021FD860(((struct Obj01276 *)p)->f38,0,0);
            *state=2;
        }
        break;
    case 2:
        if(!func_021FF72C(*(char * *)&((struct Obj24725 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,&out)) {
            if(func_021FF660(*(char * *)&((struct Obj24726 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,(int)(p+0x40),5,(int *)(p+0x54)) && ((struct Obj01276 *)p)->f54) {
                ((struct Obj01276 *)p)->fC=0;
                func_021FD73C(task,(int)func_021F88B0);
                break;
            }
            *state=3;
            func_021FD170(((struct Obj01276 *)p)->f4,((struct Obj24727 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)0x14d);
        }else{
            *state=3;
            func_021FD170(((struct Obj01276 *)p)->f4,((struct Obj24728 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)out);
        }
        break;
    case 3:
        if(func_02035C60()) {
            func_02035D20((u32 *)(&x),(u32 *)(&y));
            pair.x=x;pair.y=y;
            func_021FD860(((struct Obj01276 *)p)->f3C,1,&pair);
            func_020061E4(0x703);
            func_021FD73C(task,(int)func_021F8A0C);
        }
        break;
    }
}

void func_021F88B0(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj03886 *)p)->f34,4,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=2; break;
    case 2: func_021F8FB0(p,*(char * *)&((struct Obj03886 *)p)->f34); func_021F8D18(p,*(int * *)&((struct Obj03886 *)p)->f34); func_021F8D98(p,*(char * *)&((struct Obj03886 *)p)->f34); *state=3; break;
    case 3: func_021FE784(**(int * *)&((struct Obj03886 *)p)->f34,4,3,0); *state=4; break;
    case 4: if (func_021FE7B0((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=5; break;
    case 5: ((struct Obj03886 *)p)->f20=1; func_021FD73C((int *)a,(int)func_021F86E4); break;
    }
}
