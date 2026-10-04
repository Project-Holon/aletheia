/*
 * function: func_021AA248
 * address:  0x021AA248
 * packet:   pkt_ov021_021AA248
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_021AA728  0x021AA728  thumb  ov021
 *   func_02193920  0x02193920  thumb  ov021
 *   func_021AA42C  0x021AA42C  thumb  ov021
 *   func_021AA35C  0x021AA35C  thumb  ov021
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_021A9350  0x021A9350  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A9604  0x021A9604  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA490  0x021AA490  thumb  ov021
 *   func_021AA6F8  0x021AA6F8  thumb  ov021
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    void *f00;
    int f04;
    void *f08;
};

struct Slot14 {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 pad08[0xC];
};

struct Sel {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x20];
};

struct Pos;
extern void *func_02188CB4(u8 *p);
struct BigObj;
struct Out;
struct Unit;
extern u32 func_02012A38(const struct BigObj *p);
extern void func_021AA728(struct Pos *p, void *q);
extern u8 func_02193920(u8 *p);
extern int func_021AA42C(void *a, void *b);
extern int func_021AA35C(void *ctx, int mode, u8 *out);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_021A9604(int obj, struct Sel *sel, struct Out *out);
extern void *func_02013090(u32 heap);
extern void func_021AA490(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void func_021AA6F8(struct Pos *p, void *q);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);

int func_021AA248(struct Ctx *ctx, void *b)
{
    struct Slot14 slots[2];
    struct Sel sel;
    u8 loc;
    void *q;
    void *p;
    int m;
    void *h;

    q = func_02188CB4(ctx->f00);
    p = (void *)func_02012A38(ctx->f08);
    func_021AA728(p, q);
    if (func_02193920(b) == 1) {
        return 0;
    }
    if (!func_021AA42C(p, b)) {
        return 0;
    }
    loc = 0;
    m = func_021AA35C(ctx, 3, &loc);
    func_021A9350(&sel, ctx->f08, m, 3, func_021A1BF4((u8 *)func_02188C6C(ctx->f00)));
    func_02082BCC(slots, 0, 0x28);
    if (!func_021A9604((int)b, &sel, (struct Out *)slots)) {
        return 0;
    }
    h = func_02013090(4);
    func_021AA490(ctx, (struct Unit *)(&sel), h, 4, slots);
    func_021AA6F8(p, q);
    return func_0216E7C8(ctx->f04, (int)ctx->f00, (int)h, 0, 3);
}
