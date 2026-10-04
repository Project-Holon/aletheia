/*
 * function: func_021BAC74
 * address:  0x021BAC74
 * packet:   pkt_ov021_021BAC74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021BAC04  0x021BAC04  thumb  ov021
 */

typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;

typedef unsigned char  u8;
extern u32 func_021B821C(u8 *p);
extern void func_021BAC04(u32 p);
extern void func_0218EC54(u8 *p);
extern void func_021B79D4(u32 p, V *v);
extern void func_0218EC90(u32 h, V *v);
extern void func_0218F05C(unsigned char *a);

void func_021BAC74(u32 p)
{
    V v;
    u32 h = func_021B821C((u8 *)p);

    func_021BAC04(p);
    func_0218EC54((u8 *)h);
    func_021B79D4(p, &v);
    func_0218EC90(h, &v);
    func_0218F05C((unsigned char *)h);
}
