/*
 * function: func_0218E764
 * address:  0x0218E764
 * packet:   pkt_ov021_0218E764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Derives two 16-bit angles from a matrix and stores them at +0x82/+0x84.
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CA68  0x0207CA68  arm
 *   d_021D3E2C     0x021D3E2C  data   ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } V;

extern void func_0207CA00(void *a, void *b, void *c);
extern void func_0207CCA4(V *a, V *b);
extern int func_0207CFB8(int a, int b);
extern int func_0207CA68(V *a, V *b);
extern V d_021D3E2C;

void func_0218E764(u8 *a, void *b, void *c)
{
    V v;
    V k;
    V w;
    int r, t;
    int s;

    func_0207CA00(c, b, &v);
    func_0207CCA4(&v, &v);
    *(u16 *)(a + 0x82) = func_0207CFB8(v.x, v.z);
    k = d_021D3E2C;
    r = func_0207CA68(&k, &v);
    w = v;
    s = 0;
    w.y = 0;
    func_0207CCA4(&w, &w);
    t = func_0207CA68(&w, &v);
    if (t != 0) {
        s = func_0207CFB8(r, t);
    }
    *(u16 *)(a + 0x84) = s;
}
