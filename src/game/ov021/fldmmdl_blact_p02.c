/*
 * file:     fldmmdl_blact_p02.c
 * unit:     yes
 * function: func_0219C814, func_0219C880, func_0219C8D4, func_0219C928, func_0219C98C, func_0219C9D0, func_0219C9DC, func_0219C9E0, func_0219CA00, func_0219CA34, func_0219CA40, func_0219CA6C, func_0219CA98
 * address:  0x0219C814
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C7EC  0x0219C7EC  thumb  ov021
 *   func_0219CFB0  0x0219CFB0  thumb  ov021
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0219CB98  0x0219CB98  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219D184  0x0219D184  thumb  ov021
 *   func_0219D3B4  0x0219D3B4  thumb  ov021
 *   func_02050468  0x02050468  arm
 *   func_0219C6B8  0x0219C6B8  thumb  ov021
 *   d_021D75D0  0x021D75D0  data  a4
 *   func_02030734  0x02030734  arm
 *   d_021DDD70  0x021DDD70  data ov021 a4
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj09509.h"
#include "../../matched/include/Obj17968.h"
#include "../../matched/include/Obj17969.h"

struct BbActSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef signed char    s8;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern void *func_0216E3C4(void *p);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern u16 func_0219C7EC(u32, u32);
extern void func_0219CFB0(u32, u32, u16 *, u16 *, u32, u32, u32);
extern u32 func_020508D8(u8 *o, u32 i);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_0216DFC4(void *a, u32 id);
extern void func_0219CB98(u8 *, u32);
extern u16 func_0216D598(void *p);
extern void func_0219D184(int *obj, int key);
extern int func_0219D3B4(u8 *, u32, u16);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_0219C6B8(u32, V3 *, int, u32, u16);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
int func_0219C814(u32 a, u16 *b);
void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
void func_0219C8D4(u32 o, u32 a);
int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
void func_0219C98C(u32 a, u16 *b);
void func_0219C9D0(u32 a, u32 b, u8 *p);
u32 func_0219C9DC(u8 *p);
void func_0219C9E0(u32 a, u16 *x, u16 *y);
void func_0219CA00(u32 *s, u32 n, u32 heap);
void func_0219CA34(u8 *p);
void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c);
void func_0219CA6C(Tbl *t, u16 k);
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);
extern u16 d_021D75D0[][2];
extern unsigned char d_021DDD70[];




int func_0219C814(u32 a, u16 *b)
{
    u32 m = func_0216D520(func_0216D67C((void *)a));
    u16 *p = func_0216E3C4((void *)a);
    u16 loc[2];
    func_0219CBD4(m, *p, (u32)(&loc[1]), (u32)(&loc[0]));
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = func_0219C7EC(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    func_0219CFB0(m, a, p, b, 0, 0, 0);
    return 0;
}




/*
 * Former blocker (now filed in src/matched/arm9): the only unresolved site is the call to func_020508D8
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (Ilias's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 func_020508D8(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * Addresses are Black-image addresses.
 */
void func_0219C880(u8 *o, u32 a, u32 b, u32 c)
{
    u16 v[2];
    if (func_0219CBD4((u32)o, c, (u32)(&v[1]), (u32)(&v[0])) == 1) {
        if (v[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj00429 *)o)->f4), b);
            func_02050278((struct BbActSys *)(((struct Obj00429 *)o)->f4), t, 1);
        }
        if (v[0] & 1) {
            if (func_0216DFC4((void *)a, c) == 0)
                func_0219CB98(o, c);
        }
    }
}




/*
 * Addresses are Black-image addresses.
 */
void func_0219C8D4(u32 o, u32 a)
{
    u32 t = func_0216D598((void *)o);
    u8 *c = (u8 *)func_0216D520(func_0216D67C((void *)o));
    if (a == 0xFFFF) {
        func_0219D184((int *)c, (u32)o);
        return;
    }
    if (func_0219D3B4(c, o, a) != 1) {
        func_0219C880(c, o, (u16)a, t);
        func_02050468((struct BbActSys *)(((struct Obj00429 *)c)->f4), a, 1);
    }
}




/* b is const: that is what lets the b[7]/b[9] loads schedule above the
 * outgoing stack-argument store of v. */
int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1)
{
    u16 v;
    u32 t = func_0216D520((void *)a);
    func_0219CBD4(t, *(const u16 *)&((struct Obj03118 *)b)->f0, (u32)(&v), (u32)c);
    if (!(*c & 2)) {
        c[1] = func_0219C6B8(a, d, b[7], b[9], v);
        return 1;
    }
    c[1] = 0xFFFF;
    func_0219CFB0(t, 0, (u16 *)b, &c[1], s0, s1, (u32)d);
    return 0;
}




void func_0219C98C(u32 a, u16 *b)
{
    u8 *c = (u8 *)func_0216D520((void *)a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj09509 *)c)->f4), b[1]);
            func_02050278((struct BbActSys *)(((struct Obj09509 *)c)->f4), t, 1);
        }
        func_02050468((struct BbActSys *)(((struct Obj09509 *)c)->f4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}




void func_0219C9D0(u32 a, u32 b, u8 *p)
{
    *p |= 1;
}




/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_0219C9DC(u8 *p)
{
    return ((struct Obj17968 *)p)->f4;
}




void func_0219C9E0(u32 a, u16 *x, u16 *y)
{
    u8 *d = func_0216E3C4((void *)a);
    u16 *t = d_021D75D0[d[7]];
    *x = t[0];
    *y = t[1];
}




void func_0219CA00(u32 *s, u32 n, u32 heap)
{
    u16 *p = (u16 *)func_02030734(heap, n * 8, 1, (const char *)d_021DDD70, 0x484);
    s[0] = n;
    s[1] = (u32)p;
    do {
        p[0] = 0xFFFF;
        p[1] = 0xFFFF;
        p += 4;
    } while (--n);
}




/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CA34(u8 *p)
{
    func_020307B0((void *)(((struct Obj17969 *)p)->f4));
}



void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == 0xFFFF) {
            e->a = a;
            e->b = b;
            e->c = c;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}



void func_0219CA6C(Tbl *t, u16 k)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == k) {
            e->a = 0xFFFF;
            e->b = 0xFFFF;
            e->c = 0;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}



/*
 * Linear search of an 8-byte-entry table (count at +0, entries at *(+4)).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b)
{
    int i = 0;
    u16 *e = (u16 *)o[1];
    if (a) *a = 0xFFFF;
    do {
        if (e[0] == key) {
            if (a) *a = e[1];
            if (b) *b = e[2];
            return 1;
        }
        i++;
        e += 4;
    } while (i < (int)o[0]);
    return 0;
}
