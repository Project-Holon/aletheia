/*
 * function: func_021B1DEC
 * address:  0x021B1DEC
 * packet:   pkt_ov021_021B1DEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C78DC  0x021C78DC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(void *);
extern u32 func_02188D38(u32);
extern int func_02159B10(u32, u32);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_021C78DC(u32, int, void *, void *);
extern void func_021C6DE0(u32, u32, int);

int func_021B1DEC(u32 a, u32 b)
{
    struct { int x, y, z; } v;
    u32 x;
    u32 y;
    int neg;
    int q;
    int p;
    int z;
    int zero;
    void *w;

    x = func_02158F58(func_0215A5F4((void *)b))[1];
    y = func_02188D38(x);
    neg = func_02159B10(a, b);
    p = func_02159B10(a, b);
    q = func_02159B10(a, b);
    z = func_02159B10(a, b);
    if (neg != 0)
        p = -p;
    if (z == 0) {
        zero = 0;
        v.x = zero;
        v.y = -q << 12;
        v.z = zero;
    } else {
        zero = 0;
        v.x = zero;
        v.y = q << 12;
        v.z = zero;
    }
    w = func_021A3074(func_02188CB4((void *)x));
    func_021C6DE0(y, func_021C78DC(x, p, &v, w), 0);
    return 0;
}
