/*
 * file:     unit_021ECE60_p10.c
 * unit:     yes
 * function: func_021ED8AC, func_021ED8D8, func_021ED8E8, func_021ED930, func_021ED988, func_021ED9A4, func_021ED9C8, func_021ED9EC
 * address:  0x021ED8AC
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
 *   func_020311B8  0x020311B8  arm  arm9
 *   func_02031290  0x02031290  arm  arm9
 *   func_021ED798  0x021ED798  thumb  ov093
 *   func_021ED814  0x021ED814  thumb  ov093
 *   func_02031194  0x02031194  arm
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021B8640  0x021B8640  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F80E4  0x021F80E4  thumb  ov094
 */
#include "../../matched/include/Obj21604.h"
#include "../../matched/include/Obj10122.h"

struct S02030FB4;
struct S;
struct TcblNode;
struct E;
typedef unsigned char u8;

struct Q_021ED8AC { u8 *a; int b; u8 *c; };

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Sub {
    u8 pad[0x14];
};

struct Q_021ED8E8 {
    char *f00;
    int f04;
    u8 *f08;
};

struct E { int a0; u8 *owner; u8 k8; u8 v9; u8 fa; u8 fb; };

extern void *func_020311B8(void *, void *, int, int);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *s);
extern void func_02031194(struct TcblNode *n);
extern u32 func_021B8588(void **p);
extern unsigned int func_021B8640(unsigned int **p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F80E4(u32 a);
void func_021ED8AC(u8 *p);
u32 func_021ED8D8(u8 *p);
void func_021ED8E8(int a,struct Q_021ED8E8 *q);
void func_021ED930(char *s);
void func_021ED988(u8 *p);
void func_021ED9A4(struct E *e, u8 *o, u8 k);
void func_021ED9C8(struct E *e);
void func_021ED9EC(struct E *e);

void func_021ED8AC(u8 *p)
{
    struct Q_021ED8AC *q;
    q = func_02031290(func_020311B8(((struct Obj21604 *)p)->f2C, (void *)func_021ED8E8, 0xc, 1));
    q->a = p;
    q->c = p + 0x40;
    q->b = 0;
    (*q->c)++;
}


/*
 * Untraced mid-stream entry point, same shape as func_021ED374 with the offset 0x40.
 */
u32 func_021ED8D8(u8 *p) { if (p[0x40] == 0) return 1; return 0; }


void func_021ED8E8(int a,struct Q_021ED8E8 *q)
{
    switch (q->f04) {
    case 0:
        func_021ED798((struct S *)(q->f00 + 0x154));
        q->f04++;
        break;
    case 1:
        if (func_021ED814((struct S *)(q->f00 + 0x154)) != 0) {
            (*q->f08)--;
            func_02031194((struct TcblNode *)a);
        }
        break;
    }
}


void func_021ED930(char *s)
{
    u32 i;
    u32 n;

    for (i = 0; i <= 6; i++) {
        *(u8 *)(s + i * 12 + 0x53) = 0;
        *(int *)(s + i * 12 + 0x48) = 0;
    }
    if (func_021B8588(((struct Obj10122 *)s)->f134) != 3) {
        n = func_021B8640(((struct Obj10122 *)s)->f134);
    } else {
        n = 5;
    }
    for (i = 0; i <= n; i++) {
        func_021ED9A4((struct E *)(s + 0x48 + i * 12), (u8 *)s, i);
    }
}

void func_021ED988(u8 *p)
{
    u32 i;
    for (i = 0; i < 6; i++)
        func_021ED9C8((struct E *)(p + 0x48 + i * 12));
}

void func_021ED9A4(struct E *e, u8 *o, u8 k)
{
    e->k8 = k;
    e->v9 = func_021B8E70(*(u8 * *)&((struct Obj10122 *)o)->f134, k);
    e->owner = o;
    e->fa = 0;
    e->fb = 1;
    e->a0 = 0;
}

void func_021ED9C8(struct E *e)
{
    if (e->fb != 0) {
        if (e->fa != 0) {
            func_021F80E4(e->v9);
            e->fa = 0;
        }
        e->a0 = 0;
        e->fb = 0;
    }
}

void func_021ED9EC(struct E *e)
{
    if (e->fa != 0) {
        func_021F80E4(e->v9);
        e->fa = 0;
    }
}
