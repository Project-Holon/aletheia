/*
 * function: func_021BA6E8
 * address:  0x021BA6E8
 * packet:   pkt_ov021_021BA6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021B82F0  0x021B82F0  thumb  ov021
 *   func_021B833C  0x021B833C  thumb  ov021
 *   func_021B834C  0x021B834C  thumb  ov021
 *   func_021B836C  0x021B836C  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021BA7E0  0x021BA7E0  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u32 p);
u32 func_021B821C(u32 p);
u16 func_021B82F0(u32 q);
u32 func_021B833C(u32 q);
u32 func_021B834C(u32 q);
int *func_021B836C(u32 q, u32 k);
int func_021B82FC(u32 q);
int func_021B82F8(u32 q);
int *func_021B830C(u32 q);
u32 func_0207C768(u32 a, u32 b);
void func_021BA7E0(u32 p, u16 ang, int r, V *pos);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void func_021BA6E8(u32 p)
{
    V v;
    int *k0;
    int *k1;
    u32 q;
    u32 a;
    u32 b;
    int d;
    int t;
    u16 x;
    int x0;
    int y;

    q = func_021B8220(p);
    func_021B821C(p);
    if (func_021B82F0(q) == 1) {
        a = func_021B833C(q);
        b = func_021B834C(q);
        k0 = func_021B836C(q, a);
        k1 = func_021B836C(q, b);
        d = func_021B82FC(q);
        t = func_021B82F8(q);
    } else {
        k0 = func_021B830C(q);
        k1 = func_021B830C(q);
        d = 1;
        t = 0;
    }
    x0 = k0[1];
    x = x0 + (k1[1] - x0) * t / d;
    y = k0[2] + func_0207C768(FX_MUL(k1[2] - k0[2], t << 12), d << 12);
    v.x = k0[3];
    v.y = k0[4];
    v.z = k0[5];
    func_021BA7E0(p, x, y, &v);
}
