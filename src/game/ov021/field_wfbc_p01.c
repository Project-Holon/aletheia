/*
 * file:     field_wfbc_p01.c
 * unit:     yes
 * function: func_02193628, func_02193790, func_021938AC, func_021938D4, func_021938F4, func_021938FC, func_02193904, func_0219390C, func_0219391C
 * address:  0x02193628
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
 *   func_02169520  0x02169520  thumb ov010
 *   func_0216959C  0x0216959C  thumb ov010
 *   func_02169530  0x02169530  thumb ov010
 *   func_021695BC  0x021695BC  thumb ov010
 *   func_02169620  0x02169620  thumb ov010
 *   func_02169528  0x02169528  thumb ov010
 *   func_02169540  0x02169540  thumb ov010
 *   func_02169580  0x02169580  thumb ov010
 *   func_02169560  0x02169560  thumb ov010
 *   func_02169578  0x02169578  thumb ov010
 *   func_02169598  0x02169598  thumb ov010
 *   func_0218DD04  0x0218DD04  thumb ov021
 *   func_0218DD08  0x0218DD08  thumb ov021
 *   func_0218DD0C  0x0218DD0C  thumb ov021
 *   func_0218DD10  0x0218DD10  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_02193924  0x02193924  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm  arm9
 *   func_02193CBC  0x02193CBC  thumb  ov021
 *   d_021DDA60     0x021DDA60  data   ov021  a1
 *   func_02193C80  0x02193C80  thumb  ov021
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02193D08  0x02193D08  thumb  ov021
 *   func_02193E54  0x02193E54  thumb
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193F34  0x02193F34  thumb  ov021
 */
#include "../../matched/include/Obj03576.h"
#include "../../matched/include/Obj07438.h"

struct S;
struct X;
struct E50;
struct V;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16_02193790;

typedef int fx32;

typedef long long s64;

typedef struct Vec {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct Tile {
    s16_02193790 n0[3];
    s16_02193790 n1[3];
    fx32 d0;
    fx32 d1;
    u32 attr : 31;
    u32 flag : 1;
} Tile;

typedef struct Plane {
    s16_02193790 x;
    s16_02193790 y;
    s16_02193790 z;
    s16_02193790 pad;
    u32 attr;
    fx32 height;
    int w[0x3C];
    int valid;
} Plane;

typedef short          s16_021938AC;

typedef signed short   s16_021938D4;

typedef signed char    s8;

typedef signed short   s16_0219390C;

extern int func_02169520(int a0, int a1);
extern void func_0216959C(u8 *p);
extern void func_02169530(unsigned char *a, int *out);
extern void func_021695BC(struct S *p, int b);
extern int func_02169620(struct S *p);
extern void func_02169528(unsigned char *a, int *out);
extern void func_02169540(unsigned char *a, unsigned int v);
extern int func_02169580(int a0);
extern int func_02169560(unsigned char *a);
extern int func_02169578(unsigned char *a);
extern unsigned int func_02169598(u8 *p);
extern int func_0218DD04(u8 *p);
extern int func_0218DD08(u8 *p);
extern int func_0218DD0C(u8 *p);
extern u16 func_0218DD10(u8 *p);
extern int func_0218B974(int a, int o, void *p, int n);
extern int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h);
extern int func_0218DCF4(unsigned int *a0);
extern int func_0218DCFC(unsigned int *a0);
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02193CBC(unsigned char *p);
extern u32 func_020307B0(void *p);
extern void func_0216D974(unsigned int *p, unsigned int v);
extern void func_02193C80(struct X *x);
int func_02193D08(unsigned char *p);
extern void func_02193E54(unsigned char *p, unsigned char *q);
extern int func_02193EB4(void *p);
extern struct E50 *func_02193F34(struct V *v, u32 key);
int func_02193628(u8 *o, unsigned int *q);
void func_02193790(Plane *out, const int *map, Vec *pos, fx32 size, fx32 base);
void *func_021938AC(u32 heap);
u32 func_021938D4(void *a);
int func_021938F4(unsigned char *p);
void func_021938FC(void *v, unsigned char *a1);
int func_02193904(void *p);
void *func_0219390C(void *a, u32 b);
u8 func_0219391C(u8 *p);
extern char d_021DDA60[];


/*
 * Addresses are Black-image addresses.
 */
int func_02193628(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    int boff;
    char *base;
    int j;
    int y0;
    int g;
    int id;
    u16 c;
    char *p;
    int off;
    int r;
    int n;
    int i;
    int x0;

    func_0218DD10((u8 *)q);
    func_02169520((int)o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj03576 *)st)->f18 = 1;
        ((struct Obj03576 *)st)->f1C = 1;
        ((struct Obj03576 *)st)->f20 = 1;
        *st = 3;
        break;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj07438 *)p)->f4));
        off = ((struct Obj07438 *)p)->fC;
        if (off != ((struct Obj07438 *)p)->f10)
            r = func_0218B974(func_0218DD04((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        g = func_0218DD04((u8 *)q);
        base = h;
        boff = ((struct Obj07438 *)p)->f8;
        n = func_0218DD0C((u8 *)q);
        id = func_0218DD08((u8 *)q);
        c = func_0218DD10((u8 *)q);
        x0 = (n % 2) * 4;
        y0 = (n / 2) * 4;
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                r = func_02193924((u8 *)id, base + boff, g, (int)o, r, x0 + i, y0 + j, c);
            }
        }
        func_02169580((int)o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC((unsigned int *)q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 4;
        break;
    case 4:
        *st = 0;
        return 0;
    }
    return 1;
}


static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


static inline void VecSet(Plane *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}


void func_02193790(Plane *out, const int *map, Vec *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int lx = x % 0x10000;
    int lz = z % 0x10000;
    Tile *t = (Tile *)((char *)map + map[2] + 4) + (x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000));
    fx32 d;

    if (t->flag == 0) {
        if (lx + lz < 0x10000) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    } else {
        if (lx > lz) {
            VecSet(out, t->n0[0], t->n0[1], -t->n0[2]);
            d = t->d0;
        } else {
            VecSet(out, t->n1[0], t->n1[1], -t->n1[2]);
            d = t->d1;
        }
    }
    {
        fx32 ny = out->y;
        fx32 mz = FX_MUL(out->z, pos->z);
        fx32 mx = FX_MUL(out->x, pos->x);
        out->attr = t->attr;
        out->height = base + func_0207C768(-(d + (mx + mz)), ny);
    }
    out->valid = 1;
}


void *func_021938AC(u32 heap)
{
    void *o = func_02030734(heap, 0x144, 1, d_021DDA60, 0x12A);
    func_02193CBC(o);
    return o;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021938D4(void *a)
{
func_02193C80((struct X *)a);
if (*(u32 *)((u8 *)(a) + ((5 << 6))) != 0) {
    func_0216D974((unsigned int *)(*(u32 *)((u8 *)(a) + ((5 << 6)))), 1);
}
return func_020307B0(a);
}


/*
 * Unblocked by matching the leaf at 0x02193D08 in ov021; the tail-call site
 * now resolves via `matched`.
 */
int func_021938F4(unsigned char *p)
{
    return func_02193D08(p);
}


/*
 * Tail-call thunk: forwards to func_02193E54 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021938FC(void *v, unsigned char *a1)
{
    func_02193E54(v, a1);
}


/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
int func_02193904(void *p)
{
    return func_02193EB4(p);
}


void *func_0219390C(void *a, u32 b)
{
if (b < 30) {
    return func_02193F34(a, b);
}
return 0;
}


u8 func_0219391C(u8 *p)
{
    return *p;
}
