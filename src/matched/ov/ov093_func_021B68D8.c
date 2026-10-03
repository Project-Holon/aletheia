/*
 * function: func_021B68D8
 * address:  0x021B68D8
 * packet:   pkt_ov093_021B68D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA710  0x021BA710  thumb  ov093
 *   func_021BA128  0x021BA128  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct T {
    u8 pad00[0x24];
    void *f24[4];
};

extern u8 func_021BA710(int a, int b);
extern void func_021BA128(u8 *s, int k, void *p);

void func_021B68D8(u8 *s, struct T *t)
{
    int a, b, c, d;

    a = func_021BA710(s[0x46c], 0);
    b = func_021BA710(s[0x46c], 1);
    func_021BA128(s, 0, t->f24[a]);
    func_021BA128(s, 1, t->f24[b]);
    c = func_021BA710(s[0x46c], 2);
    d = func_021BA710(s[0x46c], 3);
    if (t->f24[c] != 0) {
        func_021BA128(s, 2, t->f24[c]);
    }
    if (t->f24[d] != 0) {
        func_021BA128(s, 3, t->f24[d]);
    }
}
