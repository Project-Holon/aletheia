/*
 * function: func_021BAC04
 * address:  0x021BAC04
 * packet:   pkt_ov021_021BAC04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef unsigned char  u8;
extern u32 func_021B821C(u8 *p);
extern u32 func_021B8220(u8 *p);
extern u32 *func_021B830C(u32);
extern void func_0218E124(u8 *a, u32 s);
extern int func_0218EC60(u32 a);
extern void func_021B79D4(void **o, void *out);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218ECD4(u32, u32 *);

void func_021BAC04(u32 a)
{
    u32 loc[3];
    u32 s[3];
    u32 h;
    u32 *r;
    u16 x, y;
    u32 z;

    h = func_021B821C((u8 *)a);
    r = func_021B830C(func_021B8220((u8 *)a));
    func_0218E124((u8 *)h, 0);
    func_0218EC60(func_021B821C((u8 *)a));
    func_021B79D4((void **)a, loc);
    x = r[1];
    y = r[2];
    z = r[3];
    func_0218ED48((u8 *)h, y);
    func_0218ED34((u8 *)h, x);
    func_0218ED58((u8 *)h, z);
    s[0] = r[4];
    s[1] = r[5];
    s[2] = r[6];
    func_0218ECD4(h, s);
}
