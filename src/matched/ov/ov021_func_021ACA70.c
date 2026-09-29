/*
 * function: func_021ACA70
 * address:  0x021ACA70
 * packet:   pkt_ov021_021ACA70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021ABE18(u32 a);
extern u32 func_021ABE24(u32 a);
extern void func_021C6AE0(u32 *a);
extern u32 func_021C6AF0(u32 *a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern u32 func_021C6574(u32 a, u32 *b, u32 c);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);

void func_021ACA70(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r4 = func_021ABE18(a[0]);
    u32 r6 = func_021ABE24(a[0]);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r6, 0x31);
    h[2] = func_021C6574(r4, buf, 0);
    h[4] = func_021C6590(r4, h[2], 0, 0);
    func_021C67D8(r4, h[4], 1);
    func_021C6AE0(buf);
    func_021C6AF0(buf, r6, 0x36);
    func_021C6AF8(buf, r6);
    func_021C6AFC(buf, 0x6b);
    func_021C6AFC(buf, 0x85);
    h[3] = func_021C6574(r4, buf, 0);
    h[5] = func_021C6590(r4, h[3], 0, 0);
    func_021C67D8(r4, h[5], 1);
}
