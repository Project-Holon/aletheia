/*
 * function: func_021BB528
 * address:  0x021BB528
 * packet:   pkt_ov021_021BB528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A7C     0x021D9A7C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_021ABEA0(u32, int);
extern void func_0216E1A4(u32, u32 *);
extern u32 func_021ABE14(u32);
extern void func_021BB778(u32);
extern void func_021ABFA8(u32, void *, int, int, void *, int);
extern int d_021D9A7C;

void func_021BB528(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, &s[4]);
    s[6] = func_021ABE14(a);
    if (d == 1)
        func_021BB778(c);
    func_021ABFA8(a, &d_021D9A7C, 0, 0, s, 0);
}
