/*
 * function: func_021B57CC
 * address:  0x021B57CC
 * packet:   pkt_ov021_021B57CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 *
 * symbols:
 *   func_0201A354  0x0201A354  thumb
 *   func_021B5824  0x021B5824  thumb  ov021
 *   func_0201EE60  0x0201EE60  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0201A354(int a, int b);
extern u16 *func_021B5824(u8 *a0, void *a1, u16 *a2, int a3);
struct WordSet;
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_020307B0(void *p);

u16 func_021B57CC(void *a0, void *a1, u32 a2, int a3)
{
    u16 n = 0;
    u16 i = 0;
    void *t;
    u16 *v;

    t = func_0201A354(a2, a3);
    v = func_021B5824(t, a0, &n, a3);
    for (i = 0; i < n; i++) {
        func_0201EE60(a1, i, v[i]);
    }
    func_020307B0(v);
    func_020307B0(t);
    return n;
}
