/*
 * file:     unit_02184C78_p01.c
 * unit:     yes
 * function: func_02184C78, func_02184CEC, func_02184D38, func_02184D90, func_02184DE8, func_02184E40, func_02184E94, func_02184EEC, func_02184F40, func_02184F88
 * address:  0x02184C78
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02173744  0x02173744  thumb  ov012
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BF66C  0x021BF66C  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAAF0  0x021AAAF0  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02184388  0x02184388  thumb  ov020
 *   func_020141A8  0x020141A8  thumb
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02184730  0x02184730  thumb  ov020
 *   func_020128B8  0x020128B8  thumb
 *   func_021847CC  0x021847CC  thumb  ov020
 *   func_02185F18  0x02185F18  thumb  ov020
 *   func_02184894  0x02184894  thumb  ov020
 *   func_02012914  0x02012914  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_0218495C  0x0218495C  thumb  ov020
 *   func_02012894  0x02012894  thumb
 *   func_02184A14  0x02184A14  thumb  ov020
 */
#include "../../matched/include/Obj00248.h"

struct Evt;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct t;
struct Rec1C;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct { u16 f0; u16 f2; s16 f4; u16 f6; } Q;

typedef struct { int x, y, z; } Vec;

typedef struct { int f[7]; } S7;

void func_02012374(struct Evt *evt, struct Evt **out);
void func_02034A5C(int id);
int func_02034AC4(signed int id);
void *func_02161824(void *a, void *b);
void func_02173744(int a);
void *func_02184360(u8 *p, int value);
void *func_021BF66C(int a0, void *p, int a2);
void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
u8 func_02012984(const struct BigObj *p);
u16 func_02188C9C(u8 *p);
u32 func_02188CE8(u8 *p);
void func_021AAAF0(int x, int y);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
u32 func_020142A4(u32 idx);
int func_02184388(int a, int *state, u8 *p);
void func_02014184(void *o, int a, int s, int x, int y, int z);
void func_020141A8(struct t *p, int b, int d, u16 g, u16 i, s16 h);
int func_02184504(int a, int *state, u8 *p);
int func_02184730(int ctx, int *state, u8 *p);
struct Rec1C *func_020128B8(const struct BigObj *p);
int func_021847CC(int ctx, int *state, u8 *p);
void func_02185F18(void *a, void *b);
int func_02184894(void *a, int *state, struct Obj *o);
u16 func_02012914(const struct BigObj *p);
u16 func_02159F94(int a);
void func_02014204(struct t *p, int id);
int func_0218495C(int ctx, int *state, u8 *p);
struct Rec1C *func_02012894(const struct BigObj *p);
int func_02184A14(int ctx, int *state, u8 *p);
int func_02184C78(void *ctx, int *st, int *p);
void func_02184CEC(void **o, void *p);
void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t);
void *func_02184DE8(void *p, int unused, int a, const Q *q, u16 s, int t);
void *func_02184E40(void *p, int u, const Vec *v, s16 b, const int *s);
void *func_02184E94(int u, void *p);
void *func_02184EEC(void *p);
void *func_02184F40(void *p);
void *func_02184F88(void *p);
extern char ov011_id[];
extern char ov012_id[];


int func_02184C78(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];

    switch (*st) {
    case 0:
        func_02012374(ctx, func_02161824((void *)a, (void *)b));
        (*st)++;
        break;
    case 1:
        func_02034A5C((int)ov011_id);
        func_02034AC4((int)ov012_id);
        func_02012374(ctx, func_02184360((u8 *)p, 4));
        (*st)++;
        break;
    case 2:
        func_02173744(a);
        (*st)++;
        break;
    case 3:
        func_02012374(ctx, func_021BF66C((int)ctx, (void *)a, b));
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


void func_02184CEC(void **o, void *p)
{
    void *a = func_020120F4(p);
    void *b = func_0201210C(p);
    u16 c = func_02012984(a);

    o[0] = p;
    o[1] = a;
    o[2] = b;
    ((struct Obj00248 *)o)->fC = func_02188C9C(b);
    ((struct Obj00248 *)o)->f40 = 0;
    ((struct Obj00248 *)o)->f44 = 0;
    ((struct Obj00248 *)o)->f48 = c;
    ((struct Obj00248 *)o)->f4A = c;
    func_021AAAF0(func_02188CE8(o[2]), 1);
}


/*
 * The ARM9 leaf 0x02014184 is resolved by its matched shard.
 *
 * What made it byte-correct: `const int *q` (see the EXACT twins
 * ov020_func_02184D90.c / ov020_func_02184DE8.c).
 */
void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_02014184(r4 + 0x10, a, (s16)s, q[0], q[1], q[2]);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}


/*
 * Allocator with callback (0x9c-byte work area), then the 0x18-byte record
 * at +0x10 initialised by func_020141A8 from three u16 fields of q.
 * What closed it: `const Q *q`. Without const the q field loads are kept
 * below the outgoing stack-argument stores and `adds r1,r7` is scheduled
 * first; const lets them hoist (docs/notes/pkt_ov020_02184D38.c.txt has
 * the earlier near miss). The u16 stack parameter s fixes the frame.
 */
void *func_02184D90(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_020141A8((struct t *)(r4 + 0x10), a, (s16)s, q->f0, q->f6, q->f4);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}


void *func_02184DE8(void *p, int unused, int a, const Q *q, u16 s, int t)
{
    void *r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    s = func_020142A4(s);
    func_020141A8((struct t *)(r4 + 0x10), a, (s16)s, q->f0, q->f6, q->f4);
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = t;
    return r0v;
}

static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x; d->y = y; d->z = z;
}

void *func_02184E40(void *p, int u, const Vec *v, s16 b, const int *s)
{
    void *r0v = func_020122C0(p, 0, func_02184730, 0x9c);
    char *r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    func_02014184(r4 + 0x10, b, 1, s[0], s[1], s[2]);
    vset((Vec *)(r4 + 0x34), v->x, v->y, v->z);
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}


void *func_02184E94(int u, void *p)
{
    void *r0v = func_020122C0(p, 0, func_021847CC, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_020128B8(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    func_02185F18(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}


void *func_02184EEC(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184894, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_020128B8(((struct Obj00248 *)r4)->f4);
    *(S7 *)(r4 + 0x10) = *src;
    func_02185F18(((struct Obj00248 *)r4)->f4, r4 + 0x10);
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f40 = 1;
    return r0v;
}


void *func_02184F40(void *p)
{
    void *r6 = (void *)func_02012914(func_020120F4(p));
    void *r0v = func_020122C0(p, 0, func_0218495C, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    func_02014204((struct t *)(r4 + 0x10), func_02159F94((int)r6));
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}


/*
 * Allocator + base init, copies a seven-word record fetched through the node's
 * fourth word, then fills status fields.
 */
void *func_02184F88(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184A14, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC((void **)r4, p);
    src = (S7 *)func_02012894((const struct BigObj *)(*(int *)&((struct Obj00248 *)r4)->f4));
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f18 = 2;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}
