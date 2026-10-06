/*
 * function: func_021AA80C
 * address:  0x021AA80C
 * packet:   pkt_ov021_021AA80C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
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

struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
extern u32 func_02012974(const struct BigObj *p);
struct Blk34;
extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
struct Actor;
struct VecFx32;
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
