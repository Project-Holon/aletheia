/*
 * file:     field_palace_sys_p05.c
 * unit:     yes
 * function: func_021D1A54, func_021D1A74, func_021D1A9C, func_021D1AB0, func_021D1AEC, func_021D1B2C, func_021D1B8C, func_021D1BD8, func_021D1C24, func_021D1C8C, func_021D1F48, func_021D1F50
 * address:  0x021D1A54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159104  0x02159104  thumb  ov010
 *   func_0215910C  0x0215910C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D1884  0x021D1884  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D1894  0x021D1894  thumb  ov021
 *   func_021D18E0  0x021D18E0  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   d_021DD608     0x021DD608  data  a4
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02006984  0x02006984  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006CBC  0x02006CBC  thumb
 *   func_02006D44  0x02006D44  thumb
 *   func_02006D64  0x02006D64  thumb
 *   func_02006D94  0x02006D94  thumb
 *   func_02006DD8  0x02006DD8  thumb
 *   func_02006E18  0x02006E18  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_020295A4  0x020295A4  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_02034F84  0x02034F84  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190F9C  0x02190F9C  thumb  ov021
 *   func_021D1F64  0x021D1F64  thumb  ov021
 *   func_021D2040  0x021D2040  thumb  ov021
 *   func_021D20BC  0x021D20BC  thumb  ov021
 *   func_021D2124  0x021D2124  thumb  ov021
 *   sub_020056BC   0x020056BC  thumb
 *   sub_02006BD0   0x02006BD0  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 */
#include "../../matched/include/Obj18375.h"
#include "../../matched/include/Obj18377.h"

struct Desc;
struct Obj;
struct Big;
struct Ctx;
struct Sub02007AC8Entry;
struct Obj00020;
struct BigObj;
struct P;
struct Fx;
struct Obj2;
struct Evt;
struct Handle;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    void *x00;      /* 0x00 */
    void *x04;      /* 0x04 */
    u8 pad08[0xC];
    void *x14;      /* 0x14 */
    void *x18;      /* 0x18 */
    void *x1C;      /* 0x1C */
    void *x20;      /* 0x20 */
    void *x24;      /* 0x24 */
    void *x28;      /* 0x28 */
    void *x2C;      /* 0x2C */
    u32 pad30;
    void *x34;      /* 0x34 */
    u8 pad38[0x18];
    void *x50;      /* 0x50 */
    int x54;        /* 0x54 */
} Work;

extern void *func_0215A5F4(void *p);
extern u32 func_0215910C(void *a);
extern void func_021D1884(u8 *p);
extern void func_02159104(u8 *p, u32 v);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_021D1894(u8 *p, u32 n);
extern u32 func_021D18E0(u8 *p, u32 a1, u32 a2, u32 a3);
extern void *func_0215A5DC(void *a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215897C(void *vm, void *task);
extern int func_021A0ED4(u32 a);
extern int func_021A0F30(u32 a, u32 b);
extern int func_02158F58(int a0);
extern u32 func_02188CCC(u8 *p);
extern void func_02159144(int n);
extern void func_02159168(int n);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021D20BC(u32 *w);
extern int func_02007B50(void *);
extern void func_02190E74(u32 *p, u32 b, u32 c, u32 d);
extern u32 func_02190EF0(u32 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern void func_02190F7C(struct P *p);
extern void func_02034F84(u32);
extern void *func_02006CBC(u32);
extern void *sub_020056BC(void *);
extern void *func_02190F9C(void **p);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_02006D64(u32);
extern u32 func_02006D94(void);
extern void func_0202F038(u8 *p);
extern u8 *func_020295A4(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02006DD8(void *a, u32 b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
extern void func_02006D44(void);
extern void func_02034FB8(u32);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_02006E18(void *);
extern int func_021D2040(u8 *w);
extern void func_02006CAC(void **out);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 sub_02006BD0(u32 i);
extern void func_021D2124(Work *);
extern u32 func_0201ED04(struct WordSet *p);
extern int func_02190E40(u32 a);
extern u32 func_021904C8(struct Rec *a0);
extern int func_021D1F64(u32 a);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0216D9A0(void *);
extern void *func_02188C7C(unsigned char *p);
int func_021D1A54(u32 a, u32 b);
int func_021D1A74(u32 a, u32 b);
int func_021D1A9C(u32 a, u32 b, u32 c, u32 d);
int func_021D1AB0(u32 a, u32 b);
int func_021D1AEC(int a, int *seq, u32 *c);
int func_021D1B2C(u32 a, u32 b);
int func_021D1B8C(u32 a, u32 b);
int func_021D1BD8(u32 *a, int *seq);
u32 func_021D1C24(u32 a, u32 b, u32 c);
int func_021D1C8C(void *proc, int *seq, Work *w);
void func_021D1F48(void *unused, int *done);
int func_021D1F50(u32 a);
extern u32 d_021DD608[];


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021D1A54(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);

    func_021D1884((u8 *)func_0215910C(x));
    func_02159104(x, 0);
    return 0;
}


int func_021D1A74(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u32 k = func_02159B10((void *)a, (void *)b);

    func_021D1894((u8 *)func_0215910C(x), k);
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1A9C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021D18E0((u8 *)(((struct Obj18375 *)((u8 *)(c)))->f0), b, c, d) == 1) {
    return 1;
}
return 0;
}


int func_021D1AB0(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *task = func_020122C0((void *)func_0215A5DC((void *)b), 0, func_021D1A9C, 4);
    u32 *w = func_020124E8(task);

    *w = func_0215910C(x);
    func_0215897C(x, task);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D1AEC(int a, int *seq, u32 *c)
{
    switch (*seq) {
    case 0:
        if (func_021A0ED4(c[0])) {
            func_021A0F30(c[0], c[1]);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(c[0])) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D1B2C(u32 a, u32 b)
{
    u32 r4, r5;
    u32 *e;
    void *r7;
    void *r6;
    u32 *p;

    r7 = func_0215A5F4((void *)b);
    e = (u32 *)func_02158F58((int)r7);
    r5 = func_02159B10((void *)a, (void *)b);
    r4 = func_02188CCC((u8 *)e[1]);
    r6 = func_0215A5DC((void *)b);
    r6 = func_020122C0(r6, 0, func_021D1AEC, 8);
    p = func_020124E8(r6);
    r5 = d_021DD608[r5];
    p[0] = r4;
    p[1] = r5;
    func_0215897C(r7, r6);
    func_02159144(8);
    return 1;
}


int func_021D1B8C(u32 a, u32 b)
{
    u32 r4;
    void *r5;
    void *r6;
    u32 *p;

    r5 = func_0215A5F4((void *)b);
    r4 = func_02188CCC((u8 *)(((u32 *)func_02158F58((int)r5))[1]));
    r6 = func_0215A5DC((void *)b);
    r6 = func_020122C0(r6, 0, func_021D1AEC, 8);
    p = func_020124E8(r6);
    p[0] = r4;
    p[1] = 0;
    func_0215897C(r5, r6);
    func_02159168(8);
    return 1;
}


int func_021D1BD8(u32 *a, int *seq)
{
    u32 r4;

    r4 = func_02188CCC((u8 *)(((u32 *)func_02158F58(a[2]))[1]));
    switch (*seq) {
    case 0:
        if (func_021A0ED4(r4)) {
            func_021A0F30(r4, 0);
            func_02159168(8);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(r4)) {
            return 1;
        }
        break;
    }
    return 0;
}


u32 func_021D1C24(u32 a, u32 b, u32 c)
{
    u32 r;
    u32 *p;

    r = (u32)func_020122C0((void *)a, 0, func_021D1C8C, 0x58);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x58);
    p[1] = a;
    p[2] = (u32)func_020120F4((const struct Ctx *)a);
    p[0] = (u32)func_02007B44(func_02012EBC((struct Big *)p[2]));
    p[3] = b;
    p[4] = (u32)func_02188CB4((void *)b);
    p[5] = (u32)func_0201AB28(func_02012934((void *)p[2]), c);
    p[7] = func_02188C54((u8 *)p[3]);
    *((u8 *)p + 0x4e) = c;
    p[0x15] = 0;
    return r;
}


/*
 * Fifteen-state field sequence: sets up handles, runs fades and a message task, then tears down.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1C8C(void *proc, int *seq, Work *w)
{
    void *a;
    void *t;
    u32 buf;

    switch (*seq) {
    case 0:
        func_021D1F50((u32)w);
        *seq = 1;
        break;
    case 1:
        w->x18 = t = (void *)func_021904B0((u32)w->x1C, 88);
        w->x20 = func_02190F64(w->x1C, (u32)t);
        w->x28 = func_0201EC64(21);
        w->x2C = func_020457B0(0x400, 21);
        func_021D20BC((u32 *)w);
        if (func_02007B50(w->x00) == 1) {
            func_02190E74(w->x20, 0, 0, 0);
            *seq = 2;
        } else {
            func_02190E74(w->x20, 0, 0, 6);
            *seq = 4;
        }
        break;
    case 2:
        if (func_02190EF0(w->x20) == 1) {
            w->x24 = func_02190BE4(w->x1C, 0);
            *seq = 3;
        }
        break;
    case 3:
        switch (func_02190C78(w->x24)) {
        case 0:
            func_021909BC((void *)w->x24);
            func_02190F7C(w->x20);
            func_02190E74(w->x20, 0, 0, 6);
            *seq = 4;
            break;
        case 1:
            func_021909BC((void *)w->x24);
            *seq = 13;
            break;
        }
        break;
    case 4:
        if (func_02190EF0(w->x20) == 1) {
            func_02034F84(8);
            a = sub_020056BC(func_02006CBC(21));
            w->x34 = func_0202EE30(a, func_02190F9C(w->x20), 15, 16, 21);
            *seq = 5;
        }
        break;
    case 5:
        func_02006D64(2);
        if (func_02006D94() == 1) {
            func_0202F038(w->x34);
            func_02190F7C(w->x20);
            func_02190E74(w->x20, 0, 0, 1);
            func_02012374(proc, (struct Evt **)func_020295A4(w->x04, 6));
            *seq = 6;
        }
        break;
    case 6:
        if (func_02190EF0(w->x20) == 1) {
            if (func_02006DD8(func_021D1F48, (u32)(&w->x54)) == 0) {
                *seq = 7;
            } else {
                a = func_02045EC0(w->x18, 3);
                func_0201EEF4(w->x28, 0, w->x14);
                func_0201F250(w->x28, w->x2C, a);
                func_02045808(a);
                func_02190F7C(w->x20);
                func_02190EB8(w->x20, 0, 0, (u32)w->x2C);
                func_02006D44();
                func_02034FB8(8);
                func_02012374(proc, func_02029620(w->x04, 0, 30));
                *seq = 12;
            }
        }
        break;
    case 7:
        if (w->x54 == 1) {
            func_02006E18(w->x00);
            func_02006D44();
            func_02034FB8(8);
            func_02012374(proc, func_02029620(w->x04, 0, 30));
            *seq = 8;
        }
        break;
    case 8:
        if (func_021D2040((u8 *)w) == 0) {
            a = func_02045EC0(w->x18, 2);
            func_0201EEF4(w->x28, 0, w->x14);
            func_0201F250(w->x28, w->x2C, a);
            func_02045808(a);
            func_02190F7C(w->x20);
            func_02190EB8(w->x20, 0, 0, (u32)w->x2C);
            *seq = 9;
        }
        break;
    case 9:
        if (func_02190EF0(w->x20) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        func_02006CAC((void **)(&buf));
        w->x50 = (void *)func_02006984(0x1B9, 0, 64, 0, 0, 0, 0, (u32)(&buf));
        *seq = 11;
        break;
    case 11:
        if (sub_02006BD0((u32)w->x50) == 0) {
            *seq = 13;
        }
        break;
    case 12:
        if (func_02190EF0(w->x20) == 1) {
            *seq = 13;
        }
        break;
    case 13:
        func_021D2124(w);
        func_02045808(w->x2C);
        func_0201ED04(w->x28);
        func_02190E40((u32)w->x20);
        func_021904C8(w->x18);
        *seq = 14;
        break;
    case 14:
        func_021D1F64((u32)w);
        return 1;
    }
    return 0;
}

/*
 * Completion callback: writes 1 through its second argument.  Referenced
 * only by address from func_021D1C8C's literal pool.
 *
 * Addresses are Black-image addresses.
 */
void func_021D1F48(void *unused, int *done)
{
    *done = 1;
}


int func_021D1F50(u32 a)
{
return func_0216D9A0(func_02188C7C(func_0201210C((const struct Ctx *)((struct Obj18377 *)((u8 *)(a)))->f4)));
}
