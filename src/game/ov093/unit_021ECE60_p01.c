/*
 * file:     unit_021ECE60_p01.c
 * unit:     yes
 * function: func_021ECE60, func_021ECEB8, func_021ECF50, func_021ECF68, func_021ED118, func_021ED158, func_021ED1B0, func_021ED208, func_021ED250, func_021ED268, func_021ED280, func_021ED294, func_021ED2BC, func_021ED2D0, func_021ED304, func_021ED318
 * address:  0x021ECE60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_021B85DC  0x021B85DC  thumb  ov093
 *   func_0201CD10  0x0201CD10  thumb
 *   func_0201CE0C  0x0201CE0C  thumb
 *   func_021ED7C8  0x021ED7C8  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_0201CE20  0x0201CE20  thumb  arm9
 *   func_0201CED4  0x0201CED4  thumb  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 *   func_0201CE30  0x0201CE30  thumb  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_02035C38  0x02035C38  arm  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_02035C60  0x02035C60  arm  arm9
 *   func_0201DD68  0x0201DD68  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb  arm9
 *   func_0201CE38  0x0201CE38  thumb  arm9
 *   func_02006254  0x02006254  thumb  arm9
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_021ED798  0x021ED798  thumb  ov093
 *   func_021F7B2C  0x021F7B2C  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_02006210  0x02006210  thumb
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 *   func_021F8118  0x021F8118  thumb  ov094
 *   func_021F8180  0x021F8180  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7CE4  0x021F7CE4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021ED384  0x021ED384  thumb  ov093
 */
#include "../../matched/include/Obj02796.h"
#include "../../matched/include/Obj00027.h"
#include "../../matched/include/Obj06290.h"
#include "../../matched/include/Obj04385.h"
#include "../../matched/include/Obj13565.h"
#include "../../matched/include/Obj21589.h"
#include "../../matched/include/Obj21590.h"
#include "../../matched/include/Obj13566.h"
#include "../../matched/include/Obj05231.h"
#include "../../matched/include/Obj12172.h"
#include "../../matched/include/Obj21591.h"

struct CharBuf;
struct Descriptor;
struct Rec;
struct S;
struct Rec3;
struct E;
struct Work;
struct S02030FB4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021ECE60;

typedef unsigned int   u32;

typedef short s16_021ECEB8;

typedef int s32_021ECEB8;

typedef signed char s8;

typedef signed short s16_021ECF50;

typedef signed int s32_021ECF50;

struct T_021ECF68 {
    u8 pad0[0x30];
    void *h30;
    u8 pad34[0x100];
    u8 **owner;
    u8 pad138[6];
    u8 b13e;
    u8 b13f;
    u8 pad140;
    u8 b141;
    u8 pad142[2];
    int i144;
    u16 h148;
    u16 h14a;
    u16 h14c;
    u8 pad14e[6];
    u8 s154[1];
};

typedef signed int     s32_021ECF68;

struct T_021ED118 {
    u16 h;
    int a;
    int b;
    u8 e;
    u8 f;
    u32 d;
};

typedef int (*Cb)(void *, u32);

extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *x, s16_021ECE60 y, s16_021ECE60 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern int func_021B85DC(unsigned char *p);
extern struct Rec *func_0201CD10(u32 a0, s16_021ECEB8 a1, s16_021ECEB8 a2, u32 a3, u32 a4, s32_021ECEB8 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_0201CE0C(void *p);
extern void func_021ED7C8(struct S *, int);
extern int func_021ED814(struct S *);
extern u8 func_021B86C0(u8 **);
extern void func_0201CE20(void *);
extern u32 func_0201CED4(struct Rec *p);
extern void func_0201CE8C(struct Rec *p, s32_021ECF68 v);
extern signed char func_02013080(u32 idx);
extern void func_0201CEB8(struct Rec *p);
extern u32 func_0201CE30(void *p);
extern u32 func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201DD68(void);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern int func_02006254(u32 a);
extern void func_020061E4(u32 a);
extern void func_021ED798(struct S *s);
extern void func_021F7B2C(u8 *);
extern int func_021F7EB4(void);
extern void func_02006210(void);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F80FC(u32 a, u32 b);
extern void func_021F7C2C(int a, int b);
extern void func_021F8118(u32 a, u32 b);
extern int func_021F8180(void);
extern void func_021F80E4(u32);
extern void func_021F7CE4(int);
extern void func_021F7F04(int);
extern void *func_021D5864(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021EDA04(struct E *e);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021ED384(u32 a, u8 *t);
void func_021ECE60(u8 *a, int b);
void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c);
u32 func_021ECF50(u8 *p);
int func_021ECF68(struct T_021ECF68 *p);
void func_021ED118(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f);
int func_021ED158(int *st, u8 *b);
int func_021ED1B0(char *p);
void func_021ED208(char *p, u8 k, u16 a, int flag);
int func_021ED250(void);
void func_021ED268(u8 *p, u8 k, u32 x);
int func_021ED280(char *p);
void func_021ED294(u8 *p, int k, u32 x);
int func_021ED2BC(void);
void func_021ED2D0(u8 *p, u8 k);
int func_021ED304(void);
void func_021ED318(char *p, u16 k, u16 a, int flag);
int func_021ED374(char *p);


void func_021ECE60(u8 *a, int b)
{
    func_02043B5C((struct CharBuf *)(((struct Obj02796 *)a)->f4), 0xc);
    func_0201DD78(1, 9, 0xc);
    func_0201C7A4((void *)(((struct Obj02796 *)a)->f4), 0, 0, (void *)b, (void *)(((struct Obj02796 *)a)->f24));
    func_02045334((struct Descriptor *)((struct Obj02796 *)a)->f0);
    a[0x13f] = 0;
    ((struct Obj02796 *)a)->f148 = 0;
    ((struct Obj02796 *)a)->f14A = 0;
    ((struct Obj02796 *)a)->f14C = 0;
    a[0x13e] = 1;
    a[0x141] = 0;
}


void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c)
{
    void *o;

    func_02043B5C((struct CharBuf *)(((struct Obj00027 *)a)->f4), 0xc);
    func_0201DD78(1, 9, 0xc);
    o = func_0201CD10(((struct Obj00027 *)a)->f0, 0, 0, b, ((struct Obj00027 *)a)->f24,
                      func_021B85DC((unsigned char *)(*(int *)&((struct Obj00027 *)a)->f134)),
                      ((struct Obj00027 *)a)->f2C, 0,
                      ((struct Obj00027 *)a)->f13C, 0xc, c);
    ((struct Obj00027 *)a)->f30 = o;
    func_0201CE0C(o);
    a[0x13f] = 0;
    a[0x13e] = 0;
    if (s == 0xff) {
        ((struct Obj00027 *)a)->f148 = 0x50;
        ((struct Obj00027 *)a)->f14C = 0;
    } else {
        ((struct Obj00027 *)a)->f148 = s;
        ((struct Obj00027 *)a)->f14C = s;
    }
    ((struct Obj00027 *)a)->f14A = ((struct Obj00027 *)a)->f148;
    a[0x141] = 0;
}


/*
 * Untraced mid-stream entry point (reached only through the `bx r3` tail thunks, so disasm.py emitted its bytes as a pool run).  Reads the byte at p+0x141: returns 1 and clears it when set, else 0.  The 0x141 index is too wide for Thumb ldrb's 5-bit immediate, so it lives in a pool word and the load is register-offset.
 */
u32 func_021ECF50(u8 *p) { if (p[0x141]) { p[0x141] = 0; return 1; } return 0; }

/*
 * Case 2 writes the next state in if/else arms (the ternary loses the 0x144 base kept in r5),
 * case 4 decrements with `--` (reload of the halfword), and case 5 restarts the counter from
 * h14a without a decrement.
 */
int func_021ECF68(struct T_021ECF68 *p)
{
    switch (p->b13f) {
    case 0:
        func_021ED7C8((struct S *)p->s154, p->b13e);
        p->b13f = p->b13f + 1;
    case 1:
        if (func_021ED814((struct S *)p->s154) == 0)
            break;
        if (p->b13e != 0) {
            p->b13f = 6;
            break;
        }
        if (p->h30 != 0)
            func_0201CE20(p->h30);
        p->b13f = p->b13f + 1;
    case 2:
        if (p->h30 != 0) {
            if (func_021B86C0(p->owner) == 0) {
                if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                    if (func_0201CED4(p->h30) == 0)
                        func_0201CE8C(p->h30, func_02013080(2));
                } else {
                    if (func_0201CED4(p->h30) != 0)
                        func_0201CEB8(p->h30);
                }
            }
            p->i144 = func_0201CE30(p->h30);
            if (p->i144 != 0) {
                if (func_021B86C0(p->owner) == 0)
                    p->b13f = 3;
                else
                    p->b13f = 4;
                if (p->i144 == 2) {
                    p->h148 = p->h14c;
                    p->b141 = 1;
                }
            }
        } else {
            p->b13f = 6;
        }
        break;
    case 3:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0)
            p->h148 = 0;
        if (p->h148 != 0) {
            p->h148 = p->h148 - 1;
            break;
        }
        p->b13f = 5;
        break;
    case 4:
        if (p->h148 != 0) {
            p->h148--;
            break;
        }
        p->b13f = 5;
        break;
    case 5:
        if (p->i144 == 2) {
            func_0201DD68();
            func_0201CE48(p->h30);
            p->h30 = 0;
            p->b13f = 6;
            break;
        }
        func_0201CE38(p->h30);
        func_020061E4(0x547);
        p->b13f = 2;
        p->h148 = p->h14a;
        break;
    case 6:
        if (func_02006254(0x547) == 0) {
            p->b13f = 7;
            return 1;
        }
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}


void func_021ED118(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f)
{
    struct T_021ED118 *q = (struct T_021ED118 *)(p + 0xf0);

    ((struct Obj06290 *)p)->fF0 = c;
    q->a = a;
    q->b = b;
    q->e = e;
    q->f = f;
    q->d = d;
    ((struct Obj06290 *)p)->fE0 = 0;
    *(int (**)(int *, u8 *))(p + 0xe4) = func_021ED158;
    *(u8 * *)&((struct Obj06290 *)p)->fE8 = p;
    ((struct Obj06290 *)p)->fEC = 0;
}


int func_021ED158(int *st, u8 *b)
{
    switch (*st) {
    case 0:
        func_021ED798((struct S *)(b + 0x154));
    inc:
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED814((struct S *)(b + 0x154)) != 0) {
            func_021F7B2C(b + 0xf0);
            goto inc;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_02006210();
            goto inc;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


int func_021ED1B0(char *p)
{
    Cb f;

    f = *(Cb *)&((struct Obj04385 *)p)->fE0;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE0 = 0;
            ((struct Obj04385 *)p)->fEC = 0;
        }
        return 0;
    }
    f = *(Cb *)&((struct Obj04385 *)p)->fE4;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021ED208(char *p, u8 k, u16 a, int flag)
{
    int t;
    u32 v;

    t = func_021D59B4(func_021B98AC(*(char *const * *)&((struct Obj13565 *)p)->f138, k), 0xd);
    v = func_021B8E70(*(u8 * *)&((struct Obj13565 *)p)->f134, k);
    if (flag == 0) {
        func_021F80FC(v, t);
        func_021F7C2C(v, a);
    } else {
        func_021F8118(v, t);
    }
}

int func_021ED250(void)
{
    int a = func_021F7EB4();
    if ((func_021F8180() | a) == 0)
        return 1;
    return 0;
}

void func_021ED268(u8 *p, u8 k, u32 x)
{
    func_021F7C2C(func_021B8E70(*(u8 * *)&((struct Obj21589 *)p)->f134, k), x);
}

int func_021ED280(char *p)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}

void func_021ED294(u8 *p, int k, u32 x)
{
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj21590 *)p)->f134, k);
    func_021F80E4(r);
    if (x == 0)
        func_021F7CE4(r);
    else
        func_021F7F04(r);
}

int func_021ED2BC(void)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}

void func_021ED2D0(u8 *p, u8 k)
{
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj13566 *)p)->f134, k);
    func_021F7EE8(func_021D5864((struct Work *)func_021B98AC(*(char *const * *)&((struct Obj13566 *)p)->f138, k)), r);
    func_021EDA04((struct E *)(p + 0x48 + k * 12));
}

int func_021ED304(void)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}


void func_021ED318(char *p, u16 k, u16 a, int flag)
{
    u8 *t;

    if (flag != 0 || a == 0) {
        func_021F80E4(k);
        func_021F7F04(k);
        return;
    }
    t = func_02031290(func_020311B8(((struct Obj21591 *)p)->f2C, (void *)func_021ED384, 0x10, 1));
    ((struct Obj05231 *)t)->f6 = k;
    *(char * *)&((struct Obj05231 *)t)->f0 = p + 0x48 + k * 0xc;
    *(char * *)&((struct Obj05231 *)t)->fC = p + 0x42;
    if (a == 0)
        a = 0x26c;
    ((struct Obj05231 *)t)->f8 = a;
    ((struct Obj05231 *)t)->f4 = 0;
    (**(u8 * *)&((struct Obj05231 *)t)->fC)++;
}


int func_021ED374(char *p)
{
    if (((struct Obj12172 *)p)->f42 == 0)
        return 1;
    return 0;
}
