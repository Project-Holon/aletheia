/*
 * function: func_0218E610
 * address:  0x0218E610
 * packet:   pkt_ov021_0218E610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Converts a vector to two 16-bit angles plus its length.
 *
 * symbols:
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218E7DC  0x0218E7DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef struct { int x, y, z; } V;

extern int func_0207CBD0(void *a);
extern void func_0207CCA4(void *a, V *b);
extern int func_0207CFB8(int a, int b);
extern void func_0218E7DC(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1);

void func_0218E610(void *a, u16 *b, u16 *c, int *d)
{
    V v;
    V w;
    u16 h[2];
    int len;

    len = func_0207CBD0(a);
    func_0207CCA4(a, &v);
    w.x = v.x;
    w.y = 0;
    w.z = v.z;
    h[1] = func_0207CFB8(v.y, func_0207CBD0(&w));
    h[0] = func_0207CFB8(v.x, v.z);
    func_0218E7DC(&v, h[0], h[1], h, &h[1]);
    *b = h[1];
    *c = h[0];
    *d = len;
}
