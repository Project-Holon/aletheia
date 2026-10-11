/*
 * file:     br_codein_p03.c
 * unit:     yes
 * function: func_021E21E0, func_021E23C8, func_021E24AC
 * address:  0x021E21E0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3900 0x021E3900 data a4
 *   func_021FD15C  0x021FD15C  thumb  ov186
 */
#include "../../matched/include/Obj00683.h"
#include "../../matched/include/Obj24654.h"
#include "../../matched/include/Obj24655.h"
#include "../../matched/include/Obj24656.h"
#include "../../matched/include/Obj24657.h"
#include "../../matched/include/Obj24658.h"
#include "../../matched/include/Obj24659.h"
#include "../../matched/include/Obj24660.h"
#include "../../matched/include/Obj24662.h"
#include "../../matched/include/Obj24664.h"
#include "../../matched/include/Obj24665.h"
#include "../../matched/include/Obj02896.h"
#include "../../matched/include/Obj10761.h"
#include "../../matched/include/Obj24667.h"

struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {u32 a,b;} Pair;

typedef unsigned char u8;

typedef struct { u8 a,b,c,d; void *value; } Rec;

typedef struct { u32 index; u8 f4[8]; char *owner; u8 f10[8]; u32 base; } Input;

extern u32 func_02035D20(u32 *,u32 *);
extern int func_02035C60(void);
extern int func_021E24F8(char *,int,int),func_021E2538(char *,int,int);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021E24C4(char *,char *),func_021FD860(int,int,Pair *);
extern void func_021D76A8(int,int,int);
extern int func_021D76D8(char *p, int id);
extern void func_020061E4(u32 a);
extern int *func_021FD73C(int *p, int v);
extern void func_021E2194(int *task, int *state, char *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern int func_021FC21C(char *p);
extern int func_021FC214(char *);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201EE0C(struct WordSet *,u32,const void *,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_021FD19C(char *p, void *q, void *text);
extern void func_02045808(struct U16Vec *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FD15C(void *p, int a1);
void func_021E21E0(int task,int *state,char *p);
void func_021E23C8(char *p,const Input *q);
void func_021E24AC(char *p, char *a1);
extern const Rec d_021E3900[];

/*
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 */
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

/*
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 */
void func_021E23C8(char *p,const Input *q) {
    struct WordSet *ws;
    struct U16Vec *str,*expanded;
    int font,bank,i;
    const Rec *r;
    char *slot;
    u32 tmp1,tmp;
    u16 *tmp2;
    if(!((struct Obj02896 *)p)->f4) ((struct Obj02896 *)p)->f4=func_021FD12C((int)q->owner,(void *)(*(int *)&((struct Obj02896 *)p)->f0),((struct Obj02896 *)p)->f1C);
    ws=(struct WordSet *)func_021FC21C(q->owner);
    str=func_02045EC0((struct MsgBank *)func_021FC214(q->owner),321);
    tmp2=(u16 *)(p+28);
    expanded=func_020457B0(128,*tmp2);
    tmp1=q->base;
    tmp=q->index;
    func_0201EE0C(ws,0,*(void **)(q->base+tmp*4+16),
        *(u32 *)(tmp1+tmp*4+32),1,2);
    func_0201F250(ws,expanded,str);
    func_021FD19C(((struct Obj02896 *)p)->f4,q->owner,expanded);
    func_02045808(expanded); func_02045808(str);
    func_021FB964((void *)((int)q->owner),30,((struct Obj02896 *)p)->f1C);
    font=func_021FC20C(q->owner);
    bank=func_021FC214(q->owner);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i]; slot=p; slot=slot+i*4;
        ((struct Obj02896 *)slot)->fC=func_021FC6A4(4,r->a,r->b,r->c,r->d,14,((struct Obj02896 *)p)->f0,((struct Obj02896 *)p)->f1C);
        func_021FC754(*(char * *)&((struct Obj02896 *)slot)->fC,(void *)bank,r->value,(void *)font,0x3da0);
    }
}


void func_021E24AC(char *p, char *a1)
{
    if (((struct Obj10761 *)p)->f4 != 0) {
        func_021FD15C((void *)(((struct Obj10761 *)p)->f4), ((struct Obj24667 *)a1)->fC);
        ((struct Obj10761 *)p)->f4 = 0;
    }
}
