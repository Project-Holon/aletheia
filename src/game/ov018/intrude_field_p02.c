/*
 * file:     intrude_field_p02.c
 * unit:     yes
 * function: func_0217B214, func_0217B410, func_0217B4D8
 * address:  0x0217B214
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021584A4  0x021584A4  thumb
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02175BE4  0x02175BE4  thumb  ov011
 *   func_02175548  0x02175548  thumb
 *   func_0217C758  0x0217C758  thumb
 *   func_0217C820  0x0217C820  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188D20  0x02188D20  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190758  0x02190758  thumb
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021BC5A0  0x021BC5A0  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0217B5DC  0x0217B5DC  thumb  ov018
 *   func_0216B340  0x0216B340  thumb  ov010
 *   d_02182B90     0x02182B90  data   a4
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0217B044  0x0217B044  thumb  ov018
 *   func_0217B1DC  0x0217B1DC  thumb  ov018
 */
struct Obj;
struct Ctx;
struct Sub24;
struct Rec44;
struct WordSet;
struct U16Vec;
struct MsgBank;
struct BigObj;
struct Rec;
struct VecFx32;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    struct WordSet *f10;
    u16 f14;
    u8 f16;
    u8 f17;
    int f18;
} Obj;

typedef struct {
    u8 pad0[0x86];
    u16 slot : 3;
    u16 rest : 13;
} Peer;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Tmp;

typedef struct { int x, y, z; } V12;

extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_02012B58(const struct BigObj *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020362DC(void);
extern int func_02158344(int a0);
extern int func_021584A4();
extern int func_0216D3CC(int a0);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern int func_02175BE4(void *a);
extern void func_02175548();
extern void func_0217C758();
extern int func_0217C820();
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188C54(u8 *p);
extern int func_02188D20();
extern int func_02188C9C();
extern int func_021904B0(u32 a, u32 b);
extern int func_021907A8();
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern void func_02190758();
extern int func_0219077C(u8 *p);
extern int func_02190728(void *a);
extern void func_021BC5A0();
extern u8 *func_020120F8(const struct Ctx *p);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_0217B5DC();
extern struct Desc *func_0216B340(int a0, int a1, void *a2, int a3, int a4);
extern int func_0203D1B4();
extern void *func_0217B044(void *a, int b, int c, int d, int e, int f);
extern void *func_0217B1DC();
int func_0217B214(int a0, int *state, Obj *o);
int func_0217B410(int a0, int a1, int a2);
void *func_0217B4D8(int a0, int a1, int a2, int *a3, int a4, u16 a5);
extern const V12 d_02182B90;


int func_0217B214(int a0, int *state, Obj *o)
{
    void *w;
    int h;
    void *ctx;
    Peer *p;
    int t;
    struct U16Vec *a;
    void *b;
    Tmp tmp;

    w = func_020124E4((struct Obj *)a0);
    h = func_02012138(w);
    ctx = func_020120F4(w);
    p = (Peer *)func_02158344(h);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(o->f0));
        *state += 1;
        break;
    case 1:
        if (func_0216D3CC(o->f4) == 0)
            break;
        if (p == 0) {
            *state = 6;
            break;
        }
        if (func_02175BE4((u8 *)p + 0x1AC) == 1) {
            o->f16 = 1;
            func_0217C758(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 0);
        } else if (func_021584A4(h, ctx, o->f14) == 1) {
            func_0217C758(&o->f18, w, o->f0, p, 0, 0, 0, o->f14, 1);
        } else {
            func_02175548(func_02012944(ctx), &tmp.h2, &tmp.b1, &tmp.b0);
            func_0217C758(&o->f18, w, o->f0, p, tmp.h2, tmp.b1, tmp.b0, o->f14, 1);
        }
        *state += 1;
        break;
    case 2:
        if (func_0217C820(&o->f18, p) == 1)
            *state += 1;
        break;
    case 3:
        if (p == 0) {
            *state = 6;
            break;
        }
        t = func_02188C54(o->f0);
        o->f8 = func_021904B0(t, 0x2D);
        o->fc = func_021907A8(t, o->f8);
        o->f10 = func_0201EC64(4);
        if (p->slot == func_02012B58(ctx)) {
            if (o->f16 == 1)
                func_02190740(o->fc, 0, 0, 0x4F);
            else
                func_02190740(o->fc, 0, 0, 0x4E);
        } else {
            a = func_020457B0(0x100, 0x15);
            func_0201F02C(o->f10, 0, func_02012950(ctx, p->slot));
            if (o->f16 == 1)
                b = func_02045EC0((struct MsgBank *)o->f8, 0x50);
            else
                b = func_02045EC0((struct MsgBank *)o->f8, 0x51);
            func_0201F250(o->f10, a, b);
            func_02190758(o->fc, 0, 0, a);
            func_02045808(b);
            func_02045808(a);
        }
        *state += 1;
        break;
    case 4:
        if (func_0219077C((u8 *)o->fc) == 1) {
            t = func_02188D20(o->f0);
            func_021BC5A0(t, func_02188C9C(o->f0));
            *state += 1;
        }
        break;
    case 5:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 6:
        if (o->fc != 0) {
            func_02190728((void *)o->fc);
            func_02045C04((struct Rec *)o->f8);
            func_0201ED04(o->f10);
        }
        func_0216D9E4(func_02188C7C(o->f0));
        return 1;
    }
    return 0;
}


int func_0217B410(int a0, int a1, int a2)
{
    int h;
    int w;
    int i;
    int base;
    V12 pos;
    V12 v;

    h = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a1));
    w = func_02158344(func_02012138((const struct Ctx *)a1));
    if (func_02013D5C(h) == 0)
        return 0;
    func_021A3038((unsigned char *)a2, (struct VecFx32 *)&pos);
    for (i = 0; i < 3; i++) {
        if (pos.x >= (i << 22) + 0x1F8000 && pos.x <= (i << 22) + 0x1F8000 && pos.z >= 0x2C8000 && pos.z <= 0x2C8000)
            return func_0217B5DC(a1, a0, w);
    }
    base = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (pos.x >= base && pos.x < base + 0x20000 && pos.z == 0x158000) {
            v = d_02182B90;
            v.x += pos.x - base;
            return (int)func_0216B340(a1, 1, &v, 0, 4); /* int-typed on purpose: function returns int */
        }
        base += 0x400000;
    }
    return 0;
}


void *func_0217B4D8(int a0, int a1, int a2, int *a3, int a4, u16 a5)
{
    u8 *p;
    int r;
    int col;
    int x;
    int n;
    int sub;

    p = (u8 *)func_02158344(func_02012138((const struct Ctx *)a0));
    r = 9;
    x = *a3;
    n = 1;
    if (p)
        n = p[0x902];
    if (x <= 0) {
        x += n << 22;
    } else if (x >= n << 22) {
        x -= n << 22;
    }
    col = ((x >> 12) / 16) % 64;
    sub = x % 0x400000;
    if (a5 == 2) {
        if ((a4 != 3 || (a4 == 3 && sub <= 0x8000)) && col == 0)
            r = 2;
    } else if (a5 == 3) {
        if ((a4 != 2 || (a4 == 2 && sub >= 0x3F8000)) && col == 0x3F)
            r = 3;
    }
    if (r != 9) {
        if (p == 0 || func_0203D1B4() <= 1 || p[0x902] < 2)
            return func_0217B044((void *)a0, a1, a2, a4, r, 0);
        if (func_02175BE4(p + 0x1AC) == 1)
            return func_0217B044((void *)a0, a1, a2, a4, r, 1);
        return func_0217B1DC(a0, a1, a2, r);
    }
    return 0;
}
