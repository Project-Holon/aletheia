/*
 * file:     field_effect_p05.c
 * unit:     yes
 * function: func_021AA248, func_021AA304, func_021AA35C
 * address:  0x021AA248
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_021AA728  0x021AA728  thumb  ov021
 *   func_02193920  0x02193920  thumb  ov021
 *   func_021AA42C  0x021AA42C  thumb  ov021
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_021A9350  0x021A9350  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A9604  0x021A9604  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_021AA490  0x021AA490  thumb  ov021
 *   func_021AA6F8  0x021AA6F8  thumb  ov021
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02013ED8  0x02013ED8  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021AA69C  0x021AA69C  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB580  0x021AB580  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB100  0x021AB100  thumb
 *   func_021AB140  0x021AB140  thumb
 *   func_021AB29C  0x021AB29C  thumb
 */
struct Pos;
struct Obj00020;
struct BigObj;
struct Out;
struct Unit;
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

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct RtcTime { u32 hour; u32 minute; u32 second; };

struct Info {
    u32 f00;
    u32 f04;
    u8 f08;
    u8 f09;
    u16 f0A;
    u8 f0C;
    u8 f0D;
};

extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02012A38(const struct BigObj *p);
extern void func_021AA728(struct Pos *p, void *q);
extern u8 func_02193920(u8 *p);
extern int func_021AA42C(void *a, void *b);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_021A9604(int obj, struct Sel *sel, struct Out *out);
extern void *func_02013090(u32 heap);
extern void func_021AA490(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
extern void func_021AA6F8(struct Pos *p, void *q);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern u16 func_02188C9C(u8 *p);
extern u8 func_02013ED8(u32 id);
extern u32 func_021A30C8(void **ctx);
extern u16 func_021AB0F0(u32 attr);
extern u8 func_021AB580(u16 x);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_021AA69C(void *p);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02188C98(u8 *p);
extern int func_021AB100(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB140(int x);
extern int func_021AB29C(u16 x);
int func_021AA248(struct Ctx *ctx, void *b);
void func_021AA304(struct Info *out, void *a1, void *a2);
int func_021AA35C(void **ctx, int mode, u8 *out);


/*
 * Addresses are Black-image addresses.
 */
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
    m = func_021AA35C((void **)ctx, 3, &loc);
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



void func_021AA304(struct Info *out, void *a1, void *a2)
{
    struct RtcTime t;
    u16 x = func_02188C9C(a2);
    void *y = func_02188CB4(a2);

    out->f00 = func_02013ED8(x);
    out->f04 = func_021AB580(func_021AB0F0(func_021A30C8(y)));
    out->f0A = x;
    func_0203F4CC(&t);
    out->f0C = t.hour;
    out->f0D = t.minute;
    out->f08 = func_021AA69C(a2);
    out->f09 = func_02012984(a1);
}



int func_021AA35C(void **ctx, int mode, u8 *out)
{
    void *y = func_02188CB4(ctx[0]);
    u32 attr;
    u16 fl;
    u16 t;

    func_02188C98(ctx[0]);
    *out = 0;
    attr = func_021A30C8(y);
    if (func_021AB100(attr) == 0)
        return 0xFF;
    fl = func_021AB0F8(attr);
    if (mode != 1 && (fl & 4) == 0)
        return 0xFF;
    t = func_021AB0F0(attr);
    if (func_021AB140(t))
        *out += 10;
    if (fl & 2) {
        if (mode == 1)
            return 4;
        return 3;
    }
    if (mode == 1)
        return 2;
    if (func_021AB29C(t))
        return 1;
    return 0;
}
