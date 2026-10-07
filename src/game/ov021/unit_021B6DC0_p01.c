/*
 * file:     unit_021B6DC0_p01.c
 * unit:     yes
 * function: func_021B6DC0, func_021B6DE4, func_021B6E0C, func_021B6E24, func_021B6E68, func_021B6EB0, func_021B6EE0, func_021B6F00, func_021B6F18, func_021B6F5C
 * address:  0x021B6DC0
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
 *   d_021D997C     0x021D997C  data  a4
 *   func_0216D588  0x0216D588  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02157E9C  0x02157E9C  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02017E1C  0x02017E1C  thumb
 */
#include "../../matched/include/Obj12850.h"

struct Ctx;
struct Rec;
struct BigObj;
struct GiftMon;
struct Party;
struct PartyMon;
struct Blk37;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

struct Ent { u16 a; u16 b; u8 pad[0x20]; };

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_0216D588(void *);
extern void *func_02188C7C(u8 *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D598(void *p);
u32 func_02012844(const struct BigObj *p);
u32 func_02162740(u8 *p);
u16 func_02162744(u8 *p);
extern void *func_02157E9C(const struct GiftMon *g, int heap, void *save);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
int func_021B6DC0(int idx, void *x, void *y, void *z);
u16 func_021B6DE4(void *a, void *b);
u16 func_021B6E0C(void *a);
void *func_021B6E24(void *a);
int func_021B6E68(int a);
int func_021B6EB0(u32 *o, int k);
int func_021B6EE0(u32 a, u32 b);
int func_021B6F00(void *a, void *b);
void func_021B6F18(int a, int b, int c);
int func_021B6F5C(void *a, void *b, void *c);
extern Entry d_021D997C[];


int func_021B6DC0(int idx, void *x, void *y, void *z)
{
    int (*fn)(void *, void *, void *) = d_021D997C[idx].fn;

    if (z != 0 && fn != 0) {
        return fn(x, y, z);
    }
    return 0;
}


u16 func_021B6DE4(void *a, void *b)
{
    void *t;
    int r;

    t = func_021B6E24(a);
    if (t != 0) {
        return func_0216D588(t);
    }
    r = func_021B6E68((int)b);
    if (r >= 0) {
        return r;
    }
    return 0;
}


u16 func_021B6E0C(void *a)
{
    return func_021B6E24(a) != 0 ? 1 : 0;
}


/*
 * Addresses are Black-image addresses.
 */
void *func_021B6E24(void *a)
{
    unsigned long it = 0;
    void *rec;
    void *list;

    list = func_02188C7C(a);
    while (func_0216DD1C(list, (struct Rec **)(&rec), (u32 *)(&it)) == 1) {
        if (func_0216D598(rec) == 0x46)
            return rec;
    }
    return 0;
}


/*
 * Search the 0x24-byte records for the one whose second halfword is 0x46
 * and return its first.  The return reads through a byte offset rather
 * than t[i].a: the subscript form lets the compiler CSE t + i*0x24 into
 * one register (product in r2, ldrh r0,[r3]); the byte-offset form keeps
 * only the product live and loads ldrh r0,[r4,r3] as the original does.
 */
int func_021B6E68(int a)
{
    struct Ent *t;
    int n;
    int m;
    int i;

    m = func_02012844((const struct BigObj *)a);
    t = (struct Ent *)func_02162740((u8 *)m);
    n = func_02162744((u8 *)m);
    if (t == 0 || n == 0) {
        return -1;
    }
    for (i = 0; i < n; i++) {
        if (t[i].b == 0x46) {
            return *(u16 *)((u8 *)t + i * 0x24);
        }
    }
    return -1;
}


int func_021B6EB0(u32 *o, int k)
{
    if (k != 2) {
        return 0;
    }
    if (((struct Obj12850 *)o)->fB0 != 0x7FE) {
        return 0;
    }
    if (o[0] == 0x23E) {
        return 1;
    }
    return 0;
}


int func_021B6EE0(u32 a, u32 b)
{
return (int)func_02157E9C((const struct GiftMon *)b, func_0215A5CC((void *)a), func_0215A5E4((void *)a));
}


int func_021B6F00(void *a, void *b)
{
    if ((int)func_0201AA18(func_02012934(b)) < 6) {
        return 1;
    }
    return 0;
}


void func_021B6F18(int a, int b, int c)
{
    void *l;
    void *m;

    l = func_02012934((void *)b);
    m = (void *)func_021B6EE0(a, c);
    if ((int)func_0201AA18(l) < 6 && m != 0) {
        func_0201A98C(l, m);
        func_0200CDE0(func_0200CA1C((void *)b), m);
        func_020307B0(m);
    }
}


int func_021B6F5C(void *a, void *b, void *c)
{
    void *t;
    int r;

    t = (void *)func_021B6EE0((u32)a, (u32)c);
    if (t == 0) {
        return 1;
    }
    r = func_02017E1C(t, 0x4C, 0);
    func_020307B0(t);
    return r == 1 ? 2 : 1;
}
