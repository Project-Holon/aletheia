/*
 * function: func_021BAB30
 * address:  0x021BAB30
 * packet:   pkt_ov021_021BAB30
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
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;

typedef unsigned char  u8;
struct Sub;
extern u32 func_021B8220(u8 *p);
extern u32 *func_021B830C(u32);
extern u32 func_021B821C(u8 *p);
extern void func_0218E124(u8 *a, u32 s);
extern void func_0218EC54(u8 *p);
extern void func_021B8050(struct Sub *o, s16 *out);
extern int func_0207CFB8(int, int);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_021B8314(u32, u32 *);
extern void func_0218EC90(u32, u32 *);

void func_021BAB30(u32 a)
{
    s16 v[4];
    u32 loc[3];
    u32 t, h;
    u32 *r;
    int ang;

    t = func_021B8220((u8 *)a);
    r = func_021B830C(t);
    h = func_021B821C((u8 *)a);
    func_0218E124((u8 *)h, 0);
    func_0218EC54((u8 *)func_021B821C((u8 *)a));
    func_021B8050((struct Sub *)t, v);
    ang = func_0207CFB8(-v[0], -v[2]);
    func_0218ED34((u8 *)h, r[2]);
    func_0218ED58((u8 *)h, r[3]);
    func_0218ED48((u8 *)h, (u16)(ang + r[1]));
    func_021B8314(t, loc);
    func_0218EC90(func_021B821C((u8 *)a), loc);
}
