/*
 * function: func_021BAA9C
 * address:  0x021BAA9C
 * packet:   pkt_ov021_021BAA9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CC30  0x0207CC30  arm
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

extern u32 func_021B8220(u32);
extern u32 *func_021B830C(u32);
extern u32 func_021B821C(u32);
extern void func_0218E124(u32, int);
extern void func_0218EC60(u32);
extern void func_021B8050(u32, s16 *);
extern int func_0207CFB8(int, int);
extern int func_0207CC30(s16 *);
extern void func_0218ED34(u32, u16);
extern void func_0218ED58(u32, u32);
extern void func_0218ED48(u32, u16);

void func_021BAA9C(u32 a)
{
    s16 b[6];
    u32 t, h;
    u32 *r;
    int x, y;

    t = func_021B8220(a);
    r = func_021B830C(t);
    h = func_021B821C(a);
    func_0218E124(h, 0);
    func_0218EC60(func_021B821C(a));
    func_021B8050(t, &b[3]);
    x = func_0207CFB8(-b[3], -b[5]);
    b[0] = b[3];
    b[2] = b[5];
    b[1] = 0;
    y = func_0207CFB8(-b[4], func_0207CC30(b));
    func_0218ED34(h, y + r[2]);
    func_0218ED58(h, r[3]);
    func_0218ED48(h, x + r[1]);
}
