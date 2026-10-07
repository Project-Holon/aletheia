/*
 * file:     intrude_field_p08.c
 * unit:     yes
 * function: func_0217C11C, func_0217C14C, func_0217C194, func_0217C1D0, func_0217C274, func_0217C294
 * address:  0x0217C11C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021700A4 0x021700A4 data a4
 *   d_02170128 0x02170128 data a2
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_021835D4     0x021835D4  data   a4
 *   func_02013D5C 0x02013D5C thumb
 *   func_0202A188  0x0202A188  thumb
 *   d_0218360C     0x0218360C  data   a4
 *   d_0218362C     0x0218362C  data   a4
 *   func_0216D63C 0x0216D63C thumb ov010
 */
#include "../../matched/include/Obj12484.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u16 h0;
    u16 h2;
    int w4;
} T;

typedef struct {
    int w[7];
    T t;
} S_0217C14C;

typedef unsigned char  u8;

typedef struct {
    u16 h[14];
    T t;
} S_0217C1D0;

typedef struct {
    u32 x : 11;
    u32 gap : 10;
    u32 y : 2;
    u32 z : 6;
    u32 e : 3;
} B;

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
} O;

extern void *func_02188C7C(unsigned char *p);
extern u16 func_02188C9C(u8 *p);
extern void func_0216CE60(int a, int b, int c);
extern u32 func_02013D5C(u32 id);
extern u32 func_0202A188(u8 *p, u32 a, u32 v2, u32 v3);
extern int func_0216D63C(char *, int);
int func_0217C11C(u32 value);
void func_0217C14C(int a0, u16 a1, u16 a2, int a3);
void func_0217C194(int p);
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, T x);
void func_0217C274(unsigned int *out, char *p);
int func_0217C294(char *a0);
extern const u32 d_021700A4;
extern const u16 d_02170128[];
extern const S_0217C14C d_021835D4;
extern const E d_0218360C[];
extern const S_0217C1D0 d_0218362C;

/*
 * lever: index declared before count preserves r3/r4 allocation.
 */
int func_0217C11C(u32 value)
{
    u32 i;
    u32 count;
    count = d_021700A4;
    for (i = 0; i < count; ++i) {
        if (value == d_02170128[i])
            return 1;
    }
    return 0;
}


void func_0217C14C(int a0, u16 a1, u16 a2, int a3)
{
    void *v;
    int c;
    S_0217C14C s;
    T *t;

    v = func_02188C7C((void *)a0);
    c = func_02188C9C((u8 *)a0);
    s = d_021835D4;
    t = &s.t;
    t->h0 = a1;
    t->h2 = a2;
    t->w4 = a3;
    func_0216CE60((int)v, (int)(&s), c);
}

/*
 * extent: two alignment bytes at 0x0217C1CE.
 */
void func_0217C194(int p)
{
    int i;
    if (func_02013D5C(func_02188C9C((u8 *)p)) != 0) {
        for (i = 0; i < 3; ++i)
            func_0217C14C(p, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}


/*
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 */
void func_0217C1D0(const O *o, const B *p, u16 a2, u16 a3, T x)
{
    const E *e;
    int v;
    u16 c;
    S_0217C1D0 s;
    T *t;

    e = &d_0218360C[p->e];
    v = (int)func_02188C7C((u8 *)o->f4);
    c = func_02188C9C((u8 *)o->f4);
    s = d_0218362C;
    s.h[0] = a2;
    s.h[1] = func_0202A188((u8 *)o->f0, (u16)p->x, (u16)p->y, (u16)p->z);
    s.h[2] = e->h0;
    s.h[10] = e->b2;
    s.h[11] = e->b3;
    s.h[7] = o->f8 + a2;
    s.h[8] = ((struct Obj12484 *)p)->f0;
    s.h[9] = ((struct Obj12484 *)p)->f0 >> 16;
    t = &s.t;
    t->h0 = a3;
    t->h2 = x.h0;
    t->w4 = x.w4;
    func_0216CE60(v, (int)(&s), c);
}

void func_0217C274(unsigned int *out, char *p)
{
    int lo;
    lo = func_0216D63C(p, 1);
    *out = lo | (func_0216D63C(p, 2) << 16);
}


/*
 * Recursive MATCH unblocker: callee of func_0216AC90 (ov010) +0026 and
 * func_0216ACCC (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 */
int func_0217C294(char *a0)
{
    return func_0216D63C(a0, 0);
}
