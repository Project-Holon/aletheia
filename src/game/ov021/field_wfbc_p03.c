/*
 * file:     field_wfbc_p03.c
 * unit:     yes
 * function: func_02194044, func_02194078, func_02194084, func_02194128, func_02194284, func_021942C8, func_02194300
 * address:  0x02194044
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   _u32_div_f     0x0209C2B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ull_mul       0x0209C054  arm
 *   func_02194014  0x02194014  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDA70     0x021DDA70  data  a4
 *   func_02194418  0x02194418  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_02194434  0x02194434  thumb  ov021
 */
#include "../../matched/include/Obj07444.h"
#include "../../matched/include/Obj07446.h"
#include "../../matched/include/Obj09482.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u8 a; u8 b; u16 c; } Cell;

typedef unsigned long long u64;

typedef struct { u8 x0; u8 x1; u8 pad[22]; } Item_02194044;

typedef struct { u32 x0; u32 x4; Item_02194044 items[10]; } In;

typedef struct {
    u64 seed;
    u64 mul;
    u64 add;
    u16 x18;
    u16 x1a;
    u32 x1c;
    u32 x20;
} Out;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
    u8 b;
} P;

typedef struct {
    P cells[8][8];
    u32 vals[1][16];
} T;

typedef struct {
    MATHRandContext32 rand;
    u16 max;
    u16 base;
    int f1c;
    u32 seed;
} E;

typedef struct { u32 key; u32 x4; u32 x8; } Item_021942C8;

typedef struct { u16 n; u16 pad; u32 x4; Item_021942C8 *items; } List;

extern void func_02082BCC();
extern int func_02161ECC(Item_02194044 *);
extern void func_02186818(u32 *p, u32 member);
extern char *func_0218682C(char *p);
extern int func_02186278(char *p, int which);
extern void func_02194014(u8 *out, int i, int j, P t, u16 c);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern int func_02194418(u32 a);
extern u32 func_020307B0(void *p);
extern int func_021945A0(int x);
extern void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);
int func_02194044(Cell (*t)[8], u8 b, u16 c);
void func_02194078(u32 a);
void func_02194084(Out *o, In *in, u32 c);
void func_02194128(E *e, T *tbl, u8 *out);
void *func_02194284(int a, void *b, int heap, int c);
void func_021942C8(List *p);
void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);
extern int d_021DDA70;



/*
 * Addresses are Black-image addresses.
 */
int func_02194044(Cell (*t)[8], u8 b, u16 c)
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (b == t[i][j].b && c == t[i][j].c) {
                return 1;
            }
        }
    }
    return 0;
}



/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 36.
 *
 * Addresses are Black-image addresses.
 */
void func_02194078(u32 a)
{
    func_02082BCC(a, 0, 36);
}



void func_02194084(Out *o, In *in, u32 c)
{
    int sum;
    int cnt;
    int i;

    sum = 0;
    cnt = 0;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(&in->items[i]) != 0) {
            func_02186818((u32 *)c, in->items[i].x1);
            sum += *(u16 *)(func_0218682C((char *)c) + 0x2E);
            cnt += in->items[i].x1;
        }
    }
    o->x1c = func_02186278((char *)in, 0);
    o->seed = in->x4;
    o->mul = 0x5D588B656C078965ULL;
    o->add = 0x269EC3;
    if (o->x1c == 0) {
        o->x18 = 1;
    } else {
        o->x18 = sum + 2;
    }
    o->x1a = cnt;
    o->x20 = in->x4;
}



static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}



static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max) {
        return (u32)(((context->x >> 32) * max) >> 32);
    } else {
        return (u32)(context->x >> 32);
    }
}



/*
 * Seeds a NitroSDK MATHRandContext32 at the head of e (MATH_InitRand32
 * inline) and fills an 8x8 grid of 4-byte cells through func_02194014.
 * Spill-slot order (u64 max temp at the top, then row, j, d, k) needs the
 * explicit locals in this declaration order; the index `r += k * 8` must be
 * folded into r before the call or the tail's loads schedule differently.
 * Addresses are Black-image addresses.
 */
void func_02194128(E *e, T *tbl, u8 *out)
{
    P t;
    u32 mx;
    P *row;
    int j;
    u8 d;
    u8 k;
    int i;
    int r;
    int dx;
    int dy;

    MATH_InitRand32(&e->rand, e->seed);
    for (j = 0; j < 8; j++) {
        row = tbl->cells[j];
        for (i = 0; i < 8; i++) {
            t = row[i];
            d = t.b;
            if (d == 0xFF) {
                continue;
            }
            if (t.lo != 0 || t.hi != 0) {
                func_02194014(out, i, j, t, *(u16 *)(out + (j - t.hi) * 0x20 + (i - t.lo) * 4 + 2));
            } else {
                dx = i - t.lo;
                dy = j - t.hi;
                k = (u8)((u8)((u8)e->base + (u8)(dx + dy)) / (u32)((dx + 3) + (dy + 1))) % 2;
                r = (e->f1c * 8) / 10;
                mx = e->max;
                r += MATH_Rand32(&e->rand, mx);
                if (r >= 8) {
                    r = 7;
                }
                r += k * 8;
                func_02194014(out, i, j, t, tbl->vals[d][r]);
            }
        }
    }
}



void *func_02194284(int a, void *b, int heap, int c)
{
    int n = 0xc;
    char *p = (char *)func_02030734(heap, n, 1, (const char *)&d_021DDA70, 0x5d);

    ((struct Obj07444 *)p)->f0 = a;
    ((struct Obj07444 *)p)->f2 = c;
    ((struct Obj07444 *)p)->f4 = b;
    ((struct Obj07444 *)p)->f8 = func_02030734(heap, n * a, 1, (const char *)&d_021DDA70, 0x63);
    return p;
}



void func_021942C8(List *p)
{
    u16 i;
    Item_021942C8 *it;

    i = 0;
    it = p->items;
    if (i < p->n) {
        for (; i < p->n; i++) {
            if (it->x8 != 0) {
                func_02194418((u32)it);
            }
            it++;
        }
    }
    func_020307B0(p->items);
    func_020307B0(p);
}



void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f)
{
    u16 i;
    unsigned char *q = *(unsigned char * *)&((struct Obj09482 *)a)->f8;

    func_021945A0(*d);
    for (i = 0; i < *a; i++) {
        if (*(int *)&((struct Obj07446 *)q)->f8 == 0) {
            ((struct Obj07446 *)q)->f8 = func_02194434((unsigned char *)a, c, d, e, f, (int)q);
            ((struct Obj07446 *)q)->f0 = b;
            ((struct Obj07446 *)q)->f6 = a[1];
            return;
        }
        q += 0xc;
    }
}
