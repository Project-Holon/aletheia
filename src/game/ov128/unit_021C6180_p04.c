/*
 * file:     unit_021C6180_p04.c
 * unit:     yes
 * function: func_021C69C4, func_021C6A5C, func_021C6A84, func_021C6AC0, func_021C6ADC, func_021C6B38, func_021C6B50, func_021C6BCC, func_021C6C20, func_021C6C94, func_021C6CB0, func_021C6DAC, func_021C6DD8, func_021C6DF8, func_021C6E18, func_021C6E3C, func_021C6E74, func_021C6EA0, func_021C6EC0, func_021C7138, func_021C7140, func_021C72A0, func_021C72E4, func_021C734C
 * address:  0x021C69C4
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02045088 0x02045088 arm
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02049EF4 0x02049EF4 arm
 *   d_021CA4F5 0x021CA4F5 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0200846C 0x0200846C thumb
 *   func_020099D4 0x020099D4 thumb
 *   func_02045924 0x02045924 arm
 *   func_020084E4 0x020084E4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02009864 0x02009864 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021CA800 0x021CA800 data a2
 *   d_021CA810 0x021CA810 data a2
 *   d_021CA818 0x021CA818 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_021C74C4 0x021C74C4 thumb ov128
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_021CA1E0 0x021CA1E0 thumb ov128
 *   func_021C76BC 0x021C76BC thumb ov128
 *   func_021C74E8 0x021C74E8 thumb ov128
 *   func_021C7500 0x021C7500 thumb ov128
 *   func_021C7558 0x021C7558 thumb ov128
 *   func_021CA014 0x021CA014 thumb ov128
 *   func_021C7674 0x021C7674 thumb ov128
 *   func_021C6460 0x021C6460 thumb ov128
 *   func_021CA084 0x021CA084 thumb ov128
 *   func_021C7694 0x021C7694 thumb ov128
 *   func_021CA19C 0x021CA19C thumb ov128
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0202EA40 0x0202EA40 thumb
 *   func_0204B98C 0x0204B98C arm
 *   d_021CA4F9 0x021CA4F9 data a1
 *   func_02012944 0x02012944 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02041090 0x02041090 arm
 *   func_02040618 0x02040618 arm
 *   func_021CA16C 0x021CA16C thumb ov128
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202EB04 0x0202EB04 thumb
 *   func_021CA154 0x021CA154 thumb ov128
 *   func_021CA184 0x021CA184 thumb ov128
 */
#include "../../matched/include/Obj08126.h"
#include "../../matched/include/Obj00725.h"
#include "../../matched/include/Obj23068.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj05378.h"
#include "../../matched/include/Obj14046.h"
#include "../../matched/include/Obj10485.h"
#include "../../matched/include/Obj10483.h"
#include "../../matched/include/Obj23069.h"
#include "../../matched/include/Obj02481.h"
#include "../../matched/include/Obj14034.h"
#include "../../matched/include/Obj02482.h"
#include "../../matched/include/Obj02841.h"
#include "../../matched/include/Obj04505.h"
#include "../../matched/include/Obj14035.h"

struct U16Vec;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct WordSet;
struct BigObj;
struct Sub020097BCEnt;
struct Sub020097BCObj;
struct Strbuf;
struct Obj;
struct Actor;
struct TaskMenu;
struct TaskMenuTmpl;
struct P;
struct Row;
struct R;
struct StrObj;
struct TaskMenuState;
struct CodeIn;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned long long u64;

typedef signed short s16;

typedef struct {s16 x,y,z;u8 a,b;} Point;

typedef struct {int heap;u8 count;u8 pad[3];void *entries;int mode;u8 x,y,a,b;} TextConfig;

struct P {
    u8 pad00[44];
    void *buf;
    void *text1;
    u16 color1;
    u16 pad36;
    u32 flag1;
    void *text2;
    u16 color2;
    u16 pad42;
    u32 flag2;
    void *menu;
};

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02045088(u16 heapId);
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021CA4B4(char *p);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern unsigned int func_0201283C(const struct BigObj *p);
extern void *func_0200846C(int);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void *func_0204B294(u32,u32,u32,u32,const Point *,u16,u32);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern u8 func_020355C4(void);
extern int func_021C74C4(int *p, int *q, u8 *r);
extern void func_021CA3A0(char *);
extern void func_021CA3C4(char *);
extern int func_021CA1E0(char *p);
extern int func_021C76BC(int *p, u8 *q);
extern void func_021C74E8(u32 *p, u8 *q);
extern void func_021C7500(u8 *,u8 *);
extern void func_021C7558(u8 *,u8 *,unsigned,unsigned);
extern u64 func_021CA014(void *,int *);
extern int func_021C7674(void *p, int *q, u8 *r);
extern int func_021C6460(char *p, void *q, u32 arg);
extern int func_021CA084(int *p);
extern void func_021C7694(u8 *p, void *ctx);
extern void func_021CA19C(unsigned *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_0204B98C(struct Actor *a);
extern u8 *func_02012944(void *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021CA444(char *);
extern void func_021CA458(char *p, void *q);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_021CA16C(u8 *,int);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_0202EB04(struct CodeIn *p);
extern void func_021CA154(u8 *, int);
extern void func_021CA184(u8 *, int, int);
void func_021C69C4(u8 *p,const u8 *q,u16 heap);
void func_021C6A5C(u8 *p);
void func_021C6A84(u8 *p,u16 heap);
void func_021C6AC0(u8 *p);
void func_021C6ADC(u8 *p,u8 *q,unsigned v);
void func_021C6B38(u8 *p);
void func_021C6B50(void **p,u64 value);
void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap);
int func_021C6C20(u8 *p,u8 *q,int idx);
void func_021C6C94(char **p, int a);
void func_021C6CB0(char *p,int heap);
void func_021C6DAC(u8 *p);
void func_021C6DD8(u8 *p,u32 a);
void func_021C6DF8(u8 *p,u32 a);
void func_021C6E18(u8 *p,int i,u16 a);
void *func_021C6E3C(void *p,void **q,int a,int heap);
int func_021C6E74(u8 *p);
void func_021C6EA0(u8 *p,u8 *q,u8 *r,u16 heap);
int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap);
void func_021C7138(u8 *p,u8 *q,u8 *ctx);
void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap);
void func_021C72A0(u8 *p, u8 *unused, u8 *q);
void func_021C72E4(u8 *p,int *q,u8 *ctx);
int func_021C734C(u32 *p, int *q, u8 *ctx);
extern const u8 d_021CA4F5[];
extern const Point d_021CA800[];
extern const Point d_021CA810;
extern const Point d_021CA818;
extern const u8 d_021CA4F9[];

void func_021C69C4(u8 *p,const u8 *q,u16 heap)
{
    func_02049B40(23,5,0,320,32,heap);
    func_02049B40(23,5,4,448,32,heap);
    func_0201F5BC(1,70,11,q[13],heap);
    func_02045088(heap);
    func_021C63AC(p,(u32 *)(p+12),1,1,0,24,3,10,100,0);
    ((struct Obj08126 *)p)->f14=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f18=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f1C=func_020457B0(128,heap);
    ((struct Obj08126 *)p)->f20=func_020457B0(128,heap);
}

void func_021C6A5C(u8 *p) { func_02045808(((struct Obj00725 *)p)->f1C);func_02045808(((struct Obj00725 *)p)->f20);func_02045808(((struct Obj00725 *)p)->f14);func_02045808(((struct Obj00725 *)p)->f18);func_020452E8(((struct Obj00725 *)p)->fC);func_020450C8(); }

void func_021C6A84(u8 *p,u16 heap) {int i;for(i=0;i<2;i++) *(void **)(p+0x16c+i*4)=func_02049EF4(((struct Obj23068 *)p)->f8,d_021CA4F5[i],0,(void **)(p+0x174+i*4),heap);}


/*
 * Addresses are Black-image addresses.
 */
void func_021C6AC0(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_020307B0(*(void **)(p + 0x16c + i * 4));
}

void func_021C6ADC(u8 *p,u8 *q,unsigned v)
{
    func_02043B5C(func_02045770(((struct Obj05378 *)q)->f0),0);
    func_02045334(((struct Obj05378 *)q)->f0);
    func_02045CAC(((struct Obj00329 *)p)->f4,v,((struct Obj00329 *)p)->f18);
    func_0201F250(((struct Obj00329 *)p)->f0,((struct Obj00329 *)p)->f14,((struct Obj00329 *)p)->f18);
    func_021B6AE4(q,(void *)(((struct Obj00329 *)p)->f34),0,4,(u32)(((struct Obj00329 *)p)->f14),(u32)(((struct Obj00329 *)p)->f17C),0x3c40,0);
    func_021CA4B4(((struct Obj05378 *)q)->f0);
}


void func_021C6B38(u8 *p)
{
    void *q = ((struct Obj14046 *)p)->fC;
    func_020456F8(q);
    func_02041B6C(func_02045730(q));
}

void func_021C6B50(void **p,u64 value)
{
    func_0201EFA4(*p,1,(unsigned)(value/100000000ULL),4,2,1);
    func_0201EFA4(*p,2,(unsigned)(value/10000ULL%10000ULL),4,2,1);
    func_0201EFA4(*p,3,(unsigned)(value%10000ULL),4,2,1);
}

void func_021C6BCC(u8 *p,u8 *q,int idx,unsigned heap)
{
    void *base;
    void *obj;
    void *str;
    base=(void *)func_0201283C(((struct Obj10485 *)q)->f4);
    obj=func_0200846C(heap);
    str=func_020457B0(10,heap);
    func_02045924(str,(const u16 *)func_020099D4(base,idx));
    func_020084E4(obj,str);
    func_02045808(str);
    func_0201F02C(((struct Obj00329 *)p)->f0,0,obj);
    func_020307B0(obj);
}

int func_021C6C20(u8 *p,u8 *q,int idx)
{
    void *base;
    unsigned v;
    int result;
    base=(void *)func_0201283C(((struct Obj23069 *)q)->f4);
    result=1;
    v=func_02009864(base,idx,7);
    if(v==0) result=0;
    func_0201EFA4(((struct Obj10483 *)p)->f0,2,v,2,0,1);
    v=func_02009864(base,idx,5);
    func_0201EFA4(((struct Obj10483 *)p)->f0,0,v,4,1,1);
    v=func_02009864(base,idx,6);
    func_0201EFA4(((struct Obj10483 *)p)->f0,1,v,2,0,1);
    return result;
}


void func_021C6C94(char **p, int a)
{
    func_0201EFA4((struct WordSet *)(*p), 0, a, 4, 1, 1);
}

/*
 * calls: 0204B294 returns the handle read in r0; heap is not truncated.
 * note 2026-10-05 (wave D9r lane 131): removed the 6 dead first assignments
 * (`a=0x138;` before `a=0x148;`; `b=0x138;` before `b=0x150;` and 4 more).
 * Game code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void func_021C6CB0(char *p,int heap)
{
    int a,b,c,d,e,f,i;
    char *q;
    void *handle;
    a=0x148;
    b=0x150;
    c=0x158;
    d=0x15c;
    e=0x15c;
    f=0x15c;
    for(i=0;i<2;i++) {
        q=p+i*4;
        *(void **)(q+d)=func_0204B294(((struct Obj02481 *)p)->f138,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&d_021CA800[i],0,heap);
        func_0204B92C(*(void **)(q+e),1);
        func_0204B3DC(*(void **)(q+f),0);
    }
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA810,0,heap);
    ((struct Obj02481 *)p)->f164=handle;
    func_0204B3DC(handle,1);
    handle=func_0204B294(((struct Obj02481 *)p)->f138,((struct Obj02481 *)p)->f148,((struct Obj02481 *)p)->f150,((struct Obj02481 *)p)->f158,&d_021CA818,0,heap);
    ((struct Obj02481 *)p)->f168=handle;
    func_0204B3DC(handle,1);
}

void func_021C6DAC(u8 *p) {int i;func_0204B3B4(((struct Obj00725 *)p)->f168);func_0204B3B4(((struct Obj00725 *)p)->f164);for(i=0;i<2;i++) func_0204B3B4(*(void **)((u32)p+i*4+0x15c));}

void func_021C6DD8(u8 *p,u32 a) {int i; for(i=0;i<2;i++) func_0204B3DC(*(void **)((u32)p+i*4+0x15c),a);}

void func_021C6DF8(u8 *p,u32 a) {int i; for(i=0;i<2;i++) func_0204B92C(*(void **)((u32)p+i*4+0x15c),a);}

void func_021C6E18(u8 *p,int i,u16 a) {func_0204B92C(*(void **)((u32)p+0x15c+i*4),1);func_0204B878(*(void **)((u32)p+0x15c+i*4),a);func_0204B9A0(*(void **)((u32)p+0x15c+i*4));}

void *func_021C6E3C(void *p,void **q,int a,int heap) {TextConfig c;c.heap=heap;c.count=2;c.entries=p;c.mode=1;c.x=32;if(a==1)c.y=18;else c.y=12;c.a=8;c.b=3;return func_02027778((struct TaskMenuTmpl *)(&c),*q);}

int func_021C6E74(u8 *p) {int n;func_02027974(p);if(func_020279E8((struct TaskMenu *)p)==1) {n=func_02027A04(p);func_02027858((struct TaskMenu *)p);return n;}return -1;}

void func_021C6EA0(u8 *p,u8 *q,u8 *r,u16 heap) {((struct Obj14034 *)q)->f0=func_020355C4();func_021C7140((struct P *)p,q,r,heap);}

/*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub func_021C7138). Only the two func_021C7138 relocations
 * lack a witness: the stub is now filed as src/matched/ov/ov128_func_021C7138.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (func_021C7694 with ctx as 2nd argument,
 * func_021CA19C, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched func_021C7694
 * takes one parameter but this caller passes two (p, ctx).
 */
int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(func_020221A4()!=0) q[8]=3;
        break;
    case 2:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        q[8]=3;
        break;
    case 3:
        func_0202EA40(*(void **)(ctx+0x184));
        result=func_021C74C4((int *)p,(int *)q,ctx);
        if(result!=0) {
            if(*(u32 *)p==3) func_021CA3A0((char *)ctx);
            else if(*(u32 *)p==4) func_021CA3C4((char *)ctx);
            else *(u16 *)(p+8)=0;
            q[8]=4;
        }
        break;
    case 4:
        if(*(u32 *)p==3) {
            if(func_0204B98C(*(void **)(ctx+0x164))==1) break;
        } else if(*(u32 *)p==4) {
            if(func_0204B98C(*(void **)(ctx+0x168))==1) break;
        } else {
            if(func_021CA1E0((char *)p)==1) break;
        }
        if(func_021C76BC((int *)p,q)==1) {
            func_021C74E8((u32 *)p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                func_021C7500(p,ctx);
                func_021C7138(p,q,ctx);
                return 1;
            }
        } else {
            func_021C7558(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        func_0202208C(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(func_020221A4()==1) {
            func_021C7138(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,(int *)q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=8;
        break;
    case 8:
        if(func_020221A4()!=0) {
            text=func_0200846C(heap);
            func_020084E4(text,*(void **)(q+0x58));
            func_0201F02C(*(void **)ctx,0,text);
            func_020307B0(text);
            number=func_021CA014(*(void **)(q+0x5C),&result);
            if(result!=0) {
                func_021C6B50((void **)ctx,number);
                func_021C7558(p,ctx,55,heap);
                q[8]=9;
            } else {
                func_021C7558(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(func_021C7674(p,(int *)q,ctx)!=0) {
            *(void **)(p+0x4C)=func_021C6E3C(p+0x30,(void **)(p+0x48),1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(func_021C6E74(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=func_020355C4();
            submission=func_021C6460((char *)q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                func_021C7694(p,ctx);
                func_021CA19C((unsigned int *)p);
                q[8]=3;
            } else {
                func_021C7558(p,ctx,d_021CA4F9[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=func_020355C4();
            func_021C7694(p,ctx);
            func_021CA19C((unsigned int *)p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(func_021C7674(p,(int *)q,ctx)!=0 && func_021CA084((int *)q)==1) {
            func_021C7694(p,ctx);
            func_021CA19C((unsigned int *)p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}

void func_021C7138(u8 *p,u8 *q,u8 *ctx) { func_021C72A0(p,q,ctx); }

void func_021C7140(struct P *p, u8 *a, u8 *ctx, u16 heap)
{
    int i;
    void *buf;
    void *text;
    u32 width;
    func_021C63AC(ctx,(u32 *)((u8 *)p+12),3,4,5,24,20,10,1,0);
    func_021C63AC(ctx,(u32 *)((u8 *)p+28),1,2,19,27,4,10,172,0);
    p->buf=func_020457B0(128,heap);
    buf=func_020457B0(128,heap);
    text=func_020457B0(128,heap);
    func_0201F02C(((struct Obj02482 *)ctx)->f0,0,func_02012944(((struct Obj14034 *)a)->f4));
    for(i=0;i<3;i++) {
        func_02045CAC(((struct Obj02482 *)ctx)->f4,i+1,text);
        func_0201F250(((struct Obj02482 *)ctx)->f0,buf,text);
        width=func_0201D304((struct StrObj *)((u32)buf),((struct Obj02482 *)ctx)->f17C,0);
        func_021B6AE4((u8 *)p+12,(void *)(((struct Obj02482 *)ctx)->f34),(192-width)/2,i*40+8,(u32)buf,((struct Obj02482 *)ctx)->f17C,0x440,0);
    }
    func_021CA4B4(((struct Obj02841 *)p)->fC);
    func_02045808(buf);
    func_02045808(text);
    ((struct Obj02841 *)p)->f14=func_02049EF4(((struct Obj02482 *)ctx)->f8,13,0,(void **)((u8 *)p+24),heap);
    p->text1=func_02045EC0(((struct Obj02482 *)ctx)->f4,66);
    p->color1=0x39e3;
    p->flag1=0;
    p->text2=func_02045EC0(((struct Obj02482 *)ctx)->f4,67);
    p->color2=0x39e3;
    p->flag2=0;
    p->menu=func_02027F60(1,14,((struct Obj02482 *)ctx)->f17C,((struct Obj02482 *)ctx)->f34,heap);
}

void func_021C72A0(u8 *p, u8 *unused, u8 *q)
{
    func_021CA444((char *)q);
    func_021CA458((char *)q,q+12);
    func_02027FD8(((struct Obj04505 *)p)->f48);
    func_02045808(((struct Obj04505 *)p)->f30);
    func_02045808(((struct Obj04505 *)p)->f3C);
    func_02045808(((struct Obj04505 *)p)->f2C);
    func_020452E8(((struct Obj04505 *)p)->f1C);
    func_020452E8(((struct Obj04505 *)p)->fC);
    func_020307B0(((struct Obj04505 *)p)->f14);
}

void func_021C72E4(u8 *p,int *q,u8 *ctx)
{
    u16 *data;
    func_021C6ADC(ctx,ctx+12,0);
    data=*(u16 * *)&((struct Obj14035 *)p)->f18;
    func_02041090(2,(unsigned int)((u8 *)data+12),0,0,data[0]>>3,data[1]>>3);
    func_02040618(2,0,0);
    func_02040618(2,3,0);
    if(*q==0) func_021CA16C(ctx,((struct Obj14035 *)p)->f0);
    else func_02041B6C(2);
}

int func_021C734C(u32 *p, int *q, u8 *ctx)
{
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 3;
        return 1;
    }
    if (func_020362DC() & 1024) {
        func_020061E4(0x556);
        func_021CA154(ctx, *p);
        func_020355D8(0);
        *q = 0;
        *p = 4;
        return 1;
    }
    if (*q == 1) {
        if (func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p, *p);
            func_020355D8(0);
            *q = 0;
        }
        return 0;
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        func_0202EB04(((struct Obj00329 *)ctx)->f184);
        return 1;
    }
    if (func_0203633C() & 64) {
        if (*p != 0) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p - 1, *p);
            --*p;
            return 0;
        }
    } else if (func_0203633C() & 128) {
        if (*p < 2) {
            func_020061E4(0x548);
            func_021CA184(ctx, *p + 1, *p);
            ++*p;
            return 0;
        }
    }
    return 0;
}
