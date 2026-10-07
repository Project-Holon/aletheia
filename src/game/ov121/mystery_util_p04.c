/*
 * file:     mystery_util_p04.c
 * unit:     yes
 * function: func_021D9BC0, func_021D9BE8, func_021D9CA4, func_021D9D4C, func_021D9E04, func_021D9E50, func_021D9F08, func_021D9F24, func_021D9FF8, func_021D9FFC, func_021DA010, func_021DA038, func_021DA148, func_021DA178, func_021DA1BC
 * address:  0x021D9BC0
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203101C 0x0203101C arm
 *   d_021DFBA0 0x021DFBA0 data a1
 *   func_02028470 0x02028470 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0202F038 0x0202F038 thumb
 *   d_021DF78C 0x021DF78C data a4
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_021D99A4 0x021D99A4 thumb ov121
 *   func_021D9B2C 0x021D9B2C thumb ov121
 *   func_021D9B28 0x021D9B28 thumb ov121
 *   func_021D9AC8 0x021D9AC8 thumb ov121
 *   func_021D9A64 0x021D9A64 thumb ov121
 */
#include "../../matched/include/Obj01057.h"
#include "../../matched/include/Obj02180.h"
#include "../../matched/include/Obj00909.h"
#include "../../matched/include/Obj00236.h"
#include "../../matched/include/Obj22877.h"
#include "../../matched/include/Obj22878.h"
#include "../../matched/include/Obj01542.h"
#include "../../matched/include/Obj01731.h"
#include "../../matched/include/Obj06448.h"
#include "../../matched/include/Obj04493.h"
#include "../../matched/include/Obj02469.h"
#include "../../matched/include/Obj04494.h"
#include "../../matched/include/Obj08093.h"

struct Descriptor;
struct Bmp;
struct StrObj;
struct Cfg;
struct CharBuf;
struct Tcbl;
struct U16Vec;
struct Rec3;
struct S02031140;
struct Blk;
struct Ctx;
struct PrintSys;
struct MsgBank;
struct Obj;
struct Slot;
struct Src;
typedef unsigned char u8;

typedef struct { int x; int y; } Pair;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct {u32 word[13];} Config;

typedef signed short s16;

extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern void *func_020457B0(u32, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *, u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_020310C4(struct Tcbl *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void *func_02028590(u32,u32,u32,u32);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,u32,u32,u32,u32,int,void *,u32,u16,u16);
extern void func_0201F73C(void *, int, int, int);
extern void *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_02020D10(u8 *p, u32 v);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_020456F8(struct Descriptor *d);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern void *func_021D99A4(void *,u16,u8,u8,u8,u8,u16,u16,u16);
extern void func_021D9B2C(char *p, u32 a, u32 b, int c);
extern void func_021D9B28(u8 *p, unsigned v);
extern void func_021D9AC8(u8 *p, int a, int b);
extern void func_021D9A64(u8 *p, u16 a, int b, int c);
void func_021D9BC0(const u8 *p,int a,Pair *out);
void func_021D9BE8(u32 mode, const Pair *in, const void *bitmap, void *obj, int a, Pair *out);
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap);
void func_021D9E04(u8 *p);
void func_021D9E50(u8 *p);
void func_021D9F08(u8 *a, int b, int c, int d);
void func_021D9F24(u8 *p,int mode);
unsigned func_021D9FF8(u8 *p);
void func_021D9FFC(u8 *p, int a, int b);
void func_021DA010(u8 *p);
void *func_021DA038(const u8 *p,u16 heap);
void func_021DA148(u8 *p);
int func_021DA178(char *p);
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u16 c,u16 d,u16 e,int f,u16 heap);
extern const char d_021DFBA0[];
extern const Config d_021DF78C;

/*
 * note: const record pointer settles stack-store schedule;
 *       two trailing zero alignment bytes.
 */
void func_021D9BC0(const u8 *p,int a,Pair *out) {
    void *bitmap=func_02045770(((struct Obj01057 *)p)->fC);
    func_021D9BE8(((struct Obj01057 *)p)->f20,(const Pair *)(p+0x18),bitmap,((struct Obj01057 *)p)->f10,a,out);
}

/*
 * extent: two zero padding bytes at 0x021D9CA2.
 * lever: the two-coordinate copy in case 0 is a Pair assignment.
 */
void func_021D9BE8(u32 mode, const Pair *in, const void *bitmap, void *obj, int a, Pair *out)
{
    int x;
    int y;
    switch (mode) {
    case 0:
        *out = *in;
        return;
    case 1:
        x = (u32)func_020437DC(bitmap) / 2;
        y = (u32)func_020437E4(bitmap) / 2;
        x -= func_0201D304(obj, a, 0) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = x + in->x;
        out->y = y + in->y;
        return;
    case 2:
        y = (u32)func_020437E4(bitmap) / 2;
        y -= func_0201D42C(obj, (void *)a) / 2;
        out->x = in->x;
        out->y = y + in->y;
        return;
    case 3:
        x = func_020437DC(bitmap);
        x -= func_0201D304(obj, a, 0);
        if (x < 0) x = 0;
        out->x = x + in->x;
        out->y = in->y;
        break;
    }
}

static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}

/*
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 func_021E8568.
 */
void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = func_020457B0(0x300, heap);
    q = (void *)func_020450F0((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    *(void **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}

/*
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, func_020457B0 second, func_0203101C first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 func_021D9CA4.
 */
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    func_02028470(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = func_020457B0(0x200, heap);
    q = (struct Descriptor *)func_020450F0((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    func_02045334(q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730(q));
    *(struct Tcbl **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}

void func_021D9E04(u8 *p)
{
    if (((struct Obj02180 *)p)->f8) {
        func_0201CE48(((struct Obj02180 *)p)->f8);
        ((struct Obj02180 *)p)->f8 = 0;
    }
    if (((struct Obj02180 *)p)->f3C) {
        func_0202F038(((struct Obj02180 *)p)->f3C);
        ((struct Obj02180 *)p)->f3C = 0;
    }
    if (((struct Obj02180 *)p)->f30) func_02028604((int)(((struct Obj02180 *)p)->f30));
    func_02031140(((struct Obj02180 *)p)->fC);
    func_0201F7A8(((struct Obj02180 *)p)->f10, 0);
    func_020452E8(((struct Obj02180 *)p)->f10);
    func_02045808(((struct Obj02180 *)p)->f14);
    func_020307B0(p);
}

/*
 * extent: two trailing zero padding bytes at 0x021D9F06.
 */
void func_021D9E50(u8 *p)
{
    u32 q;
    switch (((struct Obj00909 *)p)->f28) {
    case 2:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        break;
    case 0:
        q = ((struct Obj00909 *)p)->f24;
        if (p[0x20]) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00909 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj00909 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        ((struct Obj00909 *)p)->f2C = p[0x20] == 0 ? 1 : 0;
        break;
    case 1:
        if (((struct Obj00909 *)p)->f8) {
            if (((struct Obj00909 *)p)->f30)
                func_020286C4((struct Ctx *)(((struct Obj00909 *)p)->f30), (void *)(((struct Obj00909 *)p)->f8), (void *)(((struct Obj00909 *)p)->f10));
            if (func_02028484((struct Blk *)(p + 0x34), (void *)(((struct Obj00909 *)p)->f8)))
                ((struct Obj00909 *)p)->f2C = 1;
        }
        break;
    case 3:
        break;
    }
    func_020310C4((struct Tcbl *)(((struct Obj00909 *)p)->fC));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D9F08(u8 *a, int b, int c, int d)
{
    func_02045CAC((struct MsgBank *)b, c, ((struct Obj00236 *)a)->f14);
    func_021D9F24(a, d);
}

void func_021D9F24(u8 *p,int mode)
{
    u32 q;
    func_02043B5C(func_02045770(((struct Obj00236 *)p)->f10),((struct Obj00236 *)p)->f18);
    if(((struct Obj00236 *)p)->f8) {
        func_0201CE48(((struct Obj00236 *)p)->f8);
        ((struct Obj00236 *)p)->f8=0;
    }
    if(((struct Obj00236 *)p)->f30) {
        func_02028604((int)(((struct Obj00236 *)p)->f30));
        ((struct Obj00236 *)p)->f30=0;
    }
    func_021DA010(p);
    switch(mode) {
    case 2:
        ((struct Obj00236 *)p)->f3C=func_0202EE30((void *)func_020056BC(),((struct Obj00236 *)p)->f10,((struct Obj00236 *)p)->f18,16,((struct Obj00236 *)p)->f1A);
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 0:
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 1:
        func_02028470(p+0x34,2);
        ((struct Obj00236 *)p)->f30=func_02028590(((struct Obj00236 *)p)->f18,1,0,((struct Obj00236 *)p)->f1A);
        ((struct Obj00236 *)p)->f8=func_0201CCE4(((struct Obj00236 *)p)->f10,0,0,*(u32 *)&((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4,func_02012FFC(),((struct Obj00236 *)p)->fC,0,((struct Obj00236 *)p)->f1A,((struct Obj00236 *)p)->f18);
        ((struct Obj00236 *)p)->f28=1;
        break;
    }
    ((struct Obj00236 *)p)->f2C=0;
}

unsigned func_021D9FF8(u8 *p) { return ((struct Obj22877 *)p)->f2C; }


void func_021D9FFC(u8 *p, int a, int b)
{
    func_0201F73C(((struct Obj22878 *)p)->f10, 0, a, b);
}

void func_021DA010(u8 *p) { ((struct Obj00236 *)p)->f2C=1; if(*(u8 * *)&((struct Obj00236 *)p)->f3C) { func_0202F038(*(u8 * *)&((struct Obj00236 *)p)->f3C); *(u32 *)&((struct Obj00236 *)p)->f3C=0; func_02045374(((struct Obj00236 *)p)->f10); func_020409B4(func_02045730(((struct Obj00236 *)p)->f10)); } }

/*
 * lever: const source parameter and the original heap stack argument to 0201F878.
 */
void *func_021DA038(const u8 *p,u16 heap)
{
    u8 *out;
    void *q;
    u32 i;
    Config cfg;
    out=func_02030734(heap,24,0,d_021DFBA0,0x2cb);
    func_02082BCC(out,0,24);
    ((struct Obj01731 *)out)->f4=((struct Obj01542 *)p)->f8;
    ((struct Obj01731 *)out)->f0=(void *)func_020450F0((u8)(((struct Obj01542 *)p)->f1C),(u16)19,(u16)((u8)(17-(u8)(((struct Obj01542 *)p)->f18*2))),(u8)12,(u8)(((struct Obj01542 *)p)->f18*2),((struct Obj01542 *)p)->f1E,1);
    func_0201F73C(((struct Obj01731 *)out)->f0,2,((struct Obj01542 *)p)->f22,(u8)(((struct Obj01542 *)p)->f20));
    q=((struct Obj01731 *)out)->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    ((struct Obj01731 *)out)->f8=((struct Obj01731 *)out)->f0;
    out[12]=0;
    ((struct Obj01731 *)out)->f14=func_0201F81C(((struct Obj01542 *)p)->f18,heap);
    for(i=0;i<((struct Obj01542 *)p)->f18;i++)
        func_0201F878(((struct Obj01731 *)out)->f14,((struct Obj01542 *)p)->f0,*(u32 *)(p+12+i*4),i,(u16)heap);
    cfg=d_021DF78C;
    cfg.word[0]=*(u32 *)&((struct Obj01731 *)out)->f14;
    *(u16 *)((u8 *)&cfg+0x10)=((struct Obj01542 *)p)->f18;
    *(u16 *)((u8 *)&cfg+0x12)=((struct Obj01542 *)p)->f18;
    cfg.word[3]=*(u32 *)&((struct Obj01731 *)out)->f0;
    cfg.word[9]=((struct Obj01542 *)p)->f0;
    cfg.word[10]=(u32)(out+8);
    cfg.word[11]=((struct Obj01542 *)p)->f8;
    cfg.word[12]=((struct Obj01542 *)p)->f4;
    ((struct Obj01731 *)out)->f10=func_0201FF30((struct Src *)(&cfg),0,0,heap);
    func_02020CF8(((struct Obj01731 *)out)->f10,heap);
    func_02020D10(((struct Obj01731 *)out)->f10,0);
    return out;
}

void func_021DA148(u8 *p) { func_0202020C(((struct Obj06448 *)p)->f10,0,0); func_0201F868(((struct Obj06448 *)p)->f14); func_0201F7A8(((struct Obj06448 *)p)->f0,0); func_020456F8(((struct Obj06448 *)p)->f0); func_020452E8(((struct Obj06448 *)p)->f0); func_020307B0(p); }

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
int func_021DA178(char *p)
{
    u32 q = ((struct Obj04493 *)p)->f4;
    int r;
    if (((struct Obj04493 *)p)->fC) {
        if (func_0201C6C4((struct PrintSys *)q,(void *)((u32)func_02045770((struct Descriptor *)((struct Obj04493 *)p)->f8))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj04493 *)p)->f8);
            ((struct Obj04493 *)p)->fC=0;
        }
    }
    r=func_020200CC(((struct Obj04493 *)p)->f10);
    if (r == -2) r=func_02020350(((struct Obj04493 *)p)->f10,2)-1;
    return r;
}

/*
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 */
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u16 c,u16 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    func_02082BCC(out,0,size);
    *(const char * *)&((struct Obj04494 *)out)->f0=desc;
    ((struct Obj04494 *)out)->f4=n;
    ((struct Obj04494 *)out)->f8=f;
    ((struct Obj04494 *)out)->fC=e;
    for(i=0;i<((struct Obj04494 *)out)->f4;i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=func_021D99A4(a,b,((struct Obj02469 *)v)->f0,((struct Obj02469 *)v)->f1,((struct Obj02469 *)v)->f2,((struct Obj02469 *)v)->f3,c,d,heap);
        ((struct Obj08093 *)slot)->f10=q;
        func_021D9B2C(q,((struct Obj02469 *)v)->f10,((struct Obj02469 *)v)->f12,((struct Obj02469 *)v)->fC);
        func_021D9B28(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f14);
        if(((struct Obj02469 *)v)->f8) func_021D9AC8(((struct Obj08093 *)slot)->f10,((struct Obj02469 *)v)->f8,((struct Obj04494 *)out)->f8);
        else func_021D9A64(((struct Obj08093 *)slot)->f10,e,((struct Obj02469 *)v)->f4,((struct Obj04494 *)out)->f8);
    }
    return out;
}
