/*
 * file:     guru2_p01.c
 * unit:     yes
 * function: func_021DC860, func_021DC888, func_021DC8BC, func_021DC8D0, func_021DC90C, func_021DC924, func_021DC928, func_021DC950, func_021DC9AC
 * address:  0x021DC860
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_02031330 0x02031330 arm
 *   d_021E1A50 0x021E1A50 data a4
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_02030734 0x02030734 arm
 *   func_021DCB04 0x021DCB04 thumb ov137
 *   d_021E2260 0x021E2260 data a4
 *   func_021DCB90 0x021DCB90 thumb ov137
 *   func_021DCB60 0x021DCB60 thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   func_02031348 0x02031348 arm
 *   d_021E1A38 0x021E1A38 data a4
 */
#include "../../matched/include/Obj10612.h"
#include "../../matched/include/Obj23664.h"
#include "../../matched/include/Obj23665.h"
#include "../../matched/include/Obj23666.h"
#include "../../matched/include/Obj14200.h"
#include "../../matched/include/Obj14201.h"
#include "../../matched/include/Obj23667.h"
#include "../../matched/include/Obj08208.h"

struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct BigObj;
struct DC950Obj;
struct DC950Src;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DC950Src {
    u32 pad_00[4];
    void *unk_10;
};

struct DC950Obj {
    void *unk_00;
    void *unk_04;
    u32 pad_08[11];
    int unk_34;
    u32 unk_38;
    int unk_3c;
    u32 pad_40[22];
};

extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void *func_02031324(int a0);
extern u32 func_02031330(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 *func_021DCB04(u32,int);
extern void func_021DCB90(void *);
extern void func_021DCB60(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_02031348(void *,int,const void *,void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0203D7B0(u8 a0);
int func_021DC860(void *obj,int a,u8 *ctx);
int func_021DC888(void *obj,int a,int b,u8 *p);
int func_021DC8BC(void *obj,int a,int b,u8 *p);
void *func_021DC8D0(void *q,int heap);
void func_021DC90C(u8 *p);
void *func_021DC924(u8 *p);
int func_021DC928(u8 *p);
struct DC950Obj *func_021DC950(struct DC950Src *p,int a,int b);
int func_021DC9AC(u32 *p);
extern const u8 d_021E2260[];
extern const u8 d_021E1A38[];
extern const unsigned char d_021BED00[];
extern const unsigned char d_0000005B[];

int func_021DC860(void *obj,int a,u8 *ctx) { u8 *p=func_0203159C(obj,36,4); func_02082BCC(p,0,36); ((struct Obj10612 *)p)->f10=((struct Obj23664 *)ctx)->f4; ((struct Obj10612 *)p)->f8=ctx; ((struct Obj10612 *)p)->f20=func_02031324(1); return 1; }

extern int (* const d_021E1A50[])(u8 *);

int func_021DC888(void *obj,int a,int b,u8 *p) { switch(func_02031330(((struct Obj23665 *)p)->f20)) { case 0: if(d_021E1A50[*(u32 *)p](p)==1) return 1; break; case 1: break; case 2: break; } return 0; }

int func_021DC8BC(void *obj,int a,int b,u8 *p) { func_0203133C(((struct Obj23666 *)p)->f20); func_020315D4(obj); return 1; }

void *func_021DC8D0(void *q,int heap) {u8 *p;p=func_02030734((u16)heap,36,0,(const char *)d_021E2260,171);func_02082BCC(p,0,36);((struct Obj14200 *)p)->f14=q;((struct Obj14200 *)p)->f18=func_021DCB04((u32)p,heap);return p;}

void func_021DC90C(u8 *p) {func_021DCB90(((struct Obj14201 *)p)->f18);func_021DCB60(((struct Obj14201 *)p)->f18);func_020307B0(p);}

void *func_021DC924(u8 *p) { return ((struct Obj23667 *)p)->f10; }

int func_021DC928(u8 *p) {void *v;v=func_021DC8D0(((struct Obj08208 *)p)->f8,4);((struct Obj08208 *)p)->f0=1;((struct Obj08208 *)p)->fC=v;func_02031348(((struct Obj08208 *)p)->f20,-1,d_021E1A38,v);return 0;}

/*
 * func_02030734 0x02030734 arm
 * d_021E2260 0x021E2260 data a4
 */
struct DC950Obj *func_021DC950(struct DC950Src *p,int a,int b)
{
    struct DC950Obj *v;
    int i;
    v=func_02030734(4,sizeof(struct DC950Obj),1,(const char *)d_021E2260,256);
    v->unk_00=func_02012934(p->unk_10);
    v->unk_04=func_0201292C(p->unk_10);
    v->unk_38=0;
    v->unk_34=a;
    v->unk_3c=b;
    for(i=0;i<(int)func_0201AA18(v->unk_00);i++) func_0201AB28(v->unk_00,i);
    return v;
}

/*
 * func_021DC924 0x021DC924 thumb ov137
 * func_021DC950 0x021DC950 thumb ov137
 * func_0203D7B0 0x0203D7B0 arm
 * func_02031348 0x02031348 arm
 * d_021BED00 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
int func_021DC9AC(u32 *p)
{
    void *v;
    if (!func_021DC924((void *)p[3])) p[0]=5;
    else {
        func_0203D7B0(1);
        v=func_021DC950((struct DC950Src *)p,21,0);
        p[6]=(u32)v;
        func_02031348((void *)p[8],(int)d_0000005B,d_021BED00,v);
        *(u32 *)p[3]=1;
        p[0]=2;
    }
    return 0;
}
