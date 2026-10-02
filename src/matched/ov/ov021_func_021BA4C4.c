/*
 * function: func_021BA4C4
 * address:  0x021BA4C4
 * packet:   pkt_ov021_021BA4C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021BA348  0x021BA348  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u32 func_021B821C(u8 *p);
void func_021BA348(u8 *p);
u32 func_0218EC54(u32 a);
void func_021B8314(u32 a, V *v);
void func_0218EC90(u32 a, V *v);

void func_021BA4C4(u8 *p)
{
    V v;
    u32 q;
    u32 o;

    q = func_021B8220(p);
    o = func_021B821C(p);
    func_021BA348(p);
    func_0218EC54(o);
    func_021B8314(q, &v);
    func_0218EC90(o, &v);
}
