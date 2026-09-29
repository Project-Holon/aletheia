/*
 * function: func_02190058
 * address:  0x02190058
 * packet:   pkt_ov021_02190058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218F19C  0x0218F19C  thumb  ov021
 *   func_0218F18C  0x0218F18C  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218ED5C  0x0218ED5C  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[3]; } B12;

extern void func_0218F19C(u8 *o, B12 *v);
extern void func_0218F18C(u8 *o, B12 *v);
extern void func_0207CA00(B12 *a, B12 *b, B12 *c);
extern u32 func_0218ED5C(B12 *v, u16 *a, u16 *b, u32 *c);
extern void func_0218ED58(u8 *o, u32 v);
extern void func_0218ED34(u8 *o, u16 v);
extern void func_0218ED48(u8 *o, u16 v);

void func_02190058(u8 *o)
{
    B12 v2, v1, v;
    u32 c;
    u16 b, a;
    func_0218F19C(o, &v1);
    func_0218F18C(o, &v2);
    func_0207CA00(&v1, &v2, &v);
    func_0218ED5C(&v, &b, &a, &c);
    func_0218ED58(o, c);
    func_0218ED34(o, b);
    func_0218ED48(o, a);
}
