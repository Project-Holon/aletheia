/*
 * file:     unit_021F39C0_p04.c
 * unit:     yes
 * function: func_021F405C, func_021F40F4, func_021F4124, func_021F414C, func_021F4174, func_021F41F0, func_021F42AC, func_021F4318
 * address:  0x021F405C
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F3B20  0x021F3B20  thumb  ov055
 *   func_021F3F9C  0x021F3F9C  thumb  ov055
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216D5B4 0x0216D5B4 thumb ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021F3DD4  0x021F3DD4  thumb  ov055
 *   func_021F3DBC  0x021F3DBC  thumb  ov055
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021F3D90  0x021F3D90  thumb  ov055
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_021F4388  0x021F4388  thumb  ov055
 */
#include "../../matched/include/Obj00204.h"
#include "../../matched/include/Obj07666.h"

struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct E { char b[10]; u16 w; } E;

typedef struct S {
    short lim[6];
    u8 n;
    u8 pad[13];
    E ent[2];
    short cnt[2];
} S;

typedef unsigned int  u32;

extern u8 *func_021F3B20(u8 *p);
extern void func_021F3F9C(const char *a, int b, const u16 *c, u8 *d, u16 e);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DC98(void *a0, int a1);
extern void func_0216DAE0(unsigned int *,unsigned int);
extern void func_0216D5B4(void *p, u16 v);
extern int func_0216D454();
extern void func_0216D410(void *a0, u16 a1);
extern void func_021F3DD4(u8 *a, u32 b);
extern void func_021F3DBC(u8 *a);
extern void *func_021A3074(unsigned char *p);
extern void func_021F3D90(u8 *a);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a, int b);
extern int func_0216DAB4(void *a);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir);
void func_021F405C(S *p, char *q, int k);
u32 func_021F40F4(u8 *p);
void func_021F4124(unsigned char *p);
void func_021F414C(unsigned char *p);
void func_021F4174(u8 *a, u32 b);
void func_021F41F0(u8 *a, u32 b, u32 c);
int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e);
int func_021F4318(const u8 *a, void *b, u16 c, u16 d);


void func_021F405C(S *p, char *q, int k)
{
    int i, j, n, acc;

    for (i = 0; i < p->n; i++) {
        n = (p->ent[i].w * 6) / p->lim[k];
        acc = 0;
        for (j = 0; j < n; j++) {
            u8 *e = func_021F3B20((u8 *)q);
            if (e) {
                func_021F3F9C(q, (int)p, (const u16 *)(&p->ent[i]), e, (u16)(acc / 6));
                acc += p->lim[k];
            }
        }
    }
}


u32 func_021F40F4(u8 *p)
{
    u32 v = p[0x18];

    if (v == 2)  return 0x14;
    if (v == 4)  return 0x10;
    if (v == 6)  return 0x4c;
    if (v == 8)  return 0xc;
    if (v == 16) return 8;
    return 0xc;
}

void func_021F4124(unsigned char *p) { func_0216DB4C(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); func_0216DC98(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); func_0216DAE0(*(unsigned int * *)&((struct Obj00204 *)p)->fC,0); func_0216D5B4((void *)(*(unsigned int *)&((struct Obj00204 *)p)->fC),2000); }

void func_021F414C(unsigned char *p) { func_0216DB4C(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DC98(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DAE0(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216D5B4((void *)(*(unsigned int *)&((struct Obj07666 *)p)->fC),2000); }


void func_021F4174(u8 *a, u32 b)
{
    u32 loc;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, 2, 0)) {
            func_021F3DD4(a, loc);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}


void func_021F41F0(u8 *a, u32 b, u32 c)
{
    u32 loc;
    void *x;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        x = (void *)func_021A3074((void *)c);
        c = 1;
        if (func_021F4318(a, x, 1, 1)) {
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), ((struct Obj00204 *)a)->f6);
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, c, 0)) {
            func_021F3DD4(a, loc);
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
            func_021F3D90(a);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}


/*
 * d and e are u16, as are func_021F4318's last two parameters (its own
 * file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 */
int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e)
{
    u32 iter = 0;
    u32 cur;

    while (func_0216DD1C(b, (struct Rec **)(&cur), &iter) == 1) {
        if (*(u32 *)&((struct Obj00204 *)a)->fC != cur && func_0216D55C(cur, 0x80) == 0 &&
            func_0216DAB4((void *)cur) == 0 && func_021F4318(a, (void *)cur, d, e) != 0) {
            *c = cur;
            return 1;
        }
    }
    return 0;
}


int func_021F4318(const u8 *a, void *b, u16 c, u16 d)
{
    int x0 = func_0216D83C(b);
    int y0 = func_0216D86C(b);
    int x1 = func_0216D83C(*(void * const *)&((struct Obj00204 *)a)->fC);
    int y1 = func_0216D86C(*(void * const *)&((struct Obj00204 *)a)->fC);
    int x2;
    int y2;

    if (func_021F4388(x1, y1, x0, y0, c, d, a[3])) {
        return 1;
    }
    x2 = func_0216D804(b);
    y2 = func_0216D81C(b);
    return func_021F4388(x1, y1, x2, y2, c, d, a[3]);
}
