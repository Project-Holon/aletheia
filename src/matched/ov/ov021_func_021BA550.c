/*
 * function: func_021BA550
 * address:  0x021BA550
 * packet:   pkt_ov021_021BA550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u32 p);
u32 func_021B821C(u32 p);
u32 func_021B833C(u32 q);
u32 func_021B834C(u32 q);
int *func_021B836C(u32 q, u32 k);
void func_0218E124(u32 a, u32 b);
void func_0218EC54(u32 a);
int func_021B82FC(u32 q);
int func_021B82F8(u32 q);
void func_0218ECF4(u32 o, V *v);
void func_0218EC90(u32 o, V *v);
int func_0207C768(int a, int b);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void func_021BA550(u32 p)
{
    V m;
    V n;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    u32 h;
    int d;
    int t;

    q = func_021B8220(p);
    h = func_021B821C(p);
    a = func_021B833C(q);
    b = func_021B834C(q);
    k0 = func_021B836C(q, a);
    k1 = func_021B836C(q, b);
    func_0218E124(h, 2);
    func_0218EC54(func_021B821C(p));
    d = func_021B82FC(q);
    t = func_021B82F8(q);
    m.x = func_0207C768(FX_MUL(k1[1] - k0[1], t << 12), d << 12);
    m.y = func_0207C768(FX_MUL(k1[2] - k0[2], t << 12), d << 12);
    m.z = func_0207C768(FX_MUL(k1[3] - k0[3], t << 12), d << 12);
    n.x = func_0207C768(FX_MUL(k1[4] - k0[4], t << 12), d << 12);
    n.y = func_0207C768(FX_MUL(k1[5] - k0[5], t << 12), d << 12);
    n.z = func_0207C768(FX_MUL(k1[6] - k0[6], t << 12), d << 12);
    m.x += k0[1];
    m.y += k0[2];
    m.z += k0[3];
    n.x += k0[4];
    n.y += k0[5];
    n.z += k0[6];
    func_0218ECF4(h, &m);
    func_0218EC90(h, &n);
}
