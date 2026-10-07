/*
 * file:     unit_02184C78_p02.c
 * unit:     yes
 * function: func_021850A8, func_021850FC, func_02185140
 * address:  0x021850A8
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02014184  0x02014184  thumb
 *   func_020142A4  0x020142A4  thumb
 *   func_02184C78  0x02184C78  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_020120F4  0x020120F4  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02184BF8  0x02184BF8  thumb  ov020
 *   func_0201210C  0x0201210C  thumb
 *   func_020128E4  0x020128E4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_021852F0  0x021852F0  thumb  ov020
 *   func_02185BFC  0x02185BFC  thumb  ov020
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158590  0x02158590  thumb  ov010
 *   func_02176230  0x02176230  thumb  ov011
 */
struct Desc;
struct Obj;
struct BigObj;
struct Ctx;
struct Rec1C;
struct Big;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct { int f[7]; } S7;

typedef unsigned long long u64;

typedef struct { int f0; int f4; int f8; } S3;

struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02014184(void *d, int a, s16 b, int c, int e, int f);
u32 func_020142A4(u32 idx);
int func_02184C78(void *ctx, int *st, int *p);
void func_02184CEC(void **o, void *p);
void *func_020120F4(const struct Ctx *p);
struct Rec1C *func_02012894(const struct BigObj *p);
int func_02184BF8(void *ctx, int *st, int *p);
void *func_0201210C(const struct Ctx *p);
void func_020128E4(struct BigObj *p, const struct Rec1C *src);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
int func_02012FCC(int p0);
unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
u32 func_02012138(const struct Ctx *p);
u8 func_02012B58(const struct BigObj *p);
void func_021852F0(void *dst, int x);
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4);
int func_02158344(int a0);
int func_02158590(void *p);
u8 func_02176230(u8 *p, u8 *q);
void *func_021850A8(void *p);
void *func_021850FC(void *p, u8 *pos);
void *func_02185140(void *a, int b, S3 *c, int d);


/*
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, Ilias's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 */
void *func_021850A8(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184C78, 0x9c);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    func_02014184(r4 + 0x10, 0x1A6, func_020142A4(0), 0x2E << 14, 0, 0x3E << 14);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}


/*
 * Allocator with callback, then a seven-word record copied from a global-ish
 * accessor into offset 0x10.
 */
void *func_021850FC(void *p, u8 *pos)
{
    S7 *r5 = (S7 *)func_02012894(func_020120F4(p));
    void *r0v = func_020122C0(p, 0, func_02184BF8, 0x9C);
    char *r4 = func_020124E8(r0v);

    func_02184CEC((void **)r4, p);
    *(S7 *)(r4 + 0x10) = *r5;
    return r0v;
}


/*
 *           witness: an unlabelled arm9 Thumb leaf (printed as .word data
 *           after func_020140F8), Ilias's to file. Evidence class: label /
 *           sole-ref/code. Verified C for the leaf, per
 *           ov020_func_021852F0.c:
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 */
void *func_02185140(void *a, int b, S3 *c, int d)
{
    int h;
    void *r4;
    S3 t;
    S7 w;
    S7 out;
    int r6;
    int r5;
    int r2;
    void *q;
    u8 *r7;

    h = (int)func_0201210C(a);
    r4 = func_020120F4(a);
    t = *c;
    r6 = 0;
    func_021852F0(&w, h);
    func_020128E4(r4, (const struct Rec1C *)(&w));
    q = func_0200BE48(func_02012EBC(r4));
    func_0200BFA4(q, (void *)func_02012FCC((int)r4), 0);
    r7 = (u8 *)func_02158344(func_02012138(a));
    if (r7 == 0 || func_02158590(r4) == 0) {
        r5 = 0;
        r2 = 0;
    } else {
        r5 = func_02176230(r7, r7 + 0x1AC);
        r2 = r5 - func_02012B58(r4);
        if (r2 < 0)
            r2 += r7[0x902];
        r6 = 0x10000;
    }
    t.f0 += r6 + (r2 << 22);
    func_02014184(&out, b, func_020142A4(0), t.f0, t.f4, t.f8);
    return func_02185BFC(a, h, &out, d, r5);
}
