/*
 * file:     unit_02184C78_p04.c
 * unit:     yes
 * function: func_021854CC, func_02185534, func_02185588, func_0218562C, func_02185694
 * address:  0x021854CC
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
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185EB0  0x02185EB0  thumb  ov020
 *   func_02184584  0x02184584  thumb  ov020
 *   func_020142A4  0x020142A4  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0218466C  0x0218466C  thumb  ov020
 *   func_02012914  0x02012914  thumb
 *   func_02159FA8  0x02159FA8  thumb  ov010
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_02014204  0x02014204  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_0216446C  0x0216446C  thumb  ov010
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C110  0x0202C110  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 */
#include "../../matched/include/Obj00248.h"

struct Ctx;
struct Desc;
struct Obj;
struct Rec44;
struct SaveBlock;
struct BigObj;
struct Rec1C;
struct t;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

typedef struct { int a, b, c; } S3;

typedef short s16;

typedef struct E { char pad[0x86]; u16 lo : 3; u16 hi : 13; } E;

typedef struct V3 { u32 x, y, z; } V3;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
void *func_020127A4(struct SaveBlock *p);
void func_02012B2C(struct Rec44 *p, u32 v);
int func_02184504(int a, int *state, u8 *p);
void func_02184CEC(void **o, void *p);
void func_02185EB0(int a, u16 *p);
int func_02184584(int ctx, int *state, u8 *p);
u32 func_020142A4(u32 idx);
void func_02014184(void *d, int a, short b, int c, int e, int f);
extern u32 func_02013D5C(u32 id);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_0218466C(int ctx, int *state, u8 *p);
u16 func_02012914(const struct BigObj *p);
void func_02159FA8(int a, int b);
u16 func_02159F94(int a);
void func_02014204(struct t *p, int id);
void func_020128C0(struct BigObj *p, const struct Rec1C *src);
void func_02185B70(void *p);
void func_02185A68(void *a, int b);
void func_021857C0(int a, void *b);
void func_0202735C(u32 a0, u32 a1);
void func_02168EEC(int a);
int func_0216446C(int a, int b);
u32 func_02012134(u32 *p);
u32 func_0202B578(u32 *p);
void func_0202C110(void *p);
u8 func_02012984(const struct BigObj *p);
unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
void *func_020298A0(void *a, u32 b, u32 c, u32 d);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_020145FC(int a);
void *func_021854CC(void *p, int u, int u2, const S7 *src, u16 h);
void *func_02185534(void *p, int a1, int a2, const S3 *a3, short a4);
void *func_02185588(void *owner, u16 id, const V3 *pos);
void func_0218562C(int a);
int func_02185694(int a0, int *st, int *p);


void *func_021854CC(void *p, int u, int u2, const S7 *src, u16 h)
{
    void *r7 = func_020120F4(p);
    void *r0v;
    char *r4;

    func_02012B2C(func_020127A4(r7), 0);
    r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *src;
    ((struct Obj00248 *)r4)->f18 = h;
    ((struct Obj00248 *)r4)->f2C = 0;
    ((struct Obj00248 *)r4)->f30 = 1;
    func_02185EB0((int)r7, (u16 *)(r4 + 0x10));
    return r0v;
}


/*
 * Blocked (evidence class: none, unresolved callee site) by unlabelled arm9 leaf
 * 0x02014184 (Ilias's), verified EXACT in a scratch file with `one --region arm9 --thumb`:
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 * Lever: `const S3 *a3` (as in ov020 func_02184E40) and the callee's third
 * parameter declared short.
 */
void *func_02185534(void *p, int a1, int a2, const S3 *a3, short a4)
{
    void *r0v = func_020122C0(p, 0, func_02184584, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    *(u16 *)&a4 = func_020142A4(*(u16 *)&a4);
    func_02014184(r4 + 0x10, a2, a4, a3->a, a3->b, a3->c);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}


/*
 * 2026-10-05 (wD9r lane42): EXACT. Two source facts closed the last 18 bytes:
 *   (1) id is a u16 parameter, and func_02014184 takes a u16 id (its matched definition in
 *       src/matched/arm9/func_02014184.c). This fixed the asrs/ldr order at the 02014184 call.
 *   (2) the e->lo bitfield is read into its own block local (`int lo = e->lo; r = lo - getter;`),
 *       the same shape as sibling 02185140 (`r2 = r5 - func_02012B58(r4)`). This fixed the
 *       owner/r colour swap (owner r4, r r5).
 */
void *func_02185588(void *owner, u16 id, const V3 *pos)
{
    V3 v = *pos;
    void *ctx = func_020120F4((const struct Ctx *)owner);
    void *node = func_020122C0(owner, 0, (void *)func_0218466C, 0x9C);
    char *x = func_020124E8((struct Obj *)node);
    int r = 0;

    if (func_02013D5C(id) == 1) {
        E *e = (E *)func_02158344(func_02012138((const struct Ctx *)owner));
        if (e != 0) {
            int lo = e->lo;
            r = lo - func_02012B58(ctx);
            if (r < 0)
                r += *(u8 *)((char *)e + 0x902);
        }
        v.x += (u32)r << 22;
    }
    func_02184CEC((void **)x, owner);
    func_02014184(x + 0x10, id, (s16)func_020142A4(0), v.x, v.y, v.z);
    *(u32 *)(x + 0x2C) = 0;
    *(u32 *)(x + 0x40) = 0;
    return node;
}


void func_0218562C(int a)
{
    int r4 = (int)func_020120F4((const struct Ctx *)a);
    struct { char b[0x1c]; int f; u16 h; char pad[0x16]; } l;

    func_02159FA8(func_02012914((const struct BigObj *)r4), (int)(&l.f));
    func_02014204((struct t *)l.b, func_02159F94(func_02012914((const struct BigObj *)r4)));
    func_020128C0((struct BigObj *)r4, (const struct Rec1C *)l.b);
    func_02185B70((void *)a);
    func_02185A68((void *)a, l.h);
    func_021857C0(a, &l.f);
    func_0202735C(l.h, r4);
    func_02168EEC(r4);
    func_0216446C(r4, l.h);
}


/*
 * Blocked (evidence class: none, unresolved callee sites) by two unlabelled arm9
 * leaves inside labelled arm9 functions (Ilias's), each verified EXACT in a
 * scratch file with `one --region arm9 --thumb`:
 *   0x0202B578: int func_0202B578(int *p) { return p[8]; }
 *   0x02029DF4: void func_02029DF4(void) { func_02029EB4(); }   (thumb tail-call
 *               stub, .word 0x02029EB5)
 */
int func_02185694(int a0, int *st, int *p)
{
    int r;

    switch (st[0]) {
    case 0:
        func_0218562C(p[0]);
        st[0]++;
        break;
    case 1:
        func_02012B2C(func_020127A4(func_020120F4((const struct Ctx *)p[0])), 0);
        func_0202C110((void *)func_0202B578((u32 *)func_02012134((u32 *)p[0])));
        r = func_02029DF4((void *)p[1], ((short *)p)[6], func_02012984((const struct BigObj *)p[1]));
        r = (int)func_020298A0((void *)p[0], r, 0, 0x3c);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 2:
        r = func_020145FC(p[0]);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
