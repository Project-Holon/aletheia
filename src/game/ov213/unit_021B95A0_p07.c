/*
 * file:     unit_021B95A0_p07.c
 * unit:     yes
 * function: func_021BA5A0, func_021BA624, func_021BA650, func_021BA68C, func_021BA6C8, func_021BA710, func_021BA71C, func_021BA750
 * address:  0x021BA5A0
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8A0 0x0204B8A0 arm
 *   func_021BAC94 0x021BAC94 thumb ov213
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B800 0x0204B800 arm
 */
#include "../../matched/include/Obj04630.h"
#include "../../matched/include/Obj14695.h"
#include "../../matched/include/Obj14696.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {int pad0;const void *owner;void *other;u16 a,b;void *one,*two,*objects[3];char pad24[2];u8 kind;} Context;

typedef struct { int f0, f4, f8, fC; } Out;

typedef struct { int f0; u32 f4; int f8, fC, f10, f14, f18; u8 b1c,b1d,b1e; } In;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern int func_021B9E50(unsigned);
extern void func_0204B3DC(struct Obj *p, unsigned int v),func_0204B92C(void *,unsigned);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern u32 func_021BAC94(char *p);
extern void func_021B6208(Out *out, In *in, int unused, unsigned heap);
extern void func_021B6284(unsigned int *p);
extern void *func_021B629C(void *,int,unsigned char,unsigned char,unsigned char,unsigned short);
extern void func_0204B3DC(struct Obj *p, unsigned int v),func_0204B800(void *,unsigned);
void func_021BA5A0(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind);
void func_021BA624(char *p);
void func_021BA650(char *p);
void func_021BA68C(char *p,unsigned i,int kind);
void func_021BA6C8(char *p, void *state, short heap);
void func_021BA710(char *p);
void *func_021BA71C(char *p,int a,int b,unsigned short c);
void *func_021BA750(void *p,int kind,unsigned a);

/*
 * lever: source kind,a,b emits image a,kind,b stores and both entry copies; source a,kind,b left115 differing bytes.
 * domain: loop index is exactly 0,1,2; each switch arm initializes both coordinates before use.
 */
void func_021BA5A0(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind)
{
    int i,x,y;
    p->owner=owner;p->other=other;
    p->kind=kind;p->a=a;p->b=b;
    p->one=func_021BA750((void *)owner,0,(u8)p->a);
    p->two=func_021BA750((void *)owner,1,(u8)p->b);
    for(i=0;i<3;i++) {
        switch(i) {
        case 0:x=206;y=152;break;
        case 1:x=50;y=40;break;
        case 2:x=128;y=96;break;
        }
        p->objects[i]=func_021BA71C((void *)owner,x,y,7);
        func_0204B3DC(p->objects[i],0);
    }
}

void func_021BA624(char *p){int i;for(i=0;i<3;i++)func_0204B3B4(*(void **)((unsigned)p+i*4+24));for(i=0;i<2;i++)func_0204B3B4(*(void **)((unsigned)p+i*4+16));}

void func_021BA650(char *p){func_021B9E50(((struct Obj04630 *)p)->f26);if(((struct Obj04630 *)p)->f24==30){func_0204B3DC(((struct Obj04630 *)p)->f10,1);func_0204B92C(((struct Obj04630 *)p)->f10,1);func_0204B3DC(((struct Obj04630 *)p)->f14,1);func_0204B92C(((struct Obj04630 *)p)->f14,1);}(((struct Obj04630 *)p)->f24)++;}

void func_021BA68C(char *p,unsigned i,int kind){int n;switch(kind){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;}p+=24;func_0204B3DC(*(void **)((unsigned)p+i*4),1);func_0204B92C(*(void **)((unsigned)p+i*4),1);func_0204B8A0(*(void **)((unsigned)p+i*4),n);}

void func_021BA6C8(char *p, void *state, short heap)
{
    int resource;
    In config;
    ((struct Obj14695 *)p)->f0 = state;
    ((struct Obj14695 *)p)->f4 = heap;
    config.f0=0;
    config.f4=0;
    config.f8=0xB5;
    config.fC=9;
    config.f10=8;
    config.f14=7;
    config.f18=6;
    config.b1c=0;
    config.b1d=0;
    config.b1e=4;
    resource=func_021BAC94(state);
    func_021B6208((Out *)(p+8), &config, resource, heap);
}

void func_021BA710(char *p){func_021B6284((unsigned int *)(p+8));}

void *func_021BA71C(char *p,int a,int b,unsigned short c){return func_021B629C(p+8,func_021BAC94(((struct Obj14696 *)p)->f0),a,b,c,((struct Obj14696 *)p)->f4);}

void *func_021BA750(void *p,int kind,unsigned a){int x,y;void *v;if(kind==0){x=206;y=152;}else{x=50;y=40;}v=func_021BA71C(p,x,y,a);func_0204B3DC(v,0);func_0204B800(v,1);return v;}
