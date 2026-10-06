/*
 * function: func_0217B214
 * address:  0x0217B214
 * packet:   pkt_ov018_0217B214
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
struct Ctx;
struct Sub24;
struct Rec44;
struct WordSet;
struct U16Vec;
struct MsgBank;

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

extern void *func_020124E4(struct Obj *p);
struct BigObj;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_02012B58(const struct BigObj *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201ED04(struct WordSet *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern u32 func_020362DC(void);
extern int func_02158344(int a0);
extern int func_021584A4();
extern int func_0216D3CC(int a0);
extern void func_0216D9A0(void *map);
extern void func_0216D9E4(void *c);
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
