/*
 * function: func_021BA494
 * address:  0x021BA494
 * packet:   pkt_ov021_021BA494
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021BA348  0x021BA348  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 */

typedef unsigned int   u32;

extern u32 func_021B821C(u32);
extern void func_021BA348(u32);
extern void func_0218EC54(u32);
extern void func_021B79D4(u32, u32 *);
extern void func_0218EC90(u32, u32 *);

void func_021BA494(u32 a)
{
    u32 h = func_021B821C(a);
    u32 v[3];

    func_021BA348(a);
    func_0218EC54(h);
    func_021B79D4(a, v);
    func_0218EC90(h, v);
}
