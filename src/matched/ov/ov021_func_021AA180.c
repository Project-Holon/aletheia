/*
 * function: func_021AA180
 * address:  0x021AA180
 * packet:   pkt_ov021_021AA180
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_021AA3E0  0x021AA3E0  thumb  ov021
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_021A9350  0x021A9350  thumb  ov021
 *   func_021A94B0  0x021A94B0  thumb  ov021
 *   func_021AA6E0  0x021AA6E0  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A954C  0x021A954C  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA490  0x021AA490  thumb  ov021
 *   func_02013144  0x02013144  thumb
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
    u8 pad16[0x16];
};

struct Obj {
    u8 pad00[0xC];
    int f0C;
};

extern int func_021AA3E0(struct Ctx *t, int i, int add);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u32 v);
extern void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d);
extern u32 func_021A94B0(struct Sel *o, void *unused, u32 n);
extern u32 func_021AA6E0(void);
extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02188C9C(u8 *p);
extern int func_021A954C(void *a0, void *u, u16 id, void *slots);
extern void *func_02013090(u32 heap);
extern void func_021AA490(struct Ctx *ctx, struct Sel *s, void *a, int b, struct Slot14 *o);
extern void func_02013144(void *p, int v);

struct Obj *func_021AA180(struct Ctx *ctx, int mode)
{
    struct Slot14 slots[2];
    struct Sel sel;
    int k;
    int m;
    u32 rate;
    struct Obj *h;

    if (ctx->f0C == 0 || !ctx->f0C->b7)
        return 0;
    k = 6;
    if (mode != 1)
        k = 5;
    m = func_021AA3E0(ctx, k, 0);
    if (m == 0)
        return 0;
    func_021A9350(&sel, ctx->f08, k, mode, func_021A1BF4(func_02188C6C(ctx->f00)));
    if (mode != 1) {
        rate = func_021A94B0(&sel, ctx->f08, m);
        if (func_021AA6E0() > rate)
            return 0;
    }
    h = 0;
    func_02082BCC(slots, 0, 0x28);
    if ((u32)func_021A954C(ctx->f0C, &sel, func_02188C9C(ctx->f00), slots) < sel.f15)
        return h;
    h = func_02013090(4);
    func_021AA490(ctx, &sel, h, 4, slots);
    func_02013144(h, 1);
    h->f0C = 6;
    return h;
}
