/*
 * function: func_021BA8E0
 * address:  0x021BA8E0
 * packet:   pkt_ov021_021BA8E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B82F0  0x021B82F0  thumb  ov021
 *   func_021B82FC  0x021B82FC  thumb  ov021
 *   func_021B82F8  0x021B82F8  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021BA7E0  0x021BA7E0  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u16 func_021B82F0(u8 *p);
u32 func_021B82FC(u8 *p);
u32 func_021B82F8(u8 *p);
int *func_021B830C(u32 q);
u32 func_0207C768(u32 a, u32 b);
void func_021BA7E0(u32 p, u16 ang, int r, V *pos);

static inline int FX_MUL(int a, int b)
{
    return (int)(((s64)a * b + 0x800LL) >> 12);
}

void func_021BA8E0(u32 p)
{
    V v;
    int *k;
    u32 q;
    int d;
    int t;
    u16 x;
    int y;

    q = func_021B8220((u8 *)p);
    func_021B82F0((u8 *)q);
    d = func_021B82FC((u8 *)q);
    t = func_021B82F8((u8 *)q);
    k = func_021B830C(q);
    x = k[1];
    y = k[2];
    v.x = k[3] + func_0207C768(FX_MUL(k[6] - k[3], t << 12), d << 12);
    v.y = k[4] + func_0207C768(FX_MUL(k[7] - k[4], t << 12), d << 12);
    v.z = k[5] + func_0207C768(FX_MUL(k[8] - k[5], t << 12), d << 12);
    func_021BA7E0(p, x, y, &v);
}
