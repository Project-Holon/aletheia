/*
 * file:     field_wfbc_p01.c
 * unit:     yes
 * function: func_02193628, func_02193790, func_021938AC, func_021938D4, func_021938F4, func_021938FC, func_02193904, func_0219390C, func_0219391C, func_02193920, func_02193924, func_021939C0, func_02193ABC, func_02193AFC, func_02193B04, func_02193B20, func_02193B40, func_02193B68, func_02193BC4, func_02193BE4, func_02193C00, func_02193C04, func_02193C08, func_02193C80, func_02193CBC, func_02193D08, func_02193D30, func_02193E54, func_02193EB4, func_02193EE8, func_02193EFC
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
 *   func_021A7410  0x021A7410  thumb ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02030734  0x02030734  arm  arm9
 *   d_021DDA60     0x021DDA60  data   ov021  a1
 *   func_0216D974  0x0216D974  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_02194038  0x02194038  thumb  ov021
 *   func_021C939C  0x021C939C  thumb  ov021
 *   func_021C93E4  0x021C93E4  thumb  ov021
 *   func_021C9450  0x021C9450  thumb  ov021
 *   func_021C93D0  0x021C93D0  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02049250  0x02049250  arm
 *   func_02194044  0x02194044  thumb  ov021
 *   func_0216245C  0x0216245C  thumb  ov010
 *   d_021D3F60     0x021D3F60  data  a4
 *   func_0204A380  0x0204A380  arm
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_02186748  0x02186748  thumb  ov020
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02186764  0x02186764  thumb
 *   func_02186770  0x02186770  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_020490F4  0x020490F4  arm
 *   func_02186830  0x02186830  thumb
 *   func_02049238  0x02049238  arm  arm9
 *   func_02186804  0x02186804  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm
 *   func_02193FE8  0x02193FE8  thumb  ov021
 *   func_02194078  0x02194078  thumb  ov021
 *   func_0218625C  0x0218625C  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02193F80  0x02193F80  thumb  ov021
 *   func_02194084  0x02194084  thumb  ov021
 *   func_02194128  0x02194128  thumb  ov021
 *   func_0204932C  0x0204932C  arm
 *   d_021D3F58     0x021D3F58  data  a4
 *   func_0218609C  0x0218609C  thumb  ov020
 *   func_021860B8  0x021860B8  thumb  ov020
 *   func_02193FD4  0x02193FD4  thumb  ov021
 *   func_02193FBC  0x02193FBC  thumb  ov021
 *   func_021867B0  0x021867B0  thumb  ov020
 */
#include "../../matched/include/Obj03576.h"
#include "../../matched/include/Obj07438.h"
#include "../../matched/include/Obj17939.h"
#include "../../matched/include/Obj07440.h"
#include "../../matched/include/Obj19614.h"
#include "../../matched/include/Obj17940.h"
#include "../../matched/include/Obj19617.h"
#include "../../matched/include/Obj00485.h"
#include "../../matched/include/Obj04214.h"
#include "../../matched/include/Obj19618.h"
#include "../../matched/include/Obj07441.h"
#include "../../matched/include/Obj12617.h"

struct S;
struct X;
struct E50;
struct V_02193628;
struct ArcFile;
struct State;
struct Sub0200852CObj;
struct WordSet;
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

typedef signed short   s16_02193628;

typedef struct { u8 lo:4; u8 hi:4; u8 b; u16 c; } Cell;

typedef struct { u16 a; u16 b; u32 c; } Ent;

typedef short          s16_02193B40;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl {
    u8  hdr[8];
    E18 e[10];
} Tbl;

typedef struct V_02193628 {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl *f08;
} V_02193628;

typedef signed short   s16_02193BE4;

typedef short          s16_02193C80;

typedef struct X {
    u32 f00;
    void *f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    void *f14;
    u8  pad18[0x100];
    u32 f118;
} X;

typedef struct { u8 a; u8 b; u8 rest[0x16]; } E18_02193D30;

typedef struct { u16 h0; u16 h1; u32 w4; E18_02193D30 A[10]; E18_02193D30 B[10]; } Src;

typedef short          s16_02193EB4;

typedef struct E18_02193EB4 {
    u8 b[0x18];
} E18_02193EB4;

typedef struct Tbl_02193BE4 {
    u8  hdr[8];
    E18_02193EB4 e[10];
} Tbl_02193BE4;

typedef struct V_02193BE4 {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl_02193BE4 *f08;
} V_02193BE4;

typedef struct Tbl_02193EE8 {
    u8  hdr[8];
    E18 e[10];
} Tbl_02193EE8;

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
extern int func_0218DCF4(unsigned int *a0);
extern int func_0218DCFC(unsigned int *a0);
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0216D974(unsigned int *p, unsigned int v);
extern struct E50 *func_02193F34(struct V_02193628 *v, u32 key);
extern Cell func_02194038(void *a, int b, int c);
extern u32 *func_021C939C(u32 a, u32 heap);
extern void func_021C93E4(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
extern u32 func_021C9450(u32 a, u32 b, u32 c, u32 d, int e, int f);
extern void func_021C93D0(void **q);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern Ent *func_02049250(int h, int a, u16 heap);
extern int func_02194044(u8 *p, u16 a, u16 b);
extern void func_0216245C(u8 *o, u16 idx);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_0218E17C(u32 *p, u32 v);
extern void func_02193F6C(struct E50 *e);
extern void func_02186748(struct State *p);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_02186764(u8 *);
extern int func_02186770(u8 *);
extern int *func_021867C4(int a, int id);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_02186830(int, int, int);
extern void func_0218683C(void *p);
extern void func_02049238(u32 a);
extern void func_02186804(void **p);
extern u32 func_02082BCC(void *p, int v, int n);
extern void func_02193FE8(void *p);
extern void func_02194078(u32 a);
extern int func_0218625C(unsigned short *p);
extern int func_02161ECC(E18_02193D30 *p);
extern void func_02186818(u32 *p, u32 member);
extern u8 *func_02186844(u8 *t, int i);
extern char *func_0218682C(char *p);
extern void func_02193F80(struct E50 *e, void *a, u8 *b, void *c);
extern void func_02194084(u8 *p, Src *s, int h);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02194128(u8 *p, int a, u8 *b);
extern void func_0218609C(char *p);
extern void func_021860B8(char *p);
extern void func_02193FD4(u16 *a, void *b);
extern void func_02193FBC(u16 *a, void *b);
extern int func_021867B0(u8 *p);
int func_02193628(u8 *o, unsigned int *q);
void func_02193790(Plane *out, const int *map, Vec *pos, fx32 size, fx32 base);
void *func_021938AC(u32 heap);
u32 func_021938D4(void *a);
int func_021938F4(unsigned char *p);
void func_02193904(void *p);
void *func_0219390C(void *a, u32 b);
u8 func_0219391C(u8 *p);
u8 func_02193920(u8 *p);
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h);
void func_021939C0(u8 *o, void *dst, int skip, u32 heap);
void func_02193ABC(char *p, int a, int b);
void func_02193AFC(u8 *p, u32 v);
void func_02193B04(u32 a, u32 b, u32 c, u32 d);
void func_02193B20(u32 a, u32 b);
void func_02193B40(V_02193628 *v, u32 key);
void func_02193B68(void *a, int b, int c, int d, u16 e);
void func_02193BC4(void *a, u32 b);
int func_02193BE4(void *a, u32 b);
char *func_02193C00(char *p);
void *func_02193C04(u8 *p);
void func_02193C08(char *p, int heap);
void func_02193C80(X *x);
void func_02193CBC(unsigned char *p);
int func_02193D08(unsigned char *p);
void func_02193D30(u8 *o, Src *s, int which);
void func_02193E54(unsigned char *p, unsigned char *q);
void func_02193EB4(V_02193BE4 *v);
void func_02193EE8(V_02193BE4 *v);
E50 *func_02193EFC(V_02193BE4 *v, u32 key);
extern char d_021DDA60[];
extern int d_021D3F60[];
extern int d_021D3F58[];







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
func_02193C80((X *)((struct X *)a));
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
void func_021938FC(v, a1)
void *v;
unsigned char *a1;
{
    func_02193E54(v, a1);
}







/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
void func_02193904(void *p)
{
    func_02193EB4((V_02193BE4 *)p);
}







void *func_0219390C(void *a, u32 b)
{
if (b < 30) {
    return func_02193F34((struct V_02193628 *)a, b);
}
return 0;
}







u8 func_0219391C(u8 *p)
{
    return *p;
}







/*
 * Loads the byte at +0x1 of the object.
 */
u8 func_02193920(u8 *p)
{
    return ((struct Obj17939 *)p)->f1;
}







/*
 * The cell comes back from func_02194038 as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 * Addresses are Black-image addresses.
 */
int func_02193924(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h)
{
    Cell cell = func_02194038(a + 0x18, f, g);
    u32 *t;
    int x, y;
    int lo, hi;

    if (cell.b != 0xFF) {
        x = (f * 8) & 0x1F;
        y = (g * 8) & 0x1F;
        t = func_021C939C(cell.c, (u16)((h & 0x7FFF) | 0x8000));
        hi = cell.hi;
        lo = cell.lo;
        func_021C93E4((u32)t, q, lo * 8, hi * 8, x, y, 8, 8);
        if (lo == 0 && hi == 0) {
            e = func_021C9450((u32)t, c, d, e, x, y);
        }
        func_021C93D0((void **)t);
    }
    return e;
}







void func_021939C0(u8 *o, void *dst, int skip, u32 heap)
{
    u32 n;
    Ent *e;
    u32 *seen;
    u32 cnt;
    u32 i;
    u32 j;
    Ent *cur;

    if (skip != 0)
        return;
    n = func_020493D4((struct ArcFile *)(((struct Obj07440 *)o)->f10), d_021D3F60[*o]);
    heap = (heap & 0x7FFF) | 0x8000;
    e = func_02049250(((struct Obj07440 *)o)->f10, d_021D3F60[*o], (u16)heap);
    n >>= 3;
    seen = func_02030734((u16)heap, n * 4, 1, (const char *)&d_021DDA60, 0x208);
    cnt = 0;
    for (i = 0; i < n; i++) {
        cur = &e[i];
        if (func_02194044(o + 0x18, e[i].a, cur->b)) {
            seen[cnt] = cur->c;
            cnt++;
        } else {
            for (j = 0; j < cnt; j++) {
                if (seen[j] == e[i].c)
                    break;
            }
            if (j >= cnt) {
                for (j = i + 1; j < n; j++) {
                    if (cur->c == e[j].c)
                        break;
                }
                if (j >= n)
                    func_0216245C(dst, (u16)cur->c);
            }
        }
    }
    func_020307B0(seen);
    func_020307B0(e);
}







void func_02193ABC(char *p, int a, int b)
{
    u16 *h;

    h = func_0204A380((void *)(((struct Obj19614 *)p)->f10), 0x24, 0, (u16)((b & 0x7fff) | 0x8000));
    func_0218E17C((u32 *)a, h[func_021938F4((unsigned char *)p)]);
    func_020307B0(h);
}







/*
 * Stores the 32-bit word into byte +0x140 of the object.
 */
void func_02193AFC(u8 *p, u32 v)
{
    ((struct Obj17940 *)p)->f140 = v;
}






void func_02193B04(u32 a, u32 b, u32 c, u32 d)
{
func_02193C08((char *)a, d);
func_02193D30((u8 *)a, (Src *)b, c);
}






void func_02193B20(u32 a, u32 b)
{
func_02193EB4((V_02193BE4 *)((struct V_02193628 *)a));
func_02193F6C((struct E50 *)func_02193EFC((V_02193BE4 *)((struct V_02193628 *)a), b));
func_02193EE8((V_02193BE4 *)a);
}




void func_02193B40(V_02193628 *v, u32 key)
{
    E50 *e;

    func_02193EB4((V_02193BE4 *)v);
    e = (struct E50 *)func_02193EFC((V_02193BE4 *)((struct V_02193628 *)v), key);
    if (v->f01 == 0) {
        func_02186748((struct State *)e->f34);
        func_02193EE8((V_02193BE4 *)((u32)v));
    }
}




void func_02193B68(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    func_02193EB4((V_02193BE4 *)a);
    q = (char *)func_02193F34((struct V_02193628 *)a, c);
    h = (int)func_0200846C((u16)((e & 0x7fff) | 0x8000));
    func_020084A0((struct Sub0200852CObj *)h);
    func_020084D4(h, q + 0x38);
    func_0200852C((struct Sub0200852CObj *)h, ((struct Obj19617 *)q)->f48);
    func_0201F02C((struct WordSet *)b, d, (void *)h);
    func_020307B0((void *)h);
}




/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186764 (0x02186764) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_02193BC4(void *a, u32 b)
{
func_02193EB4((V_02193BE4 *)a);
func_02186764(((u8 *)(struct E50 *)func_02193EFC((V_02193BE4 *)((struct V_02193628 *)a), b) + 52));
func_02193EE8((V_02193BE4 *)((u32)a));
}




/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186770 (0x02186770) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193BE4(void *a, u32 b)
{
func_02193EB4((V_02193BE4 *)a);
return func_02186770(((u8 *)func_02193F34((struct V_02193628 *)a, b) + 52));
}



char *func_02193C00(char *p)
{
    return p + 4;
}




void *func_02193C04(u8 *p)
{
    return p + 0x34;
}




void func_02193C08(char *p, int heap)
{
    int i;

    if (((struct Obj00485 *)p)->fC == 0) {
        i = 0;
        ((struct Obj00485 *)p)->fC = (int)func_021867C4(0, heap);
        ((struct Obj00485 *)p)->f4 = func_02030734(heap, 0x320, 1, (const char *)&d_021DDA60, 0x39e);
        for (i = 0; i < 10; i++) {
            func_02193F6C((struct E50 *)((char *)*(int *)&((struct Obj00485 *)p)->f4 + i * 0x50));
        }
        ((struct Obj00485 *)p)->f10 = func_020490F4(0x9a, heap);
        ((struct Obj00485 *)p)->f14 = func_02030734(heap, 0x600, 1, (const char *)&d_021DDA60, 0x3ab);
        *(int *)&((struct Obj00485 *)p)->f118 = func_02186830(((struct Obj00485 *)p)->fC, ((struct Obj00485 *)p)->f0, heap);
    }
}




void func_02193C80(X *x)
{
    if (x->f0c != 0) {
        func_0218683C((void *)x->f118);
        func_020307B0(x->f14);
        func_02049238(x->f10);
        func_02186804((void **)x->f0c);
        func_020307B0(x->f04);
        x->f0c = 0;
        x->f04 = 0;
        x->f10 = 0;
        x->f14 = 0;
        x->f118 = 0;
    }
}




void func_02193CBC(unsigned char *p)
{
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj04214 *)p)->f4;

    p[0] = 0;
    p[1] = 0;
    ((struct Obj04214 *)p)->f8 = 0;
    if (q != 0) {
        for (i = 0; i < 10; i++)
            func_02193F6C((struct E50 *)(*(unsigned char * *)&((struct Obj04214 *)p)->f4 + i * 0x50));
    }
    if (((struct Obj04214 *)p)->f14 != 0)
        func_02082BCC(((struct Obj04214 *)p)->f14, 0, 0x600);
    func_02193FE8(p + 0x18);
    func_02194078((u32)(p + 0x11c));
}




int func_02193D08(unsigned char *p)
{
    int count = 0;
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj19618 *)p)->f4;

    if (q != 0) {
        for (i = 0; i < 10; i++) {
            if (*(unsigned short *)(q + i * 0x50) != 0)
                count++;
        }
    }
    return count;
}




void func_02193D30(u8 *o, Src *s, int which)
{
    int i;
    int off;
    u8 *pair;

    func_0218625C((short unsigned int *)s);
    func_02193CBC(o);
    o[0] = s->h1;
    o[1] = which;
    for (i = 0; i < 10; i++) {
        if (which == 0) {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->A + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->A[i].b);
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->A + off),
                              func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i),
                              (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        } else {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->B + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->B[i].b);
                pair = func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i);
                func_0218682C((char *)(((struct Obj00485 *)o)->fC));
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->B + off),
                              pair, (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        }
    }
    func_02194084(o + 0x11c, s, ((struct Obj00485 *)o)->fC);
    if (which == 0)
        *(Src * *)&((struct Obj00485 *)o)->f8 = s;
    else
        *(Src * *)&((struct Obj00485 *)o)->f8 = 0;
    func_020493D4((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]]);
    func_0204932C((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]], (void *)(*(int *)&((struct Obj00485 *)o)->f14));
    func_02194128(o + 0x11c, *(int *)&((struct Obj00485 *)o)->f14, o + 0x18);
}




void func_02193E54(unsigned char *p, unsigned char *q)
{
    int i;

    ((struct Obj12617 *)q)->f0 = 1;
    ((struct Obj12617 *)q)->f2 = p[0];
    if (p[1] == 0) {
        func_0218609C((char *)q);
        q += 8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    } else {
        func_021860B8((char *)q);
        q += 0xf8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    }
}




void func_02193EB4(V_02193BE4 *v)
{
    int i;

    if (v->f01 == 0 && v->f08 != 0) {
        for (i = 0; i < 10; i++)
            func_02193FBC((u16 *)(&v->f04[i]), &v->f08->e[i]);
    }
}




void func_02193EE8(V_02193BE4 *v)
{
    if (v->f01 == 0 && v->f08 != 0)
        func_021938FC(v);
}




E50 *func_02193EFC(V_02193BE4 *v, u32 key)
{
    int i;

    if (v->f04 != 0) {
        for (i = 0; i < 10; i++) {
            if (v->f04[i].f00 != 0 && key == func_021867B0(v->f04[i].f34))
                return &v->f04[i];
        }
    }
    return 0;
}
