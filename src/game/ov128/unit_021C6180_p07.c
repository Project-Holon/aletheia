/*
 * file:     unit_021C6180_p07.c
 * unit:     yes
 * function: func_021C76F8, func_021C7ACC, func_021C7D48
 * address:  0x021C76F8
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
 *   func_021C76F0 0x021C76F0 thumb ov128
 *   func_021C6520 0x021C6520 thumb ov128
 *   func_021C7E0C 0x021C7E0C thumb ov128
 *   func_021C81C8 0x021C81C8 thumb ov128
 *   func_021C8668 0x021C8668 thumb ov128
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021C81FC 0x021C81FC thumb ov128
 *   func_021C8240 0x021C8240 thumb ov128
 *   func_021C8354 0x021C8354 thumb ov128
 *   func_021CA320 0x021CA320 thumb ov128
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C651C 0x021C651C thumb ov128
 *   func_021C83B0 0x021C83B0 thumb ov128
 *   func_021C873C 0x021C873C thumb ov128
 *   func_021C83DC 0x021C83DC thumb ov128
 *   func_021C8470 0x021C8470 thumb ov128
 *   func_021C7E48 0x021C7E48 thumb ov128
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C6514 0x021C6514 thumb ov128
 *   func_021C8548 0x021C8548 thumb ov128
 *   func_021C8574 0x021C8574 thumb ov128
 *   func_021C6E74 0x021C6E74 thumb ov128
 *   func_021C875C 0x021C875C thumb ov128
 *   func_021C87B0 0x021C87B0 thumb ov128
 *   func_021C8850 0x021C8850 thumb ov128
 *   func_021C85A4 0x021C85A4 thumb ov128
 *   func_021C8880 0x021C8880 thumb ov128
 *   func_021C84E8 0x021C84E8 thumb ov128
 *   func_021CA084 0x021CA084 thumb ov128
 *   func_0202EA40 0x0202EA40 thumb
 *   func_0202EB04 0x0202EB04 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_020099D4 0x020099D4 thumb
 *   func_02009A00 0x02009A00 thumb
 *   func_02009A74 0x02009A74 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_021C88AC 0x021C88AC thumb ov128
 *   func_021C3EE0 0x021C3EE0 thumb ov127
 *   func_021C4044 0x021C4044 thumb ov127
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021CA564 0x021CA564 data a4
 *   d_021CA688 0x021CA688 data a4
 *   d_021CA650 0x021CA650 data a4
 *   d_021CA638 0x021CA638 data a4
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_021C4080 0x021C4080 thumb ov127
 *   func_021C3F80 0x021C3F80 thumb ov127
 *   func_021C88BC 0x021C88BC thumb ov128
 */
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj00298.h"
#include "../../matched/include/Obj03809.h"
#include "../../matched/include/Obj03281.h"

struct BigObj;
struct CodeIn;
struct Sub020097BCObj;
struct Row;
struct Actor;
struct Sub020097BCEnt;
struct MsgBank;
struct Obj;
struct R;
struct U16Vec;
struct Descriptor;
struct TaskMenuState;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned char u8;

typedef signed char s8;

typedef signed int     s32;

typedef struct { u16 a, b, c, d; } Rect;

typedef struct { s16 x, y, z; } V3;

typedef struct { u32 a, b; } W2;

extern void func_021C76F0(u8 *,u8 *,u8 *,u32);
extern void func_021C6520(char *);
extern void func_021C7E0C(u8 *,u8 *,u8 *,u16);
extern int func_021C81C8(s16 *p, u8 *q, u8 *r);
extern void func_021C8668(u8 *,u8 *,int);
extern void func_021CA40C(char *p, int n);
extern void func_021C81FC(u8 *,void *,u8 *,u16);
extern int func_021C8240(u8 *,u8 *,u8 *,u16),func_021C8354(u8 *,u8 *);
extern int func_021CA320(char *),func_021C87A0(s16 *);
extern void func_021C651C(char *,int),func_021C6514(char *,int);
extern void func_021C83B0(s16 *p, u8 *q, u8 *r, u16 heap);
extern int func_021C873C(void *p, int *state, u8 *q);
extern void func_021C83DC(u8 *,u8 *,void *,int);
extern int func_021C8470(u8 *,int *,void *);
extern void func_021C7E48(u8 *p, void *q, u8 *r);
extern void func_021C6438(u8 *,u8,u8);
extern void func_021C8548(s16 *p, u8 *q, u8 *r, u16 heap);
extern int func_021C8574(u8 *p, int *q, u8 *r, int heap);
extern int func_021C6E74(u8 *p);
extern void func_021C875C(char *p, char *q);
extern void func_021C87B0(u8 *,u8 *);
extern int func_021C8850(u8 *,u8 *);
extern void func_021C85A4(u8 *,u8 *,u8 *,int,int,int,u16),func_021C8880(u8 *,u8 *);
extern int func_021C84E8(u8 *,u8 *,u8 *,int);
extern int func_021CA084(int *p);
extern s32 func_0202EA40(struct Row *p);
extern void func_0202EB04(struct CodeIn *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCEnt *func_020099D4(struct Sub020097BCObj *obj, int i);
extern void func_02009A00(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02009A74(struct Sub020097BCObj *obj, u32 i);
extern u8 func_020355C4(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
extern void func_021C88AC(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
extern void *func_021C3EE0(void *, void *, u32, u32);
extern void func_021C4044(u8 *, int, int, int, int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_021CA444(char *);
extern void func_021CA458(char *p, void *q);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021C4080(u8 *p);
extern void func_021C3F80(u8 *);
extern void func_021C88BC(void *a0, void *a1);
int func_021C76F8(u8 *p,u8 *q,u8 *ctx,u16 heap);
void func_021C7AC4(u8 *p,u8 *q,u8 *ctx);
void func_021C7ACC(u8 *p, void *unused, u8 *ctx, u16 heap);
void func_021C7D48(u8 *p, void *unused, u8 *a);
extern const V3 d_021CA564[];
extern const W2 d_021CA688[];
extern const Rect d_021CA650;
extern const Rect d_021CA638;

/*
 * extent: 021C7AC4 is the eight-byte tail stub to 021C7D48.
 * calls: Entry r0-r3 stay live into argumentless switch-arm calls.
 * Original explicit r1=ctx on 021C87B0/8850/8880 is retained even
 * where the callee reads only r0. All signed indexed reads are modular.
 */
int func_021C76F8(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    int idx;
    u32 base;
    switch(q[8]) {
    case 0:
        *(u16 *)&((struct Obj00179 *)p)->f0=0; ((struct Obj00179 *)p)->f2=0; *(u16 *)&((struct Obj00179 *)p)->f4=0; ((struct Obj00179 *)p)->f6=0;
    case 1:
        func_021C76F0(p,q,ctx,52);
        func_021C6520((char *)q);
        func_021C7E0C(p,q,ctx,heap);
        q[8]=2;
        break;
    case 2:
        func_0202EA40(((struct Obj03809 *)ctx)->f184);
        func_0202EA40(((struct Obj03809 *)ctx)->f188);
        switch(func_021C81C8((s16 *)p,q,ctx)) {
        case 0: break;
        case 1:
            func_021C8668(p,q,2);
            func_021CA40C((char *)p,((struct Obj00179 *)p)->f0);
            func_0202EB04(((struct Obj03809 *)ctx)->f188);
            func_0202EA40(((struct Obj03809 *)ctx)->f188);
            break;
        case 2:
            func_021C8668(p,q,3);
            func_021CA40C((char *)p,((struct Obj00179 *)p)->f0);
            func_0202EB04(((struct Obj03809 *)ctx)->f188);
            func_0202EA40(((struct Obj03809 *)ctx)->f188);
            break;
        case 3: q[8]=25; break;
        case 4: q[8]=26; break;
        case 5: q[8]=6; break;
        }
        break;
    case 3: func_021C81FC(p,q,ctx,heap); q[8]=4; break;
    case 4: if(func_021C8240(p,q,ctx,heap)==1) q[8]=5; break;
    case 5: if(func_021C8354(p,ctx)==1) q[8]=2; break;
    case 6:
        if(func_021CA320((char *)p)!=1) {
            func_021C651C((char *)q,func_021C87A0((s16 *)p));
            func_021C83B0((s16 *)p,q,ctx,heap); q[8]=7;
        }
        break;
    case 7:
        if(func_021C873C(p,(int *)q,ctx)==1) {func_021C83DC(p,q,ctx,heap);q[8]=8;}
        break;
    case 8: q[8]=func_021C8470(p,(int *)q,ctx); break;
    case 9: ((struct Obj00179 *)p)->f19C=8; q[8]=10; break;
    case 10:
        (((struct Obj00179 *)p)->f19C)--;
        if(((struct Obj00179 *)p)->f19C<=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,4,0);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 11:
        ((struct Obj00179 *)p)->f0=((struct Obj00298 *)q)->fB/8;
        ((struct Obj00179 *)p)->f4=((struct Obj00298 *)q)->fB%8;
        q[8]=1;
        break;
    case 12:
        func_0202208C(0,0,0,0,6,1,heap);
        idx=func_021C87A0((s16 *)p);
        base=func_0201283C(((struct Obj00298 *)q)->f4);
        func_021C6514((char *)q,(int)func_020099D4((void *)base,*(u8 *)((u32)q+(u32)idx+24)));
        q[8]=13;
        break;
    case 13:
        if(func_020221A4()!=0) {
            func_021C7E48(p,q,ctx);func_021C6438(q,2,4);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 14:
        idx=func_021C87A0((s16 *)p);
        base=func_0201283C(((struct Obj00298 *)q)->f4);
        func_02009A00((void *)base,*(u8 *)((u32)q+(u32)idx+24),((struct Obj00298 *)q)->f58);
    case 15:
        func_021C76F0(p,q,ctx,52);func_021C7E0C(p,q,ctx,heap);
        func_0202208C(0,1,1,0,6,1,heap);q[8]=16;
        break;
    case 16: if(func_020221A4()!=0) q[8]=2; break;
    case 17: func_021C8548((s16 *)p,q,ctx,heap);q[8]=18;break;
    case 18: if(func_021C8574(p,(int *)q,ctx,heap)==1) q[8]=19;break;
    case 19:
        switch(func_021C6E74(((struct Obj00179 *)p)->f194)) {
        case 0:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=20;break;
        case 1:
            ((struct Obj00298 *)q)->f0=func_020355C4();func_021C875C((char *)p,(char *)ctx);q[8]=2;break;
        }
        break;
    case 20: func_021C87B0(p,ctx);q[8]=21;break;
    case 21:
        if(func_021C8850(p,ctx)==1) {
            base=func_0201283C(((struct Obj00298 *)q)->f4);
            idx=func_021C87A0((s16 *)p);
            func_02009A74((void *)base,*(u8 *)((u32)q+(u32)idx+24));
            func_021C6520((char *)q);
            func_021C85A4(p,q,ctx,((struct Obj00179 *)p)->f0,((struct Obj00179 *)p)->f4,0,heap);q[8]=22;
        }
        break;
    case 22: func_021C8880(p,ctx);q[8]=2;break;
    case 23:
        if(func_021C84E8(p,q,ctx,heap)==1) q[8]=24;
        else q[8]=2;
        break;
    case 24:
        if(func_021C873C(p,(int *)q,ctx)!=0 && func_021CA084((int *)q)==1) {q[8]=2;func_021C875C((char *)p,(char *)ctx);}
        break;
    case 25:
        if(func_0204B98C(((struct Obj03809 *)ctx)->f164)!=1) {
            func_021C7E48(p,q,ctx);func_021C6438(q,0,2);func_021C7AC4(p,q,ctx);return 1;
        }
        break;
    case 26: if(func_0204B98C(((struct Obj03809 *)ctx)->f168)!=1) q[8]=27;break;
    case 27: func_0202208C(0,0,0,0,6,1,heap);q[8]=28;break;
    case 28:
        if(func_020221A4()!=0) {func_021C6438(q,6,0);func_021C7AC4(p,q,ctx);return 1;}
        break;
    }
    return 0;
}

void func_021C7AC4(u8 *p,u8 *q,u8 *ctx) {func_021C7D48(p,q,ctx);}

static inline int iabs(int v)
{
    return v < 0 ? -v : v;
}

void func_021C7ACC(u8 *p, void *unused, u8 *ctx, u16 heap)
{
    int i;
    int j;
    Rect r1;
    Rect r2;
    for (i = 0; i < 2; i++) {
        func_021C63AC(ctx, (u32 *)(p + 0xf0 + i * 8), 3,
            (u8)(iabs(d_021CA564[i].x) + 4), (u8)(iabs(d_021CA564[i].y) + 4), 0x1a, 0x11, 0xa, 0, 0);
    }
    for (j = 0; j < 3; j++)
        func_021C88AC((u16 *)(p + 12 + j * 0x4c), (u16 *)ctx, (u16 *)((const void *)&d_021CA564[j]), 0, heap);
    *(u8 **)(p + 0x14) = p + 0xf0;
    *(u8 **)(p + 0xac) = p + 0xf8;
    *(u8 **)(p + 0x60) = p + 0xf8;
    *(void **)(p + 0x104) = func_021C3EE0(*(void **)(ctx + 0x13c), 0, 0x10, heap);
    func_021C4044(*(u8 **)(p + 0x104), 0, 2, 0xe0, heap);
    for (i = 0; i < 4; i++) {
        const W2 *e = &d_021CA688[i];
        *(void **)(p + i * 12 + 0x118) = func_02045EC0(*(struct MsgBank **)(ctx + 4), d_021CA688[i].a);
        *(u16 *)(p + i * 12 + 0x11c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x120) = 0;
        *(void **)(p + i * 12 + 0x148) = func_02045EC0(*(struct MsgBank **)(ctx + 4), e[4].a);
        *(u16 *)(p + i * 12 + 0x14c) = 0x39e3;
        *(u32 *)(p + i * 12 + 0x150) = 0;
    }
    *(u32 *)(p + 0x144) = 1;
    *(u32 *)(p + 0x174) = 1;
    *(void **)(p + 0x178) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x42);
    *(u16 *)(p + 0x17c) = 0x39e3;
    *(u32 *)(p + 0x180) = 0;
    *(void **)(p + 0x184) = func_02045EC0(*(struct MsgBank **)(ctx + 4), 0x43);
    *(u16 *)(p + 0x188) = 0x39e3;
    *(u32 *)(p + 0x18c) = 0;
    *(struct R **)(p + 0x190) = func_02027F60(1, 14, *(u32 *)(ctx + 0x17c), *(u32 *)(ctx + 0x34), heap);
    func_021C63AC(ctx, (u32 *)(p + 0x108), 1, 2, 1, 0x1b, 4, 0xa, 0, 0xf);
    *(struct U16Vec **)(p + 0x110) = func_020457B0(0x80, heap);
    r1 = d_021CA650;
    *(struct Obj **)(p + 0x1a0) = func_0204B294(*(void **)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r1, 0, heap);
    func_0204B3DC(*(struct Obj **)(p + 0x1a0), 0);
    r2 = d_021CA638;
    *(struct Obj **)(p + 0x1a4) = func_0204B294(*(void **)(ctx + 0x138), *(u32 *)(ctx + 0x144), *(u32 *)(ctx + 0x14c), *(u32 *)(ctx + 0x154), &r2, 0, heap);
}

void func_021C7D48(u8 *p, void *unused, u8 *a)
{
    int i;
    int offset;
    func_021CA444((char *)a);
    func_021CA458((char *)a,a + 12);
    func_0204B3B4(((struct Obj03281 *)p)->f1A4);
    func_0204B3B4(((struct Obj03281 *)p)->f1A0);
    func_020452E8(((struct Obj03281 *)p)->f108);
    func_02045808(((struct Obj03281 *)p)->f110);
    func_02027FD8(((struct Obj03281 *)p)->f190);
    func_02045808(((struct Obj03281 *)p)->f178);
    func_02045808(((struct Obj03281 *)p)->f184);
    offset=0x1a4;
    i=0;
    offset=0x118;
    for (; i < 4; i++) {
        func_02045808(*(void **)(p + i * 12 + offset));
        func_02045808(*(void **)(p + i * 12 + 0x148));
    }
    func_021C4080(((struct Obj03281 *)p)->f104);
    func_021C3F80(*(u8 * *)&((struct Obj03281 *)p)->f104);
    for(i=0;i<3;i++) func_021C88BC(p + 12 + i * 0x4c,a);
    for(i=0;i<2;i++) func_020452E8(*(void **)(p + i * 8 + 0xf0));
}
