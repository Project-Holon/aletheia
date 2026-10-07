/*
 * file:     unit_021B95A0_p05.c
 * unit:     yes
 * function: func_021BA14C, func_021BA1C0, func_021BA1C8, func_021BA200, func_021BA268, func_021BA2E0, func_021BA2F0, func_021BA30C
 * address:  0x021BA14C
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
 *   func_021BA034 0x021BA034 thumb ov213
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B9EB0 0x021B9EB0 thumb ov213
 *   func_0204B8A0 0x0204B8A0 arm
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_020450F0 0x020450F0 arm
 *   func_021B9EE4 0x021B9EE4 thumb ov213
 *   func_020457B0 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_02008550 0x02008550 thumb
 *   func_021B9E80 0x021B9E80 thumb ov213
 *   func_021BA330 0x021BA330 thumb ov213
 *   func_02045808 0x02045808 arm
 *   func_021BA014 0x021BA014 thumb ov213
 *   func_020452E8 0x020452E8 arm
 */
#include "../../matched/include/Obj00443.h"
#include "../../matched/include/Obj25696.h"
#include "../../matched/include/Obj25698.h"
#include "../../matched/include/Obj25699.h"
#include "../../matched/include/Obj25700.h"
#include "../../matched/include/Obj08419.h"
#include "../../matched/include/Obj14694.h"

struct C;
struct Obj;
struct U16Vec;
struct Sub0200852CObj;
struct Descriptor;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {const char *owner;void *a,*b;int c;unsigned char kind,index;char pad12[2];unsigned v14;void *v18;unsigned v1C;char sub[48];int v50;} Context;

extern void func_021BA034(struct C *p, u32 time);
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021B9EB0(void *,u32);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern int func_021B9E50(unsigned);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021B9EE4(struct C *p, void *owner, unsigned char kind, unsigned char index, void *a, void *parent, const unsigned char *types);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int func_021B9E80(unsigned);
extern void func_021BA330(void *,int);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BA014(u8 *);
extern u32 func_020452E8(struct Descriptor *d);
void func_021BA14C(char *p,unsigned limit);
void func_021BA1C0(char *p);
void func_021BA1C8(char *p,void *list,const u8 *flags,int index);
unsigned func_021BA200(unsigned kind,unsigned index);
void func_021BA268(Context *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c);
void func_021BA2E0(char *a);
void func_021BA2F0(u8 *p);
void func_021BA30C(char *p,unsigned limit);

void func_021BA14C(char *p,unsigned limit)
{
    if(((struct Obj00443 *)p)->f28) {
        switch(((struct Obj00443 *)p)->f8) {
        case 0:break;
        case 1:limit=12;break;
        case 3:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=15;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=19;
            break;
        case 2:limit=8;break;
        case 4:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=11;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=15;
            break;
        }
        if(((struct Obj00443 *)p)->f24>=limit) func_021BA034((struct C *)p,limit);
        (((struct Obj00443 *)p)->f24)++;
    }
}

void func_021BA1C0(char *p) {p[0x28]=1;}

void func_021BA1C8(char *p,void *list,const u8 *flags,int index) {void *entry=0;int value;if(index<(int)func_0201AA18(list))entry=func_0201AB28(((struct Obj25696 *)p)->f0,index);value=func_021B9EB0(entry,flags[index]);func_0204B8A0((struct Obj *)(*(u32 *)(p+12+index*4)),value);}

unsigned func_021BA200(unsigned kind,unsigned index)
{
    int x,y;
    if(func_021B9E50(kind)) {
        if(index==0) {x=4;y=17;}
        else {x=16;y=3;}
    } else {
        switch(index) {
        case 0:x=5;y=13;break;
        case 1:x=13;y=19;break;
        case 2:x=15;y=1;break;
        case 3:x=23;y=7;break;
        }
    }
    return func_020450F0(1,(unsigned char)x,(unsigned char)y,10,3,1,1);
}

/*
 * extent: 021BA2DE..021BA2E0 is two zero alignment bytes; following021BA2E0 already filed separately.
 * lever: logical owner,a,b,c,zero field order restores stack-load scheduling; const owner and typed destination alone did not.
 */
void func_021BA268(Context *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c)
{
    void *first,*second;
    int value;
    value=c;first=a;second=b;
    p->owner=owner;p->a=first;p->b=second;
    p->c=value;p->v50=0;
    p->kind=kind;p->index=index;
    func_021B9EE4((struct C *)p->sub,((struct Obj25698 *)owner)->f0,kind,index,a,b,(const unsigned char *)(owner+10));
    p->v18=func_020457B0(16,116);
    func_02008500(((struct Obj25699 *)(p->owner))->f4,p->v18);
    p->v14=func_02008550(((struct Obj25700 *)(p->owner))->f4);
    p->v1C=func_021BA200(kind,index);
    if(func_021B9E80(p->kind)==0) func_021BA330(p,p->c);
}


void func_021BA2E0(char *a)
{
    if (*(int *)&((struct Obj08419 *)a)->f50 == 0x2d)
        func_021BA330(a, ((struct Obj08419 *)a)->fC);
}

void func_021BA2F0(u8 *p) {func_02045808((struct U16Vec *)(((struct Obj14694 *)p)->f18));func_021BA014(p+32);func_020452E8((struct Descriptor *)(((struct Obj14694 *)p)->f1C));}

void func_021BA30C(char *p,unsigned limit){func_021BA14C(p+32,limit);if(func_021B9E80(((struct Obj08419 *)p)->f10))func_021BA2E0(p);(((struct Obj08419 *)p)->f50)++;}
