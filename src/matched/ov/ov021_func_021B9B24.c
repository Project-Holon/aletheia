/*
 * function: func_021B9B24
 * address:  0x021B9B24
 * packet:   pkt_ov021_021B9B24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B9A50  0x021B9A50  thumb  ov021
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CEE4  0x0207CEE4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef long long      s64;

typedef struct { int x, y, z; } V;

void func_021B9A50(V *a, V *b, V *c, int k);
int func_0207CBD0(V *a);
void func_0207CEE4(int s, V *a, V *b, V *c);

void func_021B9B24(V *a, V *b, V *c, int k)
{
    V t = {0, 0, 0};
    int m1;
    int m2;
    int d;

    func_021B9A50(a, b, c, k);
    m1 = func_0207CBD0(b);
    m2 = func_0207CBD0(c);
    d = m2 - m1;
    func_0207CEE4(m1 + (int)(((s64)d * k + 0x800) >> 12), a, &t, a);
}
