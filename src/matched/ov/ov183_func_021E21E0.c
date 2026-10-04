/*
 * function: func_021E21E0
 * address: 0x021E21E0
 * packet: pkt_ov183_021E21E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021E24F8 0x021E24F8 thumb ov183
 *   func_021E2538 0x021E2538 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021E24C4 0x021E24C4 thumb ov183
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021D76A8 0x021D76A8 thumb ov125
 *   func_021D76D8 0x021D76D8 thumb ov125
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E2194 0x021E2194 thumb ov183
 */
#include "../include/Obj00683.h"
#include "../include/Obj24654.h"
#include "../include/Obj24655.h"
#include "../include/Obj24656.h"
#include "../include/Obj24657.h"
#include "../include/Obj24658.h"
#include "../include/Obj24659.h"
#include "../include/Obj24660.h"
#include "../include/Obj24662.h"
#include "../include/Obj24664.h"
#include "../include/Obj24665.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {u32 a,b;} Pair;
extern u32 func_02035D20(u32 *,u32 *),func_02035C60(void);
extern int func_021E24F8(char *,int,int),func_021E2538(char *,int,int);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021E24C4(char *,char *),func_021FD860(int,int,Pair *);
extern void func_021D76A8(int,int,int);
extern int func_021D76D8(char *p, int id);
extern void func_020061E4(int);
extern void func_021FD73C(int *p, int v);
extern void func_021E2194(int task, int *state, char *p);
void func_021E21E0(int task,int *state,char *p) {
    u32 x0,y0,x1,y1; Pair first; u32 x9,y9; Pair second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(func_02035D20(&x0,&y0)) {
            if(func_021E24F8(p,x0,y0)) {func_021FD170((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24654 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)322);*state=1;}
            else if(func_021E2538(p,x0,y0))*state=10;
        } break;
    case 1:
        if(func_02035D20(&x1,&y1)) {
            if(func_021E24F8(p,x1,y1))*state=2;
            else if(func_021E2538(p,x1,y1))*state=10;
        } break;
    case 2:func_021FE784(((struct Obj24655 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4,2,2,1);++*state;break;
    case 3:
        if(func_021FE7B0(*(int * *)&((struct Obj24656 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4)) {
            func_021E24C4(p,*(char * *)&((struct Obj00683 *)p)->f20);
            func_021FD170((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24657 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)323);
            first.a=128;first.b=96;func_021FD860(((struct Obj00683 *)p)->f14,4,&first);
            ((struct Obj00683 *)p)->f24=0;++*state;
        } break;
    case 4:func_021FE784(((struct Obj24658 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4,2,2,0);++*state;break;
    case 5:if(func_021FE7B0(*(int * *)&((struct Obj24659 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f4))++*state;break;
    case 6:
        func_021D76A8(((struct Obj24660 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f14,((struct Obj00683 *)p)->f1C,**(int * *)&((struct Obj00683 *)p)->f20);
        ++((struct Obj00683 *)p)->f24;++*state;break;
    case 7:
        result=func_021D76D8((char *)(((struct Obj24662 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f14),**(int * *)&((struct Obj00683 *)p)->f20);
        ++((struct Obj00683 *)p)->f24;
        if((u32)(result-2)<=1) {((struct Obj24664 *)(*(char * *)&((struct Obj00683 *)p)->f20))->f1C=1;*state=8;}break;
    case 8:
        old=((struct Obj00683 *)p)->f24;((struct Obj00683 *)p)->f24=old+1;
        if(old>96) {func_021FD860(((struct Obj00683 *)p)->f14,0,0);func_021FD170((char *)(((struct Obj00683 *)p)->f4),(char *)(((struct Obj24665 *)(*(char * *)&((struct Obj00683 *)p)->f20))->fC),(void *)324);*state=9;}break;
    case 9:
        if(func_02035C60()) {
            func_02035D20(&x9,&y9);second.a=x9;second.b=y9;
            func_021FD860(((struct Obj00683 *)p)->f18,1,&second);func_020061E4(0x703);*state=10;
        }break;
    case 10:func_021FD73C((int *)task,(int)func_021E2194);break;
    }
}
