/*
 * function: func_021A9F40
 * address:  0x021A9F40
 * packet:   pkt_ov021_021A9F40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

struct Pos;
struct Sub02008C20Obj;
extern void *func_02188CB4(u8 *p);
struct BigObj;
struct Obj;
struct Unit;
extern u32 func_02012A38(const struct BigObj *p);
extern void func_021AA728(struct Pos *p, void *q);
struct Tab;
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
