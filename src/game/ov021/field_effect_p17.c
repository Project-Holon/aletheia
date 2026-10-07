/*
 * file:     field_effect_p17.c
 * unit:     yes
 * function: func_021AA7DC, func_021AA80C, func_021AA8EC, func_021AA8F8
 * address:  0x021AA7DC
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
 *   d_021D8E70  0x021D8E70  data  a4
 *   func_02012A38  0x02012A38  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021AABC4  0x021AABC4  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021AABEC  0x021AABEC  thumb  ov021
 *   func_021AACD4  0x021AACD4  thumb  ov021
 *   func_021AAE34  0x021AAE34  thumb  ov021
 *   func_021AAFA0  0x021AAFA0  thumb  ov021
 *   func_021AAF54  0x021AAF54  thumb
 */
#include "../../matched/include/Obj18072.h"

struct BigObj;
struct Blk34;
struct Obj00020;
struct Actor;
struct VecFx32;
struct Self;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u8 pad[7];
    u8 k : 7;
    u8 hi : 1;
} R;

typedef struct {
    int pad[3];
    R *fc;
} S;

typedef struct {
    char pad[0x5b8];
    u16 a;
    u16 b;
} D;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Entry {
    u8 pad00[0x1D];
    u8 flags : 4;
};

struct Enc {
    u8 pad00[4];
    u16 f04;
    u8 pad06[0x5B4];
    u16 f5BA;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
    struct Enc *f10;
};

extern u32 func_02012A38(const struct BigObj *p);
extern u32 func_02012974(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern u32 func_02188CFC(u8 *p);
extern int func_021AABC4(struct Entry *p, struct Enc *e);
extern u32 func_02005728(u32 v);
extern void func_021AABEC(u8 *p);
extern void func_021AACD4(void **ctx, struct Enc *e);
extern void func_021AAE34(struct Ctx *ctx, struct Enc *e);
extern void func_021AAFA0(u8 *p, u32 v);
extern int func_021AAF54(struct Self *self);
void func_021AA7DC(S *s, D *d);
void func_021AA80C(struct Ctx *ctx);
void func_021AA8EC(u8 *p);
void func_021AA8F8(struct Self *a0);
extern const Pair d_021D8E70[];


void func_021AA7DC(S *s, D *d)
{
    unsigned int k = s->fc->k;
    if (k > 2) {
        k = 0;
    }
    d->a = d_021D8E70[k].a;
    d->b = d_021D8E70[k].b;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021AA80C(struct Ctx *ctx)
{
    struct Enc *e = ctx->f10;
    struct Entry *p = (struct Entry *)func_02012A38(ctx->f08);
    void *m;
    u16 id;
    s32 pos[3];
    int r;

    if (ctx == 0 || ctx->f0C == 0 || !ctx->f0C->b7)
        return;
    m = (void *)func_02012974(ctx->f08);
    if (ctx->f00 == 0 || m == 0)
        return;
    id = func_02188C9C(ctx->f00);
    func_0216D88C(func_021A3074(func_02188CB4(ctx->f00)), (struct VecFx32 *)pos);
    if (func_02159C48((int)m, pos[0], pos[2]) == 0)
        return;
    r = func_02159BD4((int)m, pos[0], pos[2]);
    if (id == 0xFFFF || r == 0xFFFF || id != r)
        return;
    if (func_0200C234(func_02012F08(ctx->f08), 0) == 0)
        return;
    if (func_02188CFC(ctx->f00) != 0)
        return;
    if (p->flags != 0)
        return;
    if (func_021AABC4(p, e) == 0)
        return;
    if (func_02005728(1000) >= e->f5BA * 10) {
        func_021AABEC((u8 *)p);
        return;
    }
    func_021AACD4((void **)ctx, e);
    if (e->f04 != 0)
        func_021AAE34(ctx, e);
}


/*
 * Tail call with the object and the word at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8EC(u8 *p)
{
    func_021AAFA0(p, ((struct Obj18072 *)p)->f10);
}


/*
 * Tail-call thunk: forwards to func_021AAF54 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8F8(struct Self *a0)
{
    func_021AAF54(a0);
}
