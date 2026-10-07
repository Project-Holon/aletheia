/*
 * file:     field_palace_sys_p07.c
 * unit:     yes
 * function: func_021D2418, func_021D2440, func_021D2468, func_021D2524, func_021D25A4, func_021D25E8, func_021D25F4, func_021D26AC, func_021D26D0, func_021D2710, func_021D2750
 * address:  0x021D2418
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D2278  0x021D2278  thumb  ov021
 *   func_021D2358  0x021D2358  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   func_02008B94  0x02008B94  thumb
 *   func_02008B98  0x02008B98  thumb
 *   func_020056EC  0x020056EC  thumb
 *   d_021DD6D0     0x021DD6D0  data  a2
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb  ov021
 *   func_0204B100  0x0204B100  arm
 *   func_0202D7C8  0x0202D7C8  thumb
 *   func_0202D81C  0x0202D81C  thumb
 *   func_0202D7D8  0x0202D7D8  thumb
 *   func_02049238  0x02049238  arm
 *   func_0202D898  0x0202D898  thumb
 *   func_0204B294  0x0204B294  arm
 *   d_021DD710     0x021DD710  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013C60  0x02013C60  thumb
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_0216E2E8  0x0216E2E8  thumb  ov010
 *   func_021A35FC  0x021A35FC  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02162890  0x02162890  thumb  ov010
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218684C  0x0218684C  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 */
#include "../../matched/include/Obj04899.h"

struct Desc;
struct Obj;
struct Big;
struct Sub02008AECObj;
struct Ctx;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Bank;
struct ArcFile;
struct BigObj;
struct Rec;
struct Obj00020;
struct Record;
struct Obj18028;
struct Actor;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 h[31];
} Tbl;

typedef struct {
    u16 a, b, c, d;
} Pos_021D25F4;

typedef signed short   s16_021D26AC;

typedef signed char    s8;

typedef short          s16_021D2750;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 a;
    u16 b;
    s16_021D2750 c;
} Sub;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x14];
    u32 kind;
    Sub sub;
    u16 pad22;
} Rec;

typedef struct {
    u8 pad[0xB];
    u8 w;
    u8 h;
    u8 pad2[0xF];
} Info;

typedef struct {
    u16 a;
    u16 f2;
    s16_021D2750 c;
    u16 b;
    u16 f8;
} Loc;

typedef struct {
    s16_021D2750 x;
    s16_021D2750 y;
    s16_021D2750 z;
} Pos_021D2750;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021D2278(u32 a, int *seq, int *w);
extern int func_021D2358(u32 a, int *seq, int *w);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u8 func_02008B94(const struct Sub02008AECObj *obj);
extern u8 func_02008B98(const struct Sub02008AECObj *obj);
extern u32 func_020056EC(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5F4(void *p);
extern void func_0215897C(void *vm, void *task);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(u32 v, u32 a);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 heap);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern void func_02049238(u32 a);
extern u32 func_0202D898(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 heap);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020362DC(void);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F08(int *p);
extern u8 *func_02012944(void *p);
extern int func_0216BF9C(void *a, int i, void *b);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162740(u8 *p);
extern u16 func_02162744(u8 *p);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013C60(u32 id);
extern u32 func_021A3098(u8 *p);
extern void func_0216E2E8(const char *ctx, u32 id, struct Record *out);
extern void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u32 func_02188CFC(u8 *p);
extern void func_021A36BC(struct Obj18028 *p, void *a1);
extern void *func_021A3074(unsigned char *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern struct Rec *func_02162890(struct Ctx *c, void *a, int key);
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern u8 *func_02186844(u8 *t, int i);
extern u8 *func_0218684C(u8 *t, int i);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);
void *func_021D2418(void *a, u32 b);
void *func_021D2440(void *a, u32 b, u32 c);
int func_021D2468(u32 a, u32 b);
int func_021D2524(u32 a, u32 b);
void func_021D25A4(u32 *p);
void func_021D25E8(u32 *p);
void func_021D25F4(u32 *p, int a, int b, int c, int s0, int s1);
int func_021D26AC(u32 *a);
u32 func_021D26D0(u32 a, u32 *st, u32 *p);
u32 func_021D2710(u32 a, u32 b);
int func_021D2750(u32 a);
extern Tbl d_021DD6D0;
extern Pos_021D25F4 d_021DD710;


void *func_021D2418(void *a, u32 b)
{
    void *task = func_020122C0(a, 0, func_021D2278, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 0;
    return task;
}


void *func_021D2440(void *a, u32 b, u32 c)
{
    void *task = func_020122C0(a, 0, func_021D2358, 0x10);
    u32 *w = func_020124E8(task);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    return task;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D2468(u32 a, u32 b)
{
    u32 x, y, z, v, w, k;
    u16 *p6, *p4, *p5;
    Tbl t;

    x = (u32)func_0215A5E4((void *)b); /* int-typed on purpose: pointer local changes codegen */
    y = func_02159B10((void *)a, (void *)b);
    p6 = func_02159AE8((void *)a, (void *)b);
    p4 = func_02159AE8((void *)a, (void *)b);
    p5 = func_02159AE8((void *)a, (void *)b);
    t = d_021DD6D0;
    z = (u32)func_02008B08(func_02012EBC((struct Big *)x));
    v = func_021690D0(x);
    w = func_021690E0(x);
    k = func_02008B94((const struct Sub02008AECObj *)z);
    if (w == func_02008B98((const struct Sub02008AECObj *)z) && v == k) {
        *p6 = 0x34;
        *p4 = 0x53;
        *p5 = t.h[30];
    } else {
        u32 i = func_020056EC(y ? 0x1E : 0x16);
        *p6 = i + 0x16;
        *p4 = i + 0x35;
        *p5 = t.h[i];
    }
    return 0;
}


int func_021D2524(u32 a, u32 b)
{
    u32 r5, s1, s2, s3;
    void *r4;
    void *r6;
    void *r7;

    r6 = func_0215A5DC((void *)b);
    func_0201210C(r6);
    s1 = func_02159B10((void *)a, (void *)b);
    s2 = func_02159B10((void *)a, (void *)b);
    s3 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159B10((void *)a, (void *)b);
    r7 = func_0215A5F4((void *)b);
    r4 = func_020122C0(r6, 0, func_021D26D0, 0x18);
    r6 = func_020124E8(r4);
    func_021D25A4(r6);
    func_021D25F4(r6, s1, s2, s3, r5, 0);
    func_0215897C(r7, r4);
    return 1;
}


void func_021D25A4(u32 *p)
{
    p[0] = func_020450F0(1, 10, 3, 12, 12, 13, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[0])), 17);
    func_02045334((struct Descriptor *)p[0]);
    func_02045374((struct Cfg *)p[0]);
    func_0201F73C((void *)p[0], 1, 1, 13);
}


/*
 * Tail call with the leading word and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25E8(u32 *p)
{
    func_0201F7A8(p[0], 1);
}


/*
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * Addresses are Black-image addresses.
 */
void func_021D25F4(u32 *p, int a, int b, int c, int s0, int s1)
{
    Pos_021D25F4 loc;
    u32 t;

    p[1] = (u32)func_0204B100(1, 0, 0x8015);
    t = func_0202D7C8(0x8015);
    p[3] = func_0202D81C(t, a, b, c, s0, 0, 0, s1, 0, 0x8015);
    p[4] = (u32)func_0202D7D8((u32)t, (u32)a, (u32)b, (u32)c, (u32)s0, (u32)0, (u32)0, (u32)0, (u32)0, (u32)0x8015);
    func_02049238(t);
    p[5] = func_0202D898(a, b, c, s0, 0, 0, 1, 0, 0x8015);
    loc = d_021DD710;
    p[2] = (u32)func_0204B294((void *)p[1], p[3], p[4], p[5], &loc, 0, 0x8015);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D26AC(u32 *a)
{
func_0204B3B4((struct Obj *)(((struct Obj04899 *)((u8 *)(a)))->f8));
func_0204A8D4(((struct Obj04899 *)((u8 *)(a)))->fC);
func_0204ADA4(((struct Obj04899 *)((u8 *)(a)))->f10);
func_0204AFD8(((struct Obj04899 *)((u8 *)(a)))->f14);
return func_0204B1CC((struct Bank *)(((struct Obj04899 *)((u8 *)(a)))->f4));
}


u32 func_021D26D0(u32 a, u32 *st, u32 *p)
{
    switch (st[0]) {
    case 0:
        if (func_020362DC() & 3) {
            func_021D26AC(p);
            func_021D25E8(p);
            st[0]++;
        }
        break;
    case 1:
        func_020452E8((struct Descriptor *)p[0]);
        return 1;
    }
    return 0;
}


u32 func_021D2710(u32 a, u32 b)
{
    u32 r7;
    u16 *r5;
    u32 t;
    u32 r6;

    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02159AE8((void *)a, (void *)b);
    t = (u32)func_020120F4((const struct Ctx *)func_0215A5DC((void *)b));
    r6 = (u32)func_02012F08((int *)t);
    *r5 = func_0216BF9C((void *)r6, r7, func_02012944((void *)t));
    return 0;
}


/*
 * Spill slots follow declaration order (h, f, list, y, x, id, q, hdl, n from
 * the top down); the tail loops' counter and table pointer are block locals
 * declared j before t, which puts j in r4 and t in r5.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = (Sub *)e;` before `q = &e->sub;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * Addresses are Black-image addresses.
 */
int func_021D2750(u32 a)
{
    Info info;
    V3 v;
    Loc loc;
    Pos_021D2750 pos;
    u32 h, f;
    Rec *list;
    void *y;
    void *x;
    void *o;
    u32 id;
    Rec *e;
    Sub *q;
    int hdl;
    int i;
    int n;
    u8 *p;
    u32 r5;
    void *r4;

    h = (u32)func_020120F4((const struct Ctx *)a);
    f = func_02012844((const struct BigObj *)h);
    list = (Rec *)func_02162740((u8 *)f);
    n = func_02162744((u8 *)f);
    y = func_0201210C((void *)a);
    x = func_02188C7C((void *)y);
    o = func_02188CB4((void *)y);
    id = func_02188C9C(y);
    if ((int)func_02013C60((u16)id) == 0) {
        return 0;
    }
    if ((u32)(func_021A3098(o) - 2) <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && id != 0 && id != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        e = &list[i];
        if (e->kind == 0) {
            q = &e->sub;
            func_0216E2E8(x, e->f2, (struct Record *)&info);
            func_021A35FC(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
            if (e->sub.a <= pos.z && pos.z < e->sub.a + info.w) {
                if (q->b - info.h < pos.x && pos.x <= q->b) {
                    return 0;
                }
            }
        } else if (e->kind == 1) {
            q = &e->sub;
            if (func_02188CFC(y) == 1) {
                func_021A36BC(o, &loc);
                if (q->a == loc.a && q->b == loc.b && q->c == loc.c) {
                    return 0;
                }
            }
        }
    }
    if (func_02188CFC(y) == 0) {
        r4 = func_021A3074((void *)o);
        r5 = func_0201296C((const struct BigObj *)h);
        func_0216D88C(r4, (struct VecFx32 *)&v);
        if (func_02162890((struct Ctx *)f, (void *)r5, (int)(&v))) {
            return 0;
        }
    }
    if (id == 0 || id == 0x1A8) {
        int j;
        u8 *t;
        func_021A35FC(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
        hdl = (int)func_021867C4(0, 0x8015);
        t = func_02186830((struct ArcFile **)hdl, id != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            p = func_02186844(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            p = func_0218684C(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                func_0218683C(t);
                func_02186804((void **)hdl);
                return 0;
            }
        }
        func_0218683C(t);
        func_02186804((void **)hdl);
    }
    return 1;
}
