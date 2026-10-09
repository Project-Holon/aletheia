/*
 * file:     unit_021B6DC0.c
 * unit:     yes
 * function: func_021B6DC0, func_021B6DE4, func_021B6E0C, func_021B6E24, func_021B6E68, func_021B6EB0, func_021B6EE0, func_021B6F00, func_021B6F18, func_021B6F5C, func_021B6F88, func_021B6FE8, func_021B6FEC, func_021B6FF0, func_021B7020, func_021B7038, func_021B7068, func_021B707C, func_021B7080, func_021B7098, func_021B709C, func_021B70D4, func_021B70D8, func_021B716C, func_021B721C, func_021B72CC
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
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF18  0x0200BF18  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0204A298  0x0204A298  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 *   func_02007F68  0x02007F68  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 */
#include "../../matched/include/Obj12850.h"
#include "../../matched/include/Obj18097.h"
#include "../../matched/include/Obj18098.h"

struct Ctx;
struct Rec;
struct BigObj;
struct GiftMon;
struct Party;
struct PartyMon;
struct Blk37;
struct WordSet;
struct Big;
struct Blk34;
struct SaveBlock;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

struct MonEnt { u16 a; u16 b; u8 pad[0x20]; };

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct Ent {
    u32 k;
    u32 v;
} Ent;

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
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EEC4(struct WordSet *p, u32 i, u32 v);
extern void func_0201EED4(struct WordSet *p, u32 i, void *mon);
extern void *func_0201292C(const struct BigObj *p);
extern void func_02007E50(void *, u32, int, u32);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern u16 *func_0200BE48(void *sys);
extern u32 func_0200BF18(u32, u32);
extern void *func_02012EBC(struct Big *p);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02188C84(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern int func_02007F68(void *a, u32 b, u32 c, u32 d);
extern void *func_02158F74(void *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_020127A4(struct SaveBlock *p);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
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
int func_021B6F88(int a, int b, int c);
int func_021B6FE8(void);
int func_021B6FEC(void);
void func_021B6FF0(void *a, void *b, u32 *c);
int func_021B7020(void *a, void *b, u8 *c);
int func_021B7038(void *a, u32 *b, void *c);
int func_021B7068(u32 a, u32 b, u32 c, u32 d);
int func_021B707C(void);
int func_021B7080(u32 a, u32 b, u32 c, u32 d);
int func_021B7098(void);
int func_021B709C(void *a, u32 *b, void *c);
int func_021B70D4(void);
int func_021B70D8(u32 a, u32 b);
int func_021B716C(u32 a, u32 b);
int func_021B721C(u32 a, u32 b);
int func_021B72CC(u32 a, u32 b);
extern Entry d_021D997C[];
extern const u8 d_021D99D0[];




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
    struct MonEnt *t;
    int n;
    int m;
    int i;

    m = func_02012844((const struct BigObj *)a);
    t = (struct MonEnt *)func_02162740((u8 *)m);
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



int func_021B6F88(int a, int b, int c)
{
    void *m;
    int h;
    int r;

    h = (int)func_02012944(func_0215A5E4((void *)c));
    m = (void *)func_021B6EE0(c, b);
    r = 5;
    func_0201F02C((struct WordSet *)a, 0, (void *)h);
    if (m == 0) {
        func_0201EEC4((struct WordSet *)a, 1, 0);
    } else {
        if (func_02017E1C(m, 0x4c, 0) == 1)
            r = 0xb;
        else
            func_0201EED4((void *)a, 1, m);
        func_020307B0(m);
    }
    return r;
}


int func_021B6FE8(void) { return 6; }


/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   (`return func_02061B5C((int)d_02146B80)` with int types: same DIFF)
 */
int func_021B6FEC(void) { return 1; }



void func_021B6FF0(void *a, void *b, u32 *c)
{
    u32 v;
    void *r;
    u16 x;

    v = func_0215A5CC(a);
    r = func_0201292C(b);
    x = *c;
    if (x != 0 && x <= 0x272) {
        func_02007E50(r, x, 1, v);
    }
}




int func_021B7020(void *a, void *b, u8 *c)
{
    if (func_021B6EB0((u32 *)c, c[0xB3]) == 1) {
        return 4;
    }
    return 3;
}




int func_021B7038(void *a, u32 *b, void *c)
{
    void *t;
    u16 x;

    t = func_02012944(func_0215A5E4(c));
    x = *b;
    func_0201F02C(a, 0, t);
    func_0201EF40(a, 1, x);
    return 7;
}




int func_021B7068(u32 a, u32 b, u32 c, u32 d)
{
func_0201EF40((struct WordSet *)a, 0, ((((struct Obj18097 *)((u8 *)(b)))->f0 << 16) >> 16));
return 8;
}


int func_021B707C(void) { return 1; }


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7080(u32 a, u32 b, u32 c, u32 d)
{
return func_0200BF18((u32)func_0200BE48((void *)func_02012EBC((struct Big *)b)), ((struct Obj18098 *)((u8 *)(c)))->f0);
}


int func_021B7098(void) { return 5; }


int func_021B709C(void *a, u32 *b, void *c)
{
    void *t;
    void *r;
    u32 x;

    t = func_0215A5E4(c);
    func_0200BE48(func_02012EBC(t));
    r = func_02012944(t);
    x = *b;
    func_0201F02C(a, 0, r);
    func_0201F184(a, 1, x);
    return 9;
}


int func_021B70D4(void) { return 10; }




int func_021B70D8(u32 a, u32 b)
{
    u32 i;
    u32 v;
    u32 k;
    u32 idx;
    u16 *out;
    Ent *arr;
    u32 cnt;

    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    k = func_02159B10((void *)a, (void *)b);
    idx = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    arr = (Ent *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    i = 0;
    *out = 0;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            *out = arr[i].v;
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}




int func_021B716C(u32 a, u32 b)
{
    void *s;
    void *h;
    u32 v;
    u32 idx;
    u16 *out;
    u32 *arr;
    u32 cnt;
    u32 i;

    s = func_0215A5F4((void *)b);
    h = func_0215A5E4((void *)b);
    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)s))[1]));
    idx = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    h = func_0201292C(h);
    arr = (u32 *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    *out = 0;
    for (i = 0; i < cnt; i++) {
        if (func_02007F68(h, (u16)arr[i * 2], 1, v)) {
            *out = 1;
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}




/*
 * Same func_0204A298 lookup as func_021B72CC; the table is const so its
 * byte load is scheduled ahead of the `str r0,[sp]` that passes &cnt.
 */
int func_021B721C(u32 a, u32 b)
{
    void *s;
    u32 v;
    u32 k;
    u32 idx;
    u32 p1;
    u32 p2;
    u32 t;
    Ent *arr;
    u32 cnt;
    u32 i;

    s = func_0215A5F4((void *)b);
    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)s))[1]));
    k = func_02159B10((void *)a, (void *)b);
    idx = func_02159B10((void *)a, (void *)b);
    p1 = func_02159B10((void *)a, (void *)b);
    p2 = func_02159B10((void *)a, (void *)b);
    t = (u32)func_02158F74(s);
    arr = (Ent *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0201EFA4((struct WordSet *)t, p1, arr[i].v, p2, 0, 1);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}




/*
 * Same func_0204A298 lookup as func_021B70D8 / func_021B716C.  Here the
 * table byte d_021D99D0[idx] is loaded ahead of the `str r0,[sp]` that
 * passes &cnt: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 */
int func_021B72CC(u32 a, u32 b)
{
    void *h;
    u32 v;
    u32 k;
    u32 idx;
    Ent *arr;
    u32 cnt;
    u32 i;

    v = func_02188C84((u8 *)(((u32 *)func_02158F58((int)func_0215A5F4((void *)b)))[1]));
    k = func_02159B10((void *)a, (void *)b);
    idx = func_02159B10((void *)a, (void *)b);
    h = func_0215A5E4((void *)b);
    func_020127A4(h);
    arr = (Ent *)func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0200C278(func_02012F08(h), arr[i].v);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
