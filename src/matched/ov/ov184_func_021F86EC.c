/*
 * function: func_021F86EC
 * address: 0x021F86EC
 * packet: pkt_ov184_021F86EC
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   func_021F88E0 0x021F88E0 thumb ov184
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
#include "../include/Obj00548.h"
#include "../include/Obj24704.h"
#include "../include/Obj24705.h"
#include "../include/Obj24708.h"
#include "../include/Obj24709.h"
#include "../include/Obj24710.h"
#include "../include/Obj24711.h"
#include "../include/Obj24714.h"
typedef unsigned short u16;
typedef struct Cfg {int a,b;} Cfg;
typedef struct Pair {int x,y;} Pair;
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021F89D0(char *,char *),func_021F88E0(char *,char *);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int,int,Pair *);
extern void func_02082BCC(void *,int,unsigned),func_021FF54C(char *,int,Cfg *);
extern int func_021FF648(char *),func_021FF72C(char *,int *),func_02035C60(void),func_02035D20(int *,int *);
extern void func_020061E4(int);
extern int func_021FD744(int a);
extern void func_021F9BA0(int);
void func_021F86EC(int task,unsigned *state,char *p)
{
    Pair initial;
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,4,3,1);*state=1;break;
    case 1:if(func_021FE7B0(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=2;break;
    case 2:
        func_021F89D0(p,*(char * *)&((struct Obj00548 *)p)->f30);
        func_021F88E0(p,*(char * *)&((struct Obj00548 *)p)->f30);
        ((struct Obj00548 *)p)->f10=func_021FD12C(((struct Obj24704 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC,(void *)(((struct Obj00548 *)p)->f20),((struct Obj00548 *)p)->f24);
        func_021FD170(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24705 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)0x145);
        initial.x=0x80;initial.y=0x60;
        func_021FD860(((struct Obj00548 *)p)->f14,4,&initial);
        *state=3;break;
    case 3:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,4,3,0);*state=4;break;
    case 4:if(func_021FE7B0(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=5;break;
    case 5:
        func_02082BCC(&cfg,0,8);
        cfg.a=((struct Obj00548 *)p)->f28;
        func_021FF54C(*(char * *)&((struct Obj24708 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,0,&cfg);
        *(int *)&((struct Obj00548 *)p)->f2C=0;
        *state=6;break;
    case 6:
        ((struct Obj00548 *)p)->f2C=((struct Obj00548 *)p)->f2C+1;
        if(func_021FF648(*(char * *)&((struct Obj24709 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14) && ((struct Obj00548 *)p)->f2C>0x60) {
            func_021FD860(((struct Obj00548 *)p)->f14,0,0);*state=7;
        }break;
    case 7:
        if(!func_021FF72C(*(char * *)&((struct Obj24710 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,&out)) *state=9;
        else {func_021FD170(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24711 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)out);*state=8;}
        break;
    case 8:
        if(func_02035C60()) {
            func_02035D20(&x,&y);pair.x=x;pair.y=y;
            func_021FD860(((struct Obj00548 *)p)->f18,1,&pair);
            func_020061E4(0x703);*state=9;
        }break;
    case 9:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,2,3,1);*state=10;break;
    case 10:if(func_021FE7B0(**(int ** *)&((struct Obj00548 *)p)->f30)) *state=11;break;
    case 11:func_021FD744(task);func_021F9BA0(((struct Obj24714 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f10);break;
    }
}
