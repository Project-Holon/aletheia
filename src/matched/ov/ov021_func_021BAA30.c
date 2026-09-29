/*
 * function: func_021BAA30
 * address:  0x021BAA30
 * packet:   pkt_ov021_021BAA30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_021B8050  0x021B8050  thumb  ov021
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

u32 func_021B8220(u8 *p);
u8 *func_021B830C(void);
u32 func_021B821C(u8 *p);
u32 func_0218E124(u32 a, u32 b);
u32 func_0218EC60(u32 a);
void func_021B8050(u32 a, s16 *v);
int func_0207CFB8(int a, int b);
void func_0218ED34(u32 o, u16 v);
void func_0218ED58(u32 o, u32 v);
void func_0218ED48(u32 o, u16 v);

void func_021BAA30(u8 *p)
{
    s16 v[4];
    u8 *q;
    u32 a;
    u32 o;
    int h;

    a = func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124(o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B8050(a, v);
    h = func_0207CFB8(-v[0], -v[2]);
    func_0218ED34(o, *(u32 *)(q + 8));
    func_0218ED58(o, *(u32 *)(q + 12));
    func_0218ED48(o, h + *(u32 *)(q + 4));
}
