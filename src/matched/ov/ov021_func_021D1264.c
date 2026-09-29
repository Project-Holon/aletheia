/*
 * function: func_021D1264
 * address:  0x021D1264
 * packet:   pkt_ov021_021D1264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   d_021DB984     0x021DB984  data  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021D1430  0x021D1430  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern u32 func_02188CB4(u32 a);
extern u32 func_02188C58(u32 a);
extern u32 func_0218EC2C(u32 a);
extern void func_02048AD0(u32 l);
extern void func_02048B30(u32 l, V *out);
extern void func_02048AE8(u32 l, V *out);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern void func_0207CCA4(const V *a, V *b);
extern void func_0207CAE8(const V *a, const V *b, V *c);
extern const V d_021DB984;
extern void func_021A3038(u32 a, V *out);
extern void func_0206DF3C(V *a, int *x, int *y);
extern u32 func_020450F0(u32 a, u8 b, u8 c, u32 d, u32 e, u32 f, u32 g);
extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(u32 w);
extern void func_021D1430(u8 *p, u32 n);

void func_021D1264(u8 *p)
{
    V pos;
    V d;
    V f;
    V s;
    V u;
    V at;
    V eye;
    int x;
    int y;
    u32 o;
    u32 cam;

    o = func_02188CB4(*(u32 *)p);
    cam = func_0218EC2C(func_02188C58(*(u32 *)p));
    func_02048AD0(cam);
    func_02048B30(cam, &eye);
    func_02048AE8(cam, &at);
    func_0207CA00(&eye, &at, &d);
    f = d;
    f.y = 0;
    func_0207CCA4(&f, &f);
    func_0207CAE8(&f, &d_021DB984, &s);
    func_0207CAE8(&d, &s, &u);
    func_0207CCA4(&u, &u);
    func_021A3038(o, &pos);
    pos.x += (int)(((long long)u.x * -0x1C000 + 0x800) >> 12);
    pos.y += (int)(((long long)u.y * -0x1C000 + 0x800) >> 12);
    pos.z += (int)(((long long)u.z * -0x1C000 + 0x800) >> 12);
    func_0206DF3C(&pos, &x, &y);
    x -= 0x10;
    y -= 0x18;
    *(u16 *)(p + 8) = x % 8;
    *(u16 *)(p + 10) = y % 8;
    x /= 8;
    y /= 8;
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x > 0x1F) {
        x = 0x1F;
    }
    if (y > 0x18) {
        y = 0x18;
    }
    *(u32 *)(p + 4) = func_020450F0(3, x, y, 5, 5, 9, 1);
    func_02043B5C(func_02045770(*(u32 *)(p + 4)), 0);
    func_02045334(*(u32 *)(p + 4));
    func_021D1430(p, 0);
}
