/*
 * file:     unit_0217AE20_p04.c
 * unit:     yes
 * function: func_0217B370, func_0217B3EC, func_0217B440, func_0217B4C4, func_0217B5E0, func_0217B66C
 * address:  0x0217B370
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02180044  0x02180044  data  a4
 *   d_02180048  0x02180048  data  a4
 *   d_0218004C  0x0218004C  data  a4
 *   func_02012EBC 0x02012EBC  thumb
 *   func_0200ED48 0x0200ED48  thumb
 *   func_0201283C 0x0201283C  thumb
 *   func_02188CE0 0x02188CE0  thumb  ov021
 *   func_0217AFB0 0x0217AFB0  thumb  ov019
 *   func_0217F894 0x0217F894  thumb  ov019
 *   func_0200EDC4 0x0200EDC4  thumb
 *   func_0217F948 0x0217F948  thumb  ov019
 *   func_0217AE38  0x0217AE38  thumb  ov019
 *   func_0217AED4  0x0217AED4  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 */
#include "../../matched/include/Obj07379.h"
#include "../../matched/include/Obj07380.h"
#include "../../matched/include/Obj12518.h"

struct Big;
struct BigObj;
struct L0200EDC4;
struct Obj00020;
typedef int (*fn_t)(char *, unsigned char *, int, unsigned char *);

struct ent_0217B370 { fn_t f; int a; int b; };

typedef unsigned short u16;

typedef unsigned char u8;

struct ent_0217B440 {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x54];
    int f5c;
    u8 pad2[0x10];
    int *p70;
    u8 pad3[0x18];
};

typedef unsigned int   u32;

typedef struct Rec {
    u8 pad0[6];
    u8 b6;
    u8 f7_lo : 1;
    u8 valid : 1;
    u8 f7_hi : 6;
} Rec;

typedef struct Entry {
    u8   pad0[6];
    u8   n : 3;
    u8   f6_hi : 5;
    u8   f7_lo : 5;
    u8   kind : 3;
    u8   pad8[3];
    u8   bB;
    u8   padC[0x28 - 0xC];
    Rec  recs[8];
    u8   pad68[4];
    u16  h6C;
} Entry;

typedef struct Msg {
    Entry *e;
    u8     b4;
    u8     b5;
    u8     idx;
} Msg;

typedef short s16;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02188CE0(u8 *p);
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern int func_0217F894(void *p, char *q);
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void func_0217F948(char *p, u32 a, u32 b);
extern int func_0217AE38(char *p, char v);
extern u16 func_0217AED4(u8 *a, u8 *b);
extern int func_0217F060(int i);
extern int func_0217F858(int a);
extern int func_0216D3CC(int a0);
extern void func_0216D410(void *a0, u16 a1);
extern u16 func_0216D5A0(void *p);
extern int func_0216E0E8(int a0, int a1);
extern void func_0216D828(int, s16 *);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern int func_0216D454(int);
extern int func_0216D480(char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
int func_0217B370(char *base, unsigned char *p, int r2);
int func_0217B3EC(char *base, char *p);
void func_0217B440(char *base, int x, void *y);
int func_0217B4C4(u8 *w, Msg *m);
int func_0217B5E0(char *base, int *p, int r2, unsigned char *state);
int func_0217B66C(char *base, int *p, int r2, unsigned char *state);
extern struct ent_0217B370 d_02180044[];
extern struct ent_0217B370 d_02180048[];
extern struct ent_0217B370 d_0218004C[];


int func_0217B370(char *base, unsigned char *p, int r2)
{
    int res = 1;
    fn_t fn;

    switch (p[0xa]) {
    case 0:
        fn = d_02180044[p[8]].f;
        break;
    case 1:
        fn = d_02180048[p[8]].f;
        break;
    case 2:
        fn = d_0218004C[p[8]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, p, r2, p + 0xb);
    }
    if (res == 1) {
        p[0xb] = 0;
        p[0xa] = p[0xa] + 1;
        if (p[0xa] > 2) {
            if (p[8] == 2) {
                return 0;
            }
            p[0xa] = 0;
            p[8] = p[9];
            p[9] = 0;
        }
    }
    return 1;
}


int func_0217B3EC(char *base, char *p)
{
    char *q = base + 0x2830;
    if (*(char * *)&((struct Obj07380 *)q)->f14 == p || *(char * *)&((struct Obj07380 *)q)->f18 == p ||
        *(char * *)&((struct Obj07380 *)q)->f1C == p || *(char * *)&((struct Obj07380 *)q)->f20 == p) {
        if (((struct Obj07379 *)p)->f6C == 0) {
            ((struct Obj07379 *)p)->f6C = 1;
        }
        return 1;
    }
    if (((struct Obj07379 *)p)->f6C == 0) {
        return 0;
    }
    ((struct Obj07379 *)p)->f6C -= 1;
    return 1;
}


void func_0217B440(char *base, int x, void *y)
{
    struct ent_0217B440 *q;
    int a;
    int b;
    int c;
    int r;
    int i;

    a = (int)func_0200ED48(func_02012EBC((struct Big *)x));
    b = func_0201283C((const struct BigObj *)x);
    c = func_02188CE0((u8 *)y);
    q = (struct ent_0217B440 *)(base + 0x2910);
    for (i = 0; i < 10; i++, q++) {
        if (q->on == 1 && q->p70 != 0) {
            r = (int)func_0217AFB0((void **)base, (u8 *)(*q->p70), (u8 *)q->p70);
            if (r != 0) {
                if (func_0217F894((void *)b, (char *)q) == 1) {
                    func_0217F948((char *)c, r, 0);
                } else if (func_0200EDC4((struct L0200EDC4 *)a, q->f5c) == 1) {
                    func_0217F948((char *)c, r, 1);
                }
            }
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
int func_0217B4C4(u8 *w, Msg *m)
{
    Entry *e;
    u8 *s;
    int t;
    int v;
    void *r;

    s = w + 0x2830;
    e = m->e;
    if (e->h6C == 0) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    if (!e->recs[m->idx].valid || m->b4 != e->recs[m->idx].b6) {
        func_0217AE38((char *)m, 2);
        return 1;
    }
    t = func_0217F858(e->bB);
    if (((struct Obj12518 *)s)->f58 == func_0217AED4((u8 *)m->e, (u8 *)m)) {
        func_0217AE38((char *)m, 3);
        return 1;
    }
    v = s[2];
    if (v != 0 && (v == t || (t == 0 && v == e->kind)) && m->idx == 0
        && func_0217F060(e->bB) > e->n) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D3CC((int)r) == 1) {
            func_0216D410(r, 0x31);
        }
    } else if (m->idx == 0 && e->n > 1) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D5A0(r) == 2) {
            func_0216E0E8((int)r, 0xF);
        }
    } else if (m->idx == 0 && e->n <= 1) {
        r = func_0217AFB0((void **)w, (u8 *)m->e, (u8 *)m);
        if (func_0216D5A0(r) == 0xF) {
            func_0216E0E8((int)r, 2);
        }
    }
    return 0;
}


int func_0217B5E0(char *base, int *p, int r2, unsigned char *state)
{
    s16 a[8];
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            func_0216D828((int)func_021A3074(func_02188CB4((void *)r2)), a);
            func_0216D828(h, a + 4);
            if (a[4] != a[0] || a[6] != a[2]) {
                func_0216D410((void *)h, 0x44);
                func_0216DAC8((unsigned int *)h, 0);
                *state = *state + 1;
            }
        }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}


int func_0217B66C(char *base, int *p, int r2, unsigned char *state)
{
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) { func_0216D410((void *)h, 0x43); *state = *state + 1; }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}
