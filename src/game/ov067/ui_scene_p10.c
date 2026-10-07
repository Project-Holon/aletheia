/*
 * file:     ui_scene_p10.c
 * unit:     yes
 * function: func_021B7718, func_021B7754, func_021B796C, func_021B79E4, func_021B7A10, func_021B7A4C, func_021B7A64
 * address:  0x021B7718
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030734  0x02030734  arm
 *   d_021B9574     0x021B9574  data  ov067  a1
 *   func_0201C450  0x0201C450  thumb
 *   func_0202E940  0x0202E940  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02082A90  0x02082A90  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020452E8       0x020452E8  arm
 *   func_0202CA0C       0x0202CA0C  thumb
 *   func_0202EA20       0x0202EA20  thumb
 *   func_0201C4C0       0x0201C4C0  thumb
 *   func_02049EF4 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_021B7B7C  0x021B7B7C  thumb  ov067
 *   func_021B7BE0  0x021B7BE0  thumb  ov067
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021B9344  0x021B9344  thumb  ov067
 */
#include "../../matched/include/Obj20620.h"
#include "../../matched/include/Obj09863.h"
#include "../../matched/include/Obj20621.h"

struct WinMgr;
struct CodeIn;
struct Descriptor;
struct Obj0202EA20;
struct PrintSys;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

struct Ent {
    u8 f0;
    u8 pad1[7];
};

typedef struct Tmpl {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fa;
    u8 padb[0x11 - 0xb];
    u8 f11;
    u8 pad12[0x14 - 0x12];
    u16 f14;
    u16 f16;
    u8 pad18[0x1c - 0x18];
    struct Ent *f1c;
    u32 f20;
    u32 f24;
} Tmpl;

struct Slot {
    u32 w;
    u32 pad;
};

typedef struct S_021B7754 {
    Tmpl t;
    void *f28;
    u32 *f2c;
    void *f30;
    void *f34;
    struct Slot *f38;
    void *f3c;
    void **f40;
    u8 f44;
    u8 f45;
    u8 pad46[0x4a - 0x46];
    s8 f4a;
    u8 pad4b[0x54 - 0x4b];
    int f54;
    int f58;
    u8 pad5c[0x98 - 0x5c];
    u16 f98;
    u8 pad9a[2];
} S_021B7754;

struct Elem2 {
    void *p;
    u32 _4;
};

struct S_021B796C {
    u8 _0[0x16];
    u16 cnt16;
    u8 _18[0x28 - 0x18];
    void *f28;
    void *f2c;
    void *f30;
    void *f34;
    struct Elem2 *arr38;
    void *f3c;
    void **arr40;
    u8 count44;
};

typedef struct Pair { unsigned first, second; } Pair;

typedef struct S_021B7A64 {
    u8 pad00[0x34];
    u32 f34;
    u8 pad38[0x4e - 0x38];
    u16 f4e;
} S_021B7A64;

extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0201C450(u16 n, u32 heap);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void ENV_SetResourceSet(void *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0202CA0C(struct WinMgr *mgr);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02082A60(const void *, void *, int);
extern u32 func_020307B0(void *p);
extern void func_0202E9AC(struct CodeIn *, u8 *, u32, u32, u32);
extern void func_021B7B7C(S_021B7A64 *p);
extern void func_021B7BE0(struct S_021B7A64 *p, int a1);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021B9344(S_021B7A64 *p);
void func_021B7718(int which, int idx, void *data);
S_021B7754 *func_021B7754(Tmpl *tmpl, u32 heap);
void func_021B796C(struct S_021B796C *s);
void func_021B79E4(char *ctx, unsigned first, unsigned second);
void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
int func_021B7A64(S_021B7A64 *p);
extern const char d_021B9574[];


/*
 * The handed 596-byte extent also holds the unlabelled follower
 * 0x021B7754 (filed separately).
 */
void func_021B7718(int which, int idx, void *data)
{
    int type;

    switch (which) {
    case 0:
        type = 0xf;
        break;
    case 1:
        type = 0xe;
        break;
    case 4:
        type = 0x1f;
        break;
    case 5:
        type = 0x1e;
        break;
    case 2:
    case 3:
        return;
    default:
        return;
    }
    func_02061CA4((void *)type, idx << 5, (u32)data, 0x20);
}


/*
 * Unlabelled follower inside func_021B7718's handed 596-byte extent: a
 * 0x9c-byte object constructor (the listing gives it no label).  The f4a
 * loop is the compound `-=`: it keeps &p->f4a in a register for the body's
 * load and store, while the test reloads through p.
 */
S_021B7754 *func_021B7754(Tmpl *tmpl, u32 heap)
{
    S_021B7754 *p;
    u32 i;
    u32 n;

    p = func_02030734(heap, sizeof(S_021B7754), 1, d_021B9574, 0xf5);
    p->t = *tmpl;
    p->f98 = heap;
    p->f54 = -1;
    p->f58 = -1;
    p->f34 = func_0201C450(0x800, heap);
    p->f30 = func_0202E940(p->t.f11 << 4, 0x10, p->t.f0, p->f98);
    p->f28 = func_02030734(p->f98, p->t.f14 * 8, 1, d_021B9574, 0x104);
    if (p->t.f16 != 0) {
        p->f40 = func_02030734(p->f98, p->t.f16 * 4, 0, d_021B9574, 0x109);
        for (i = 0; i < p->t.f16; i++)
            p->f40[i] = func_02030734(p->f98, p->t.f4 * p->t.f5 * 2, 0, d_021B9574, 0x10b);
    }
    p->f44 = 0x18 / p->t.f5 + 2;
    p->f45 = p->f44;
    if (p->t.f1 != 0xff)
        p->f44 = p->f44 * 2;
    p->f3c = func_0202C9B4(2, p->f44, p->f98);
    p->f38 = func_02030734(p->f98, p->f44 * 8, 0, d_021B9574, 0x117);
    for (i = 0; i < p->f44; i++) {
        if (p->t.f1 != 0xff && p->f45 <= i) {
            func_0202CA3C(p->f3c, i, p->t.f1, p->t.f4, p->t.f5);
            p->f38[i].w = func_020450F0(p->t.f1, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        } else {
            func_0202CA3C(p->f3c, i, p->t.f0, p->t.f4, p->t.f5);
            p->f38[i].w = func_020450F0(p->t.f0, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        }
    }
    p->f4a = 0x18;
    do {
        p->f4a -= (s8)p->t.f5;
    } while (p->f4a > 0);
    if (p->t.f1c != 0) {
        n = 0;
        for (;;) {
            if (p->t.f1c[n].f0 == 0xff)
                break;
            n++;
        }
        p->f2c = func_02030734(p->f98, (n + 1) * 4, 0, d_021B9574, 0x13e);
        for (i = 0; i < n + 1; i++)
            func_02082A90(&p->t.f1c[i], &p->f2c[i], 4);
    }
    return p;
}


void func_021B796C(struct S_021B796C *s)
{
    u32 i;

    ENV_SetResourceSet(s->f2c);
    for (i = 0; i < s->count44; i++)
        func_020452E8((struct Descriptor *)((int)s->arr38[i].p));
    ENV_SetResourceSet(s->arr38);
    func_0202CA0C(s->f3c);
    if (s->cnt16 != 0) {
        for (i = 0; i < s->cnt16; i++)
            ENV_SetResourceSet(s->arr40[i]);
        ENV_SetResourceSet(s->arr40);
    }
    ENV_SetResourceSet(s->f28);
    func_0202EA20((struct Obj0202EA20 *)((int)s->f30));
    func_0201C4C0((struct PrintSys *)((int)s->f34));
    ENV_SetResourceSet(s);
}

void func_021B79E4(char *ctx, unsigned first, unsigned second)
{
    (*(Pair **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].first = first;
    (*(Pair **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].second = second;
    (((struct Obj20620 *)ctx)->f4C)++;
}

/*
 * prototype: 02049EF4 preserves r3 in r5 and forwards it unchanged to
 * 02062B30, which writes through it; use a pointer for the full-word payload.
 */
void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index)
{
    void *out;
    void *handle;
    handle = func_02049EF4((void *)a, b, c, &out, ((struct Obj09863 *)p)->f98);
    func_02082A60((u8 *)out + 0xc, (*(void ***)(p + 0x40))[index], p[4] * p[5] * 2);
    func_020307B0(handle);
}

/*
 * extent: trailing two-byte alignment padding at 0x021B7A62.
 */
void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj20621 *)p)->f30, a, b, c << 4, d << 4);
}


int func_021B7A64(S_021B7A64 *p)
{
    switch (p->f4e) {
    case 0:
        func_021B7B7C(p);
        func_021B7BE0(p, 0);
        p->f4e = p->f4e + 1;
        break;
    case 1:
        if (func_0201C6B4((const struct PrintSys *)p->f34) == 1) {
            p->f4e = 0;
            return 0;
        }
        break;
    }
    func_021B9344(p);
    return 1;
}
