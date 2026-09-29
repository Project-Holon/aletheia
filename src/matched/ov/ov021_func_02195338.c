/*
 * function: func_02195338
 * address:  0x02195338
 * packet:   pkt_ov021_02195338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CA00  0x0207CA00  arm
 *   func_02194E74  0x02194E74  thumb  ov021
 *   func_02194E90  0x02194E90  thumb  ov021
 *   func_02194F84  0x02194F84  thumb  ov021
 *   func_02195128  0x02195128  thumb  ov021
 *   func_0219518C  0x0219518C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

extern void func_0207CA00(u32 a, u8 *b, V *c);
extern int func_02194E74(V *a, int *b, int *c, V *d);
extern void func_02194E90(u8 *e, u8 *ent, int *b, int *c, V *d);
extern int func_02194F84(u8 *e, int b, int c, V *d, V *f);
extern void func_02195128(u8 *e, V *a, V *b, V *c, V *d);
extern void func_0219518C(u8 *p, u8 *e, V *a, V *b, V *c, V *d, V *f, V *g, V *h);

u32 func_02195338(u8 *p, u8 *e)
{
    V v8;
    V v7;
    V v6;
    V v5;
    V v4;
    V v3;
    V v2;
    V v1;
    int b;
    int c;
    int r;

    if (*(u32 *)(e + 0x10) != 0) {
        func_0207CA00(*(u32 *)(e + 0x10), p + 0xCB8, &v1);
        func_02194E74(&v1, &b, &c, &v8);
    } else {
        func_02194E90(e, p + 0x18 + *(u16 *)(e + 0x1A) * 100, &b, &c, &v8);
    }
    r = func_02194F84(e, b, c, &v7, &v6);
    func_02195128(e, &v5, &v4, &v3, &v2);
    func_0219518C(p, e, &v8, &v7, &v6, &v5, &v4, &v3, &v2);
    if (*(int *)(e + 0x58) != r) {
        *(int *)(e + 0x58) = r;
        return 1;
    }
    return 0;
}
