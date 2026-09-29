/*
 * function: func_0218FEC0
 * address:  0x0218FEC0
 * packet:   pkt_ov021_0218FEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021901E4  0x021901E4  thumb  ov021
 *   func_021901E8  0x021901E8  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_021901E4(u8 *p);
extern u8 *func_021901E8(u8 *p);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u16 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218EC90(u8 *p, u8 *v);
extern void func_0218ECD4(u8 *p, u8 *v);

void func_0218FEC0(u8 *o)
{
    u8 *a = func_021901E4(o);
    u8 *b = func_021901E8(o) + 4;
    func_0218ED34(a, *(u16 *)b);
    func_0218ED48(a, *(u16 *)(b + 2));
    func_0218ED58(a, *(u32 *)(b + 4));
    func_0218EC90(a, b + 8);
    func_0218ECD4(a, b + 0x14);
}
