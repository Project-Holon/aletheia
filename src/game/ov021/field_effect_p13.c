/*
 * file:     field_effect_p13.c
 * unit:     yes
 * function: func_021A9ED8, func_021A9F28, func_021A9F40, func_021AA0A0
 * address:  0x021A9ED8
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
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0216255C  0x0216255C  thumb  ov010
 *   func_021AA77C  0x021AA77C  thumb  ov021
 *   func_021AA7AC  0x021AA7AC  thumb  ov021
 *   d_021DDFA4     0x021DDFA4  data  a4
 *   func_021AA7CC  0x021AA7CC  thumb  ov021
 *   func_021AA794  0x021AA794  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_021AA728  0x021AA728  thumb  ov021
 *   func_021AA35C  0x021AA35C  thumb  ov021
 *   func_021AA3E0  0x021AA3E0  thumb  ov021
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_021A9350  0x021A9350  thumb  ov021
 *   func_021A94B0  0x021A94B0  thumb  ov021
 *   func_021AA3FC  0x021AA3FC  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A957C  0x021A957C  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA548  0x021AA548  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A954C  0x021A954C  thumb  ov021
 *   func_021AA490  0x021AA490  thumb  ov021
 *   func_021AA6F8  0x021AA6F8  thumb  ov021
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_02013144  0x02013144  thumb
 */
#include "../../matched/include/Obj12092.h"

struct BigObj;
struct Ctx;
struct Pos;
struct Sub02008C20Obj;
struct Obj00020;
struct Obj;
struct Unit;
struct Tab;
struct Sel;
struct Slot14;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Slot14 {
    u8 raw[0x14];
};

struct Sel {
    u8 pad00[0x15];
    u8 f15;
    u8 pad16[0x12];
    u32 b0 : 5;
    u32 b5 : 1;
};

typedef struct {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 pad8[8];
    u8 b10;
    u8 pad11[0x17];
} Opts;

typedef struct {
    u8 b[0x2c];
} Buf;

typedef struct {
    int f0;
    int f4;
    int f8;
} S;

extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0216255C(u32 a);
extern void *func_021AA77C(int heap);
extern int func_021AA7AC(u32 a, u32 b);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u32 func_020307B0(void *p);
extern u32 func_021AA794(u32);
extern int func_021AA7CC(u32 a, u32 b, u32 c, u32 d);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02012A38(const struct BigObj *p);
extern void func_021AA728(struct Pos *p, void *q);
extern int func_021AA35C(void **ctx, int mode, u8 *out);
extern int func_021AA3E0(struct Tab *t, int i, int add);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d);
extern u32 func_021A94B0(struct Obj *o, u32 unused, u32 n);
extern int func_021AA3FC(void *a0, void *p, u32 rate);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u16 func_02188C9C(u8 *p);
extern void *func_021A957C(void *a0, struct Unit *u, u32 want);
extern void *func_02013090(u32 heap);
extern void func_021AA548(struct Ctx *ctx, void *a1, void *a2, u16 heap, void *src);
extern void func_02082BCC(void *p, int v, int n);
extern int func_021A954C(void *a0, void *u, u16 id, void *slots);
extern void func_021AA490(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void func_021AA6F8(struct Pos *p, void *q);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern void func_02013144(char *p, int v);
u32 *func_021A9ED8(u32 a);
int func_021A9F28(void *a, u32 b, u32 c, u32 d);
int func_021A9F40(struct Ctx *ctx, int mode);
void func_021AA0A0(S *s, u16 a, u8 b, u32 flags);
extern int d_021DDFA4;


/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A9ED8(u32 a)
{
    u32 heap = func_02188C84((u8 *)a);
    u32 *p = (u32 *)func_02030734(heap, 0x14, 1, (const char *)&d_021DDFA4, 0x62);
    u32 x;
    u32 t;
    u32 q;

    p[0] = a;
    x = (u32)func_02188C80((void *)a);
    p[1] = x;
    t = (u32)func_020120F4((const struct Ctx *)x);
    p[2] = t;
    p[3] = func_0216255C(func_02012844((const struct BigObj *)t));
    q = (u32)func_021AA77C(heap);
    p[4] = q;
    func_021AA7AC((u32)p, q);
    return p;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A9F28(void *a, u32 b, u32 c, u32 d)
{
func_021AA7CC((u32)a, ((struct Obj12092 *)((u8 *)(a)))->f10, c, d);
func_021AA794(((struct Obj12092 *)((u8 *)(a)))->f10);
return func_020307B0(a);
}


int func_021A9F40(struct Ctx *ctx, int mode)
{
    struct Slot14 slots[2];
    struct Sel sel;
    u8 loc;
    int n;
    int m;
    void *p;
    void *q;
    int skip;
    void *src;
    void *h;
    int cnt;

    skip = 0;
    src = 0;
    q = func_02188CB4(ctx->f00);
    p = (void *)func_02012A38(ctx->f08);
    if (mode == 1 || mode == 2)
        skip = 1;
    else
        func_021AA728(p, q);
    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    loc = 0;
    m = func_021AA35C((void **)ctx, mode, &loc);
    n = func_021AA3E0((struct Tab *)ctx, m, loc);
    if (m == 0xFF || n == 0)
        return 0;
    func_021A9350(&sel, ctx->f08, m, mode, func_021A1BF4((u8 *)func_02188C6C(ctx->f00)));
    if (!skip) {
        if (!func_021AA3FC(ctx, p, func_021A94B0((struct Obj *)(&sel), (u32)ctx->f08, n)))
            return 0;
    }
    if (mode == 1)
        func_02008DF0((void *)func_02012F2C(ctx->f08), 0x70);
    else
        src = func_021A957C(ctx->f0C, (struct Unit *)(&sel), func_02188C9C(ctx->f00));
    if (src) {
        h = func_02013090(4);
        func_021AA548(ctx, &sel, h, 4, src);
    } else {
        src = 0;
        func_02082BCC(slots, 0, 0x28);
        cnt = func_021A954C(ctx->f0C, &sel, func_02188C9C(ctx->f00), slots);
        if (cnt == 0)
            return (int)src;
        if (sel.b5 && cnt == 1) {
            sel.b5 = 0;
            sel.f15 = cnt;
        }
        h = func_02013090(4);
        func_021AA490(ctx, (struct Unit *)(&sel), h, 4, slots);
    }
    func_021AA6F8(p, q);
    return func_0216E7C8(ctx->f04, (int)ctx->f00, (int)h, 0, mode);
}


void func_021AA0A0(S *s, u16 a, u8 b, u32 flags)
{
    Opts opts;
    Buf buf;
    int h;
    Opts *o;

    func_02188CB4((struct Obj00020 *)s->f0);
    func_021A9350((struct Sel *)(&buf), (void *)s->f8, 0xff, 0, func_021A1BF4((u8 *)func_02188C6C((u8 *)s->f0)));
    o = &opts;
    func_02082BCC(o, 0, 0x28);
    opts.h0 = a;
    o->b4 = b;
    if (flags & 4) {
        o->h2 = 0xffff;
    }
    if (flags & 2) {
        o->b6 = 1;
    } else if (flags & 0x10) {
        o->b6 = 2;
    } else {
        o->b6 = 0;
    }
    if (flags & 8) {
        o->b7 = 1;
    }
    if (flags & 0x20) {
        o->b10 = 1;
    } else if (flags & 0x40) {
        o->b10 = 2;
    }
    h = (int)func_02013090(4);
    func_021AA490((struct Ctx *)s, (struct Unit *)(&buf), (void *)h, 4, (struct Slot14 *)(&opts));
    if (flags & 1) {
        func_02013144((char *)h, 4);
    } else if (flags & 0x80) {
        func_02013144((char *)h, 0x80);
    }
    if (flags & 0x100) {
        func_02013144((char *)h, 0x200);
    }
    func_0216E7C8(s->f4, s->f0, h, 1, 0);
}
