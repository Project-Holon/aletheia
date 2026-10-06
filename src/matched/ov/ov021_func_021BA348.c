/*
 * function: func_021BA348
 * address:  0x021BA348
 * packet:   pkt_ov021_021BA348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of func_021BACA8 without the vector part.  The angle and scalar
 * locals are int with explicit (u16) casts: as u16 locals the k0 loads
 * reorder and the ratio stays in a register pair instead of its
 * [sp]/[sp+4] spill.
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

u32 func_021B8220(u8 *p);
u32 func_021B833C(u32 q);
u32 func_021B834C(u32 q);
u32 func_021B821C(u8 *p);
void func_0218E124(u8 *a, u32 s);
int func_0218EC60(u32 a);
int *func_021B836C(u32 q, u32 k);
u32 func_021B82FC(u8 *p);
u32 func_021B82F8(u8 *p);
void func_0218ED48(u8 *p, u32 v);
void func_0218ED34(u8 *p, u16 v);
void func_0218ED58(u8 *p, u32 v);
u32 func_0207C768(u32 a, u32 b);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void func_021BA348(u32 p)
{
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int s;
    int d;
    int t;
    int x0;
    int y0;
    int z0;
    int y1;
    int z1;
    int dx;
    int dy;
    u16 x;
    u16 y;

    q = func_021B8220((u8 *)p);
    a = func_021B833C(q);
    b = func_021B834C(q);
    h = func_021B821C((u8 *)p);
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)p));
    k0 = func_021B836C(q, a);
    k1 = func_021B836C(q, b);
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    s = func_0207C768(t << 12, d << 12);
    x0 = (u16)k0[1];
    y0 = (u16)k0[2];
    z0 = k0[3];
    y1 = (u16)k1[2];
    z1 = k1[3];
    dx = (u16)k1[1] - x0;
    if (dx >= 0x8000)
        dx -= 0x10000;
    else if (dx <= -0x8000)
        dx += 0x10000;
    x = x0 + (FX_MUL(dx << 12, s) >> 12);
    dy = y1 - y0;
    if (dy >= 0x8000)
        dy -= 0x10000;
    else if (dy <= -0x8000)
        dy += 0x10000;
    y = y0 + (FX_MUL(dy << 12, s) >> 12);
    func_0218ED48((u8 *)h, y);
    func_0218ED34((u8 *)h, x);
    func_0218ED58((u8 *)h, z0 + FX_MUL(z1 - z0, s));
}
